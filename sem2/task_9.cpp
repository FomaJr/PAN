#include <iostream>
#include <string>
#include <cmath>
using namespace std;

const double g = 9.81;
const double air_density = 1.225;

struct Aircraft {
    string name;
    double m;
    double s;
    double T;
    double CD;
    double CL;
};

double Lift(double rho, double v, double s, double CL) {
    return 0.5 * rho * v * v * s * CL;
}

double Drag(double rho, double v, double s, double CD) {
    return 0.5 * rho * v * v * s * CD;
}

double horizAccel(double T, double D, double m) {
    return (T - D) / m;
}

double vertAccel(double L, double m) {
    return (L - m * g) / m;
}

double resultantAccel(double a_h, double a_v) {
    return sqrt(a_h * a_h + a_v * a_v);
}

int main() {
    double v;
    cout << "Enter velocity: ";
    cin >> v;

    if (v <= 0) {
        cout << "Error: velocity must be > 0" << endl;
        return 1;
    }

    int n;
    cout << "Enter number of planes: ";
    cin >> n;

    const int MAX = 50;
    if (n <= 0 || n > MAX) {
        cout << "Error: n must be 1.." << MAX << endl;
        return 1;
    }

    Aircraft planes[MAX];

    for (int i = 0; i < n; i++) {
        planes[i].name = "Plane " + to_string(i + 1);

        cout << planes[i].name << " mass: ";
        cin >> planes[i].m;

        cout << planes[i].name << " wing area: ";
        cin >> planes[i].s;

        cout << planes[i].name << " thrust: ";
        cin >> planes[i].T;

        cout << planes[i].name << " CD: ";
        cin >> planes[i].CD;

        cout << planes[i].name << " CL: ";
        cin >> planes[i].CL;
    }

    double maxA = -1e9;
    int best = -1;

    cout << "\nResults\n";

    for (int i = 0; i < n; i++) {
        double L = Lift(air_density, v, planes[i].s, planes[i].CL);
        double D = Drag(air_density, v, planes[i].s, planes[i].CD);

        double a_h = horizAccel(planes[i].T, D, planes[i].m);
        double a_v = vertAccel(L, planes[i].m);
        double acc = resultantAccel(a_h, a_v);

        cout << planes[i].name << "  L=" << L << "  D=" << D << "  a=" << acc << endl;

        if (acc > maxA) {
            maxA = acc;
            best = i;
        }
    }

    cout << "\nGreatest acceleration: " << planes[best].name
        << " (a = " << maxA << ")" << endl;

    return 0;
}
