#include <iostream>
#include <vector>
#include <iomanip>
#include <numeric>

using namespace std;

int main() {
    vector <double> times, velocities;
    double v = 0;
    double v0 = 50.0;
    double g = 9.81;
    double dt = 1.0;
    
    for (double t = 0.0; t < 1000; t += dt) {
        v = v0 - g * t;
        times.push_back(t);
        velocities.push_back(v);
        if (v <= -50) break;
    }
    
    if (velocities.empty()) {
        cout << "No data" << endl;
        return 1;
    }

    double sum = accumulate(velocities.begin(), velocities.end(), 0.0);
    double avg = sum / velocities.size();
    cout << "Average velocity during flight: " << fixed << setprecision(4) << avg << endl;

    cout << "Another variant" << endl;

    double integral = 0.0;
    for (size_t i = 1; i < times.size(); i++) {
        integral += (velocities[i] + velocities[i - 1]) / 2 * dt;
    }
    double avg_integral = integral / times.back();
    cout << "Average integral velocity: " << fixed << setprecision(4) << avg_integral << endl;

    return 0;
}
