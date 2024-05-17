#include <iostream>

using namespace std;

// 함수 선언
void computeSumAndMax(int* array, int count, int& total, int& largest);

int main() {
    int numCount; // 입력받을 숫자의 개수

    cout << "입력할 숫자의 개수: ";
    cin >> numCount;

    // 동적 배열 생성
    int* values = new int[numCount];

    // 숫자 입력 받기
    cout << numCount << "개의 숫자를 입력하세요: ";
    for (int i = 0; i < numCount; ++i) {
        cin >> values[i];
    }

    int totalSum = 0;
    int maxVal = values[0];

    // 총합과 최대값 계산
    computeSumAndMax(values, numCount, totalSum, maxVal);

    // 결과 출력
    cout << "총합: " << totalSum << endl;
    cout << "최대값: " << maxVal << endl;

    // 동적 배열 해제
    delete[] values;

    return 0;
}

// 총합과 최대값을 계산하는 함수
void computeSumAndMax(int* array, int count, int& total, int& largest) {
    for (int i = 0; i < count; ++i) {
        total += array[i];
        if (array[i] > largest) {
            largest = array[i];
        }
    }
}
