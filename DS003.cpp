#include <iostream>

using namespace std;

int main() {
    int month, day; 
    int day_count; 

    int days_in_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    cin >> month >> day;

    day_count = 0;
    for(int i = 1; i < month; ++i) {
        day_count += days_in_month[i];
    }
    day_count += day;

    cout << "이 날짜는 1년 중 " << day_count << " 번째 날에 해당됩니다." << endl;

    return 0;
}
