#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
	double h;
	double v0 = 50.0;
	double g = 9.8;
	double dt = 1.0;
	vector <double> times, heights;

	if (v0 <= 0) {
		cout << "Error: initial velocity v0 must be greater than 0." << endl;
		return 1; 
	}

	for (double t = 0.0; t <= 1000; t += dt) {
		h = v0 * t - 0.5 * g * t * t;
		times.push_back(t);
		heights.push_back(h);

		if (h < 0) {
			break;
		}
	}
	cout << setw(9) << "Trajectory" << endl;
	cout << left << setw(6) << "Time" << setw(10) << left <<  "| Height" << endl;
	for (int i = 0; i < times.size(); i++) {
		cout << setw(6) << times[i] << "| " << setw(10) << heights[i];
		if (heights[i] < 0) {
			cout << "Rocket fell" << endl;
			break;
		}
		cout << endl;

	}
	return 0;
}
