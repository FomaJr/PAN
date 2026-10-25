#include <iostream>
#include <iomanip>

using namespace std;

double Lift(double rho, double v, double s, double CL) {
    return 0.5 * rho * v * v * s * CL;
}

int main() {

    double velo[5] = { 200, 250, 350, 660, 530 };
    double air_dens[5] = { 1.225, 1.2, 1.5, 2, 2.5 };

    double s, CL;

    cout << "Enter the wing area: ";
    cin >> s;

    cout << "Enter the Lift coefficient: ";
    cin >> CL;

    if (CL <= 0 || s <= 0) {
        cout << "These values must be greater than zero";
        return 1;
    }

    cout << setw(6) << "Step" << " | " << setw(10) << "Velocity" << " | " << setw(12) << "Density" << " | " << setw(12) << "Lift" << endl;

    for (int i = 0; i < 5; i++) {
        cout << setw(6) << i + 1 << " | " << setw(10) << velo[i] << " | " << setw(12) << air_dens[i] << " | " << setw(12) << Lift(air_dens[i], velo[i], s, CL) << endl;
    }
    return 0;
}
