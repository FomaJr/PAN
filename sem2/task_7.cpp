#include <iostream>

using namespace std;

double Lift(double rho, double v, double s, double CL) {
    return 0.5 * rho * v * v * s * CL;
}

const double g = 9.81;
double vertical_acceleration(double L, double m) {
    return (L - m * g) / m;
}
const double air_density = 1.225;

int main() {

    double m, v, s, CL, ay;

    cout << "Enter the mass: ";
    cin >> m;

    cout << "Enter the velocity: ";
    cin >> v;

    cout << "Enter the wing area: ";
    cin >> s;

    cout << "Enter the Lift coefficient: ";
    cin >> CL;

    if (CL <= 0 || s <= 0 || v <= 0 || m <= 0) {
        cout << "These values must be greater than zero";
        return 1;
    }

    ay = vertical_acceleration(Lift(air_density, v, s, CL), m);
    
    if (ay > 0.5) {
        cout << "Climb mode";

    }
    else if (ay >= 0) {
        cout << "Horizontal flight";
    }
    else cout << "Decrease mode";

    return 0;
}
