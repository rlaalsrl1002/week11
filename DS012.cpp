 #include <iostream>
#include <cstring> // for strcmp and strcasecmp

using namespace std;

// 상품 정보를 담는 구조체 정의
struct Product {
    char name[100];
    int price;
    char manufacturer[100];
};

// 함수 선언
bool areProductsEqual(Product* p1, Product* p2);
void toLowerCase(char* str);

int main() {
    // 두 개의 상품 정보 입력받기
    Product product1, product2;

    cout << "첫 번째 상품의 이름: ";
    cin.getline(product1.name, 100);
    cout << "첫 번째 상품의 가격: ";
    cin >> product1.price;
    cin.ignore(); // 버퍼 비우기
    cout << "첫 번째 상품의 제조사: ";
    cin.getline(product1.manufacturer, 100);

    cout << "두 번째 상품의 이름: ";
    cin.getline(product2.name, 100);
    cout << "두 번째 상품의 가격: ";
    cin >> product2.price;
    cin.ignore(); // 버퍼 비우기
    cout << "두 번째 상품의 제조사: ";
    cin.getline(product2.manufacturer, 100);

    // 두 상품이 같은지 비교
    if (areProductsEqual(&product1, &product2)) {
        cout << "두 상품은 동일합니다: " << product1.name << endl;
    } else {
        cout << "두 상품은 다릅니다." << endl;
    }

    return 0;
}

// 두 상품의 이름과 가격이 같은지 비교하는 함수
bool areProductsEqual(Product* p1, Product* p2) {
    char name1[100], name2[100];
    
    // 이름을 소문자로 변환하여 비교
    strcpy(name1, p1->name);
    strcpy(name2, p2->name);
    toLowerCase(name1);
    toLowerCase(name2);

    if (strcmp(name1, name2) == 0 && p1->price == p2->price) {
        return true;
    } else {
        return false;
    }
}

// 문자열을 소문자로 변환하는 함수
void toLowerCase(char* str) {
    for (int i = 0; str[i] != '\0'; ++i) {
        str[i] = tolower(str[i]);
    }
}
