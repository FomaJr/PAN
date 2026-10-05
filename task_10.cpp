#include <iostream>
#include <cmath>
using namespace std;

// ay = (L-mg)/m ignores thrust, so minimizing over T is meaningless. I'll try to use excess thrust — ay = (T-D)/m - g — so T actually affects climb time.

const double g = 9.81;
const double rho = 1.225;
const double V = 80.0;

int main() {
    double m, S, CD, h;
    double Tmin, Tmax, dT;

    cout << "Enter the mass: ";
    cin >> m;
    cout << "Enter the wing area: ";
    cin >> S;
    cout << "Enter the drag coefficient: ";
    cin >> CD;
    cout << "Enter the height: ";
    cin >> h;
    cout << "Enter Tmin: ";
    cin >> Tmin;
    cout << "Enter Tmax: ";
    cin >> Tmax;
    cout << "Enter dT: ";
    cin >> dT;

    if (m <= 0 || S <= 0 || CD <= 0 || h <= 0 || dT <= 0 || Tmin >= Tmax) {
        cout << "Wrong input" << endl;
        return 1;
    }

    double D = 0.5 * rho * V * V * S * CD;

    double bestT = -1;
    double bestTime = -1;

    for (double T = Tmin; T <= Tmax; T += dT) {
        double ay = (T - D) / m - g;

        if (ay <= 0) continue;

        double t = sqrt(2.0 * h / ay);

        if (bestTime < 0 || t < bestTime) {
            bestTime = t;
            bestT = T;
        }
    }

    if (bestT < 0) {
        cout << "No thrust value allows climbing" << endl;
    }
    else {
        cout << "Best thrust: " << bestT << " N" << endl;
        cout << "Time: " << bestTime << " s" << endl;
    }

    return 0;
}
