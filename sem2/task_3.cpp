#include <iostream>
using namespace std;

int main() {
	double m, L, D, T; //m = mass, L = Lift force, D = Drag, T = Thrust
	double g = 9.81;
	cout << "Enter the mass: ";
	cin >> m;
	cout << "Enter the lift force: ";
	cin >> L;
	cout << "Enter the drag: ";
	cin >> D;
	cout << "Enter the thrust: ";
	cin >> T;
	double a = (T - D) / m;
	double ay = (L - m * g) / m;
	cout << "Direction acceleration a = " << a << endl;
	cout << "Vertical acceleration ay = " << ay;

	return 0;
}
