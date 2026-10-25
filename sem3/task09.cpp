#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    vector<double> h = { 10.0, 15.0, 40.0, 25.0, 30.0, 65.0, 40.0, 45.0, 50.0 };
    size_t n = h.size();

    vector<double> smoothed(n);

    smoothed[0] = (h[0] + h[1]) / 2;
    smoothed[n - 1] = (h[n - 2] + h[n - 1]) / 2;

    for (size_t i = 1; i + 1 < n; i++) {
        smoothed[i] = (h[i - 1] + h[i] + h[i + 1]) / 3.0;
    }

    cout << left << setw(10) << "Original" << "| " << setw(10) << "Smoothed" << endl;
    cout << "---------------------" << endl;

    for (size_t i = 0; i < n; i++) {
        cout << left << setw(10) << fixed << setprecision(2) << h[i] << "| " << setw(10) << fixed << setprecision(2) << smoothed[i] << endl;
    }

    return 0;
}
