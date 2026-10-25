#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<double> temp = { 50.0, -150.0, 75.0, 210.0, 80.0, -120.0 };

    auto is_bad_temperature = [](double t) {
        return t < -100.0 || t > 200.0;
        };

    auto new_end = remove_if(temp.begin(), temp.end(), is_bad_temperature);

    temp.erase(new_end, temp.end());

    cout << "Cleaned temperatures: ";
    for (double t : temp) {
        cout << t << " ";
    }
    cout << endl;

    return 0;
}
