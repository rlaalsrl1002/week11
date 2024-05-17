#include <iostream>
#include <cctype> // for isalpha and tolower
#include <cstring> // for strlen

using namespace std;

int main() {
    char sentence[51]; 
    int alphabetCount[26] = {0}; // A-Z 알파벳 개수 배열
    int spaceCount = 0; // 공백 개수

    // 문장 입력 받기
    cout << "영어 문장을 입력하세요 (최대 50자): ";
    cin.getline(sentence, 51);

    // 문자열 길이 확인
    int length = strlen(sentence);

    // 문자 분석
    for (int i = 0; i < length; i++) {
        if (isalpha(sentence[i])) {
            char lowerChar = tolower(sentence[i]);
            alphabetCount[lowerChar - 'a']++;
        } else if (isspace(sentence[i])) {
            spaceCount++;
        }
    }

    // 결과 출력
    cout << "공백의 개수: " << spaceCount << endl;
    cout << "알파벳 개수:" << endl;

    for (int i = 0; i < 26; ++i) {
        if (alphabetCount[i] > 0) {
            cout << static_cast<char>('a' + i) << ": " << alphabetCount[i] << endl;
        }
    }

    return 0;
}
