#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<double> x_coords = { 15.5, 2.0, 15.5, 8.0, 2.0, 10.0, 15.5 };

    sort(x_coords.begin(), x_coords.end());

    x_coords.erase(unique(x_coords.begin(), x_coords.end()), x_coords.end());

    cout << "Unique sorted coords: ";
    for (double x : x_coords) cout << x << " ";
    cout << endl;
    return 0;
}
