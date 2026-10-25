#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    vector<double> y_coords = { 0, 10, 25, 15, 40 };
    vector<double> diffs(y_coords.size());

    adjacent_difference(y_coords.begin(), y_coords.end(), diffs.begin());

    for (size_t i = 1; i < diffs.size(); i++) {
        diffs[i] = abs(diffs[i]);
    }

    double total_path = accumulate(diffs.begin() + 1, diffs.end(), 0.0);

    cout << "Total path: " << fixed << setprecision(1) << total_path << " m" << endl;
    return 0;
}
