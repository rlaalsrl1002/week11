#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int findRoom(int persons[5]); 
void printReport(string mn[10], int mr[10], int mc, string wn[10], int wr[10], int wc);

int main(){
    string mnames[10]; // names of all male students (max. 10)
    string wnames[10]; // names of all female students (max. 10)
    int mroom[10];     // room numbers assigned all male students
    int wroom[10];     // room numbers assigned all female students
    int person[2][5] = {0};   // number of persons assigned to all rooms (two floors & each five rooms) 
    int mcount = 0, wcount = 0; // number of all persons (male, female)
    int menu;

    srand(time(0));
    cout << "===========================================" << endl;
    cout << "생활관 호실 배정 프로그램" << endl;
    cout << "===========================================" << endl;
    while (1) {
        cout << "메뉴 : 1.남학생 등록 2.여학생 등록 0.종료 > ";
        cin >> menu;
        if (menu == 0) break;
        else if (menu == 1) {
            if (mcount >= 10) {
                cout << "정원 초과입니다. 등록불가!" << endl;
                continue;
            }
            cout << "학생 이름은? > ";
            cin >> mnames[mcount];
            int roomno = findRoom(person[0]);
            if (roomno == -1) {
                cout << "모든 방이 꽉 찼습니다. 추가 배정 불가!" << endl;
                continue;
            }
            mroom[mcount] = 100 + roomno;
            person[0][roomno - 1]++; // 방에 남학생 수 증가
            cout << mnames[mcount] << " 학생 " << mroom[mcount] << "호실 배정되었습니다." << endl;
            mcount++;
        } else if (menu == 2) {
            if (wcount >= 10) {
                cout << "정원 초과입니다. 등록불가!" << endl;
                continue;
            }
            cout << "학생 이름은? > ";
            cin >> wnames[wcount];
            int roomno = findRoom(person[1]);
            if (roomno == -1) {
                cout << "모든 방이 꽉 찼습니다. 추가 배정 불가!" << endl;
                continue;
            }
            wroom[wcount] = 200 + roomno;
            person[1][roomno - 1]++; // 방에 여학생 수 증가
            cout << wnames[wcount] << " 학생 " << wroom[wcount] << "호실 배정되었습니다." << endl;
            wcount++;
        }
    }

    cout << "===========================================" << endl;
    cout << "생활관 호실 배정 결과는 다음과 같습니다." << endl;
    cout << "===========================================" << endl;
    printReport(mnames, mroom, mcount, wnames, wroom, wcount);

    return 0;
}

int findRoom(int persons[5]) {
    int MAX_PERSONS = 2;
    int roomNumber;

    while (true) {
        roomNumber = rand() % 5; // 0에서 4까지의 랜덤 숫자 생성
        if (persons[roomNumber] < MAX_PERSONS) {
            return roomNumber + 1; // 방 번호는 1부터 시작
        }
        
        // 모든 방이 꽉 찬 경우 처리
        bool allFull = true;
        for (int i = 0; i < 5; ++i) {
            if (persons[i] < MAX_PERSONS) {
                allFull = false;
                break;
            }
        }
        if (allFull) {
            return -1; // 방 번호가 유효하지 않음을 나타냄
        }
    }
}

void printReport(string mn[10], int mr[10], int mc, string wn[10], int wr[10], int wc) {
    cout << "남학생 배정 결과:" << endl;
    for (int i = 0; i < mc; ++i) {
        cout << mn[i] << " 학생, " << mr[i] << " 호실" << endl;
    }

    cout << endl << "여학생 배정 결과:" << endl;
    for (int i = 0; i < wc; ++i) {
        cout << wn[i] << " 학생, " << wr[i] << " 호실" << endl;
    }
}
