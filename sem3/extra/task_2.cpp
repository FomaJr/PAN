#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<double> sensor_data = {0.5, 0.0, 1.2, 0.0, 0.0, 9.8, 0.0, 3.1};
    
    int zero_count = count(sensor_data.begin(), sensor_data.end(), 0.0);
    
    cout << "Number of zero readings: " << zero_count << endl;
    return 0;
}
