#include <iostream>
using namespace std;

int main() {
    int height, weight;
    double bmi;

    cout << "height & weight";
    cin >> height >> weight;

    double heightInMeters = height / 100.0;

    bmi = weight / (heightInMeters * heightInMeters);

    if(bmi > 25){
        cout << "yes\n";
    }else{
        cout << "No\n";
    }

    return 0;
}
