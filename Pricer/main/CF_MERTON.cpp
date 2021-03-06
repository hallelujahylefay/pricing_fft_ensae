#include "CF_MERTON.h"

using namespace std;

CfMerton::CfMerton(double r, double T, double alpha, int N, double eta, double s0, double v, double lambda, double mu, double delta) : CF(r, T, alpha, N, eta, s0), v(v), lambda(lambda), mu(mu), delta(delta) {
}

// Characteristic Function for BS Merton model
complex<double> CfMerton::phi(const complex<double> z) const {
    complex<double> i(0.0, 1.0);
    complex<double> mu_M = r - v * v - lambda * (exp(mu + 0.5 * delta * delta) - 1);
    complex<double> phi = exp(T * (-0.5 * pow(v * z, 2) + i * mu_M * z + lambda * exp(-pow(delta * z, 2) / (complex<double>(2, 0)) + i * mu * z - complex<double> (1.0, 0.0))));
    return phi * exp(i * z * s0);
}
