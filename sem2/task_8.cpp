#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

const double g = 9.81;
const double air_density = 1.225;

struct Aircraft {
	string name;
	double m; // m = mass
	double s; // s = wing area [seems to be forgotten in task]
	double T; // T = thrust
	double CD; // CD = Drag coefficient
	double CL; // CL = lift coefficient

};

struct Result {
	Aircraft plane;
	double ay;
	double time;
};

double Lift(double rho, double v, double s, double CL) {
	return 0.5 * rho * v * v * s * CL;
}

double ay(double L, double m, double g) {
	return (L - m * g) / m;
}

double t(double ay, double h) {
	return sqrt(2 * h / ay);
}


int main() {

	double v, h;
	cout << "Enter the velocity: ";
	cin >> v;
	cout << "Enter the height: ";
	cin >> h;

	if (v < 0 || h < 0) {
		cout << "Error: values must be greater than zero";
		return 1;
	}

	Aircraft planes[3] = {
		{"Plane 1", 5000,  30,  10000, 0.5, 0.1},
		{"Plane 2", 10000, 120, 25000, 0.9, 0.4},
		{"Plane 3", 2500,  80,  1500,  0.3, 0.2}
	};

	Result list[3];

	for (int i = 0; i < 3; i++) {
		list[i].plane = planes[i];

		list[i].ay = (Lift(air_density, v, planes[i].s, planes[i].CL) - planes[i].m * g) / planes[i].m;
		if (list[i].ay > 0) {
			list[i].time = t(list[i].ay, h);
		}
		else {
			list[i].time = -1;  // Cannot climb
		}
	}

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2 - i; j++) {

			double t1 = list[j].time;
			if (t1 < 0) {
				t1 = 1e9;
			}

			double t2 = list[j + 1].time;
			if (t2 < 0) {
				t2 = 1e9;
			}

			if (t1 > t2) {
				Result temp = list[j];
				list[j] = list[j + 1];
				list[j + 1] = temp;
			}
		}
	}

	cout << setw(8) << "Plane" << " | " << setw(10) << "ay" << " | " << setw(10) << "Time" << endl;
	for (int i = 0; i < 3; i++) {
		cout << setw(8) << list[i].plane.name << " | " << setw(10) << list[i].ay << " | " << setw(10) << list[i].time << endl;
	}

	return 0;
}
