#include <iostream>
#include <string>

using namespace std;

void ltrim(string &str);
void rtrim(string &str);
int getLastWordLength(const string &str);

int main() {
    string input;

    cout << "문장을 입력하세요: ";
    getline(cin, input);

    // 좌우 공백 및 탭 제거
    ltrim(input);
    rtrim(input);

    // 마지막 단어의 길이 계산
    int lastWordLength = getLastWordLength(input);

    cout << "마지막 단어의 길이: " << lastWordLength << endl;

    return 0;
}

// 좌측 공백 및 탭 제거 함수
void ltrim(string &str) {
    size_t start = str.find_first_not_of(" \t");
    if (start != string::npos) {
        str = str.substr(start);
    }
}

// 우측 공백 및 탭 제거 함수
void rtrim(string &str) {
    size_t end = str.find_last_not_of(" \t");
    if (end != string::npos) {
        str = str.substr(0, end + 1);
    }
}

// 마지막 단어의 길이를 계산하는 함수
int getLastWordLength(const string &str) {
    int length = 0;
    bool inWord = false;

    for (int i = str.length() - 1; i >= 0; --i) {
        if (str[i] != ' ' && str[i] != '\t') {
            inWord = true;
            length++;
        } else {
            if (inWord) {
                break;
            }
        }
    }

    return length;
}
