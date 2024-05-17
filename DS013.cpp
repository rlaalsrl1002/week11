#include <iostream>
using namespace std;

// Menu 구조체 정의
struct Menu {
    char name[100];
    int price;
};

// Cafe 구조체 정의
struct Cafe {
    string name;
    int menuCount;
    Menu* menuList;
};

// 함수 선언
void addCafe(Cafe &r1);
void addMenu(Menu &m1);
void displayMenus(const Cafe &r1);

int main() {
    Cafe myCafe;

    // 카페 정보 입력받기
    addCafe(myCafe);

    // 메뉴 정보 입력받기
    myCafe.menuList = new Menu[myCafe.menuCount];
    for (int i = 0; i < myCafe.menuCount; ++i) {
        addMenu(myCafe.menuList[i]);
    }

    // 메뉴 정보 출력
    displayMenus(myCafe);

    // 동적 배열 해제
    delete[] myCafe.menuList;

    return 0;
}

// 카페 정보를 입력받는 함수
void addCafe(Cafe &r1) {
    cout << "카페 이름을 입력하세요: ";
    cin.ignore();
    getline(cin, r1.name);
    cout << "메뉴 개수를 입력하세요: ";
    cin >> r1.menuCount;
}

// 메뉴 정보를 입력받는 함수
void addMenu(Menu &m1) {
    cout << "메뉴 이름을 입력하세요 (공백 없이): ";
    cin >> m1.name;
    cout << "메뉴 가격을 입력하세요: ";
    cin >> m1.price;
}

// 메뉴 정보를 출력하는 함수
void displayMenus(const Cafe &r1) {
    cout << "카페 이름: " << r1.name << endl;
    cout << "메뉴 개수: " << r1.menuCount << endl;
    for (int i = 0; i < r1.menuCount; ++i) {
        cout << "메뉴 " << i + 1 << ": " << r1.menuList[i].name << ", 가격: " << r1.menuList[i].price << "원" << endl;
    }
}
