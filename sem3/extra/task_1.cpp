#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
    vector<double> heights = {0, 45, 80, 127, 123, 86, 10};
    vector<double> times = {0, 1, 2, 3, 4, 5, 6};

    auto it = max_element(heights.begin(), heights.end());
    size_t idx = distance(heights.begin(), it);

    cout << "Max height: " << heights[idx] << " m at t = " << times[idx] << " s" << endl;
    return 0;
}
