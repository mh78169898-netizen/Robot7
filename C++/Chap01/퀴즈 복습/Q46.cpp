#include <iostream>
#include <cstdlib>
#include <memory>
#include <vector>
#include <string>
using namespace std;

class Account{
private:
    int id; //계좌번호
    string name; //예금주 이름
    int balance = 0; //잔액, C++11 이후로는 이렇게 초기화 하는것을 권장
public:
    explicit Account(int id, const string& name, int initialBalance = 0)
       : id(id), name(name), balance(initialBalance) {};
    int getId() const;
    string getName() const;
    int getBalance() const;
    bool deposit(int amount){
        if(amount <= 0){
            cout << "입금액은 0보다 커야 합니다." << endl;
            return false;
        }
        balance += amount;
        cout << amount << "원이 입금되었습니다." << endl;
        return true;
    };
    bool withdraw(int amount){
        if(amount <= 0){
            cout << "출금액은 0보다 커야 합니다." << endl;
            return false;
        }
        if(amount > balance){
            cout << "잔액이 부족:출금 실패." << endl;
            return false;
        }
        balance -= amount;
        cout << amount << "원이 출금되었습니다." << endl;
        return true;
    };
    void printInfo() const{
        cout << "계좌번호: " << id << ", 예금주: " << name << ", 잔액: " << balance
        << "원" << endl;
    };
};


int main()
{
     // 1. 계좌 생성
    Account acc1(1001, "홍길동", 50000);
    Account acc2(1002, "이순신", 30000);

    // 2. 입금/출금 테스트
    acc1.deposit(20000);    // 정상 입금
    acc2.withdraw(5000);    // 정상 출금
    acc2.withdraw(50000);   // 실패 테스트 (잔액 부족)

    // 3. 계좌 정보 출력
    acc1.printInfo();
    acc2.printInfo();

    // 4. vector로 여러 계좌 관리
    vector<Account> v;
    v.push_back(acc1);
    v.push_back(acc2);

    cout << "\n=== 전체 계좌 목록 ===\n";
    for (const auto& acc : v) {
        acc.printInfo();
    }

    return 0;
}
