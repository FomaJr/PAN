#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    struct Point {
        double x;
        double y;
        double z;
    };

    double x = 0, y = 0, z = 0;
    double vx = 10.0, vy = 20.0, vz = 30.0;
    double dt = 1.0;
    double t_max = 20;

    vector <Point> traj;
    traj.reserve(1000);

    for (double t = 0; t < t_max; t += dt) {
        x += vx * dt;
        y += vy * dt;
        z += vz * dt;
        traj.push_back({ x, y, z });
    }

    double t = 0;

    cout << left << setw(5) << "Time" << "| " << setw(8) << "x" << "| " << setw(8) << "y" << "| " << setw(8) << "z" << endl;
    
    for (size_t i = 0; i < traj.size(); i++) {
        cout << left << setw(5) << fixed << setprecision(0) << t << "| "
            << setw(8) << fixed << setprecision(2) << traj[i].x << "| "
            << setw(8) << fixed << setprecision(2) << traj[i].y << "| "
            << setw(8) << fixed << setprecision(2) << traj[i].z << endl;
        t += dt;
    }

    return 0;
}
