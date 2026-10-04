#include <iostream>
#include <cmath>
using namespace std;

struct plane{
		string name;
		double m; // m = mass
		double s; // s = square
		double T; // T = thrust
		double CD; // CD = drag coefficient
		double CL; // CL = lift coefficient

};

double Lift(double rho, double v, double s, double CL) {
	return 0.5 * rho * v * v * s * CL;
}

double Drag(double rho, double v, double s, double CD) {
	return 0.5 * rho * v * v * s * CD;
}

double acceleration(double thrust, double drag, double mass) {
	return (thrust - drag) / mass;
}

double vertical_acceleration(double L, double m, double g) {
	return (L - m * g) / m;
}

double t(double ay, double h) {
	return sqrt(2 * h / ay);
}

const double g = 9.81;

int main() {
	
	double rho, v, h;
	cout << "Enter the air density: ";
	cin >> rho;
	cout << "Enter the velocity: ";
	cin >> v;
	cout << "Enter the height: ";
	cin >> h;
	
	if (rho < 0 || v < 0 || h < 0) {
		cout << "Error: values must be greater than zero";
		return 1;
	}

	plane planes[3] = {
		{"Plane 1", 5000, 50, 10000, 0.5, 0.1},
		{"Plane 2", 10000, 80, 25000, 0.9, 0.4},
		{"Plane 3", 2500, 20, 1500, 0.3, 0.2 }
	};

	int best = 4;
	double L, D, a, ay, time;
	double c = pow(10, 200);

	for (int i = 0; i < 3; i++) {
		L = Lift(rho, v, planes[i].s, planes[i].CL);
		D = Drag(rho, v, planes[i].s, planes[i].CD);
		a = acceleration(planes[i].T, D, planes[i].m);
		ay = vertical_acceleration(L, planes[i].m, g);
		if (ay < 0) {
			cout << "Due to vertical acceleration is below zero plane " << i+1 << " cannot lift" << endl;
			continue;
		}
		time = t(ay, h);
		if (time < c) {
			best = i;
			c = time;
		}

	}
	if (best != 4) {
		cout << "Best plane is Plane " << best + 1;
	}
	else {
		cout << "All planes cannot lift";
	}

	return 0;
}
