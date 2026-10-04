#include <iostream>
using namespace std;

int main() {
	int S, V, rho, CL, L;
	cout << "Enter the wing square: ";
	cin >> S;
	cout << "Enter the velocity: ";
	cin >> V;
	cout << "Enter the density of air: ";
	cin >> rho;
	cout << "Enter the lift coefficient: ";
	cin >> CL;

	cout << "Lift force L = " << 0.5 * rho * V * V * S * CL;
	return 0;
}
