#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
    double g = 9.81;
    double dt = 1.0;
    double t_max_sim = 20.0;

    vector<double> times1, heights1;
    vector<double> times2, heights2;

    for (double t = 0; t < t_max_sim; t += dt) {

        //Rocket 1
        double h1 = 30.0 * t - 0.5 * g * t * t;
        times1.push_back(t);
        heights1.push_back(h1);

        //Rocket 2
        double h2 = 50.0 * t - 0.5 * g * t * t;
        times2.push_back(t);
        heights2.push_back(h2);
    }

    size_t idx_max1 = distance(heights1.begin(), max_element(heights1.begin(), heights1.end()));
    double max_h1 = heights1[idx_max1];
    double t_max1 = times1[idx_max1];

    size_t idx_fall1 = distance(heights1.begin(), find_if(heights1.begin(), heights1.end(), [](double h) {return h < 0.0; }));
    double t_fall1 = times1[idx_fall1];

    size_t idx_max2 = distance(heights2.begin(), max_element(heights2.begin(), heights2.end()));
    double max_h2 = heights2[idx_max2];
    double t_max2 = times2[idx_max2];

    size_t idx_fall2 = distance(heights2.begin(), find_if(heights2.begin(), heights2.end(), [](double h) {return h < 0.0; }));
    double t_fall2 = times2[idx_fall2];

    cout << left << setw(20) << "Metric" << "| " << setw(10) << "Rocket 1" << "| " << "Rocket 2" << endl;
    cout << left << setw(20) << "Max Height (m)" << "| " << setw(10) << fixed << setprecision(2) << max_h1 << "| " << max_h2 << endl;
    cout << left << setw(20) << "Time of Max (s)" << "| " << setw(10) << t_max1 << "| " << t_max2 << endl;
    cout << left << setw(20) << "Time of Fall (s)" << "| " << setw(10) << t_fall1 << "| " << t_fall2 << endl;

    cout << endl << "Results" << endl;
    if (max_h1 > max_h2) {
        cout << "Rocket 1 flew higher." << endl;
    }
    else {
        cout << "Rocket 2 flew higher." << endl;
    }

    if (t_fall1 > t_fall2) {
        cout << "Rocket 1 was in the air longer." << endl;
    }
    else {
        cout << "Rocket 2 was in the air longer." << endl;
    }

    return 0;
}
