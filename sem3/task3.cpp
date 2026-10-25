#include <iostream>
#include <vector>
#include <iomanip>

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
        if (v <= -100) break;
    }
    
    double t = v0 / g;
    cout << "Velocity = 0 at t = " << fixed << setprecision(3) << t << " s" << endl << endl;

    cout << left << setw(5) << "Time" << "| " << setw(8) << "Velocity" << endl;
    for (size_t i = 0; i < times.size(); i++) {
        cout << left << setw(5) << fixed << setprecision(0) << times[i] << "| " 
             << setw(8) << fixed << setprecision(2) << velocities[i];
        if (velocities[i] <= -100) {
            cout << " Velocity is too low" << endl;
            break;
        }
        cout << endl;
    }

    return 0;
}
