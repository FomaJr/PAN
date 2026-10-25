#include <iostream>
#include <cmath>
using namespace std;

int main() {
	double ay, h, t;
	cout << "Enter the vertical acceleration: ";
	cin >> ay;
	if (ay <= 0) {
		cout << "Error: vertical acceleration must be bigger than zero";
		return 1;
	}
	cout << "Enter the height: ";
	cin >> h;
	if (h <= 0) {
		cout << "Error: height must be bigger than zero";
		return 1;
	}

	t = sqrt(2 * h / ay);
	cout << "Flight time t = " << t;

	return 0;
}
