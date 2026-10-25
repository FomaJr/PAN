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

	if (heights.empty()) {
		cout << "No data" << endl;
		return 1;
	}
	
	//size_t idx_max = 0;
	//for (size_t i = 1; i < heights.size(); i++) {
	//	if (heights[i] > heights[idx_max]) {
	//		idx_max = i;
	//	}
	//}

	//cout << "Max height: " <<  heights[idx_max] << " m" << endl;
	//cout << "At time: " << times[idx_max] << " s" << endl;

	auto it = max_element(heights.begin(), heights.end());
	size_t idx = distance(heights.begin(), it);

	cout << "Max height: " << heights[idx] << " m" << endl;
	cout << "At time: " << times[idx] << " s" << endl;

	return 0;
}
