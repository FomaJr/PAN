#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	vector <double> times, heights;
	double g = 9.81;
	double v0 = 30.0;
	double dt = 1;
	double t_max = 10;
	double h = 0.0;

	for (double t = 0; t < t_max; t += dt) {
		h = v0 * t - g * t * t / 2;
		heights.push_back(h);
		times.push_back(t);
	}

	auto it = find_if(heights.begin(), heights.end(), [](double h) {return h < 0.0; });
	if (it == heights.end()) {
		cout << "Fall not in range" << endl;
	}
	else {
		size_t idx = distance(heights.begin(), it);
		double t_fall = times[idx];
		cout << "t_fall: " << t_fall << endl;
		cout << "heights[idx]: " << heights[idx] << endl;
	}

	return 0;
}
