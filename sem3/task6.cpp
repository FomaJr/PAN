#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	vector <double> heights;
	double g = 9.81;
	double v0 = 30.0;
	double dt = 1;
	double t_max = 10;
	double h = 0.0;

	for (double t = 0; t < t_max; t += dt) {
		h = v0 * t - g * t * t / 2;
		heights.push_back(h);

	}

	cout << "All heights" << endl;
	for (size_t i = 0; i < heights.size(); i++) {
		cout << heights[i] << " ";
	}

	cout << endl << endl;

	auto new_end = remove_if(heights.begin(), heights.end(), [](double h) {return h < 10.0;});
	heights.erase(new_end, heights.end());

	cout << "Heights above 10 m" << endl;
	for (size_t i = 0; i < heights.size(); i++) {
		cout << heights[i] << " ";
	}
	cout << endl;
	return 0;
}
