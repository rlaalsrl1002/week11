#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double x1, y1; // 첫 번째 좌표 값
    double x2, y2; // 두 번째 좌표 값
    double distance;

    cin >> x1 >> y1;
    cin >> x2 >> y2;

    distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

    cout << "거리는? " << distance << endl;

    return 0;
}
