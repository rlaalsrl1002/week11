#include <iostream>
using namespace std;

// 점수 데이터 구조체 정의
struct st_scores {
    int kor;    // 국어 점수
    int eng;    // 영어 점수
    int math;   // 수학 점수
    int total;  // 총점
    double average; // 평균 점수
};

int main() {
    st_scores scores;
    cin >> scores.kor;
    cin >> scores.eng;
    cin >> scores.math;

    scores.total = scores.kor + scores.eng + scores.math;
    scores.average = scores.total /3.0;

    cout << "sum" << scores.total << endl;
    cout << "everage" << scores.average << endl;
    return 0;
}