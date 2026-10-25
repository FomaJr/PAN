#include <iostream>
#include <vector>
#include <iomanip>
#include <string>

using namespace std;

struct Point {
    double x, y, z;
};

class Rocket {
private:
    double x, y, z;
    double vx, vy, vz;

public:
    // Constructor
    Rocket(double start_vx, double start_vy, double start_vz) {
        x = 0; y = 0; z = 0;
        vx = start_vx;
        vy = start_vy;
        vz = start_vz;
    }

    void updatePosition(double dt) {
        x += vx * dt;
        y += vy * dt;
        z += vz * dt;
    }

    Point getPosition() const {
        return { x, y, z };
    }
};

int main() {
    double dt = 1.0;
    double T = 10.0;

    vector<Rocket> squad;
    squad.reserve(5);

    squad.emplace_back(100, 10, 0);
    squad.emplace_back(90, 15, -5);
    squad.emplace_back(80, 20, 10);
    squad.emplace_back(110, 5, 5);
    squad.emplace_back(95, 25, -10);

    vector<vector<Point>> trajectories(5);

    for (double t = 0; t <= T; t += dt) {
        for (size_t i = 0; i < squad.size(); i++) {
            squad[i].updatePosition(dt);
            trajectories[i].push_back(squad[i].getPosition());
        }
    }

    cout << "Final positions after " << T << " seconds:" << endl;
    cout << left << setw(10) << "Rocket" << "| " << setw(10) << "X" << "| " << setw(10) << "Y" << "| " << setw(10) << "Z" << endl;
    cout << "--------------------------------------------------" << endl;

    for (size_t i = 0; i < squad.size(); i++) {
        Point p = squad[i].getPosition();
        cout << left << setw(10) << ("Rocket " + to_string(i + 1))
            << "| " << setw(10) << p.x
            << "| " << setw(10) << p.y
            << "| " << setw(10) << p.z << endl;
    }

    return 0;
}
