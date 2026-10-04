#include <iostream>
using namespace std;

double res(double dens, double vel, double sq, double rc) {
	return 0.5 * dens * vel * vel * sq * rc;
}

int main() {
	double S, V, rho, CD, L;

	cout << "Enter the wing square: ";
	cin >> S;
	cout << "Enter the velocity: ";
	cin >> V;
	cout << "Enter the density of air: ";
	cin >> rho;
	cout << "Enter the resistance coefficient: ";
	cin >> CD;

	cout << "Aerodynamic resistance L = " << res(rho, V, S, CD);
	return 0;
}
