#include <iostream>
#include <cstdlib>
using namespace std;

// Circle 클래스 정의 시작
class Circle{
private:
    // 원의 반지름을 저장하는 멤버 변수 (private로 선언하는 것이 일반적)
    int rid; 
public:
    // 1. 기본 생성자 (매개변수 없음) 선언
    Circle();
    // 2. 매개변수 있는 생성자 선언 (반지름 r을 인수로 받음)
    Circle(int r);
    // 3. 소멸자 선언 (객체 소멸 시 자동 호출됨)
    ~Circle();
    
    // 반지름 설정 함수 (Setter)
    void setRadius(int r){rid = r;}
    
    // 원의 면적 계산 함수
    double getArea(){
        // 원주율 3.14를 사용하여 면적 계산 (A = pi * r * r)
        return 3.14*rid*rid; 
    }
}; 
// Circle 클래스 정의 끝

// --- 클래스 멤버 함수 구현 ---

// 기본 생성자 구현
Circle::Circle(){
    // 반지름을 1로 초기화
    rid = 1;
    // 생성자 실행 메시지 출력
    cout << "생성자 실행 rid = " << rid << endl;
}

// 매개변수 있는 생성자 구현
Circle::Circle(int r){
    // 인수로 받은 r 값으로 반지름 초기화
    rid = r;
    // 생성자 실행 메시지 출력
    cout << "생성자 실행 rid = " << rid << endl;
}

// 소멸자 구현
Circle::~Circle(){
    // 객체 소멸 시 소멸자 실행 메시지 출력
      cout << "소멸자 실행 rid = " << rid << endl;
}

// --- main 함수 시작 (프로그램 진입점) ---

int main()
{
    int ridus; // 사용자로부터 입력받을 반지름 변수
    
    // 무한 루프 시작 (사용자가 음수를 입력할 때까지 반복)
    while (true){
        // 사용자에게 입력 요청
        cout << "정수 반지름 입력(음수이면 종료)>>";
        cin >> ridus;
        
        // 종료 조건 확인
        if(ridus < 0){
            break;; // 음수이면 루프를 빠져나감
        }
        
        // **동적 할당**: new 연산자를 사용하여 Circle 객체를 힙(Heap)에 생성
        Circle* p = new Circle(ridus); 
        
        // 포인터 p를 통해 getArea() 함수 호출하여 면적 출력
        cout << "원의 면적은 " << p->getArea() << endl;
        
        // **메모리 해제**: delete 연산자를 사용하여 동적으로 할당된 객체를 소멸
        // 이 때 소멸자(~Circle())가 호출됨. (메모리 누수 방지)
        delete p; 
    }
    
    return 0; // 프로그램 정상 종료
}
