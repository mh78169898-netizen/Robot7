--단일책임원칙(SRP)에 맞게 다음 코드를 리팩토링 해보세요.--
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// SRP(단일 책임 원칙)를 위반한 UserInfo 예제
// - 사용자 정보
// - 서버 정보 출력
// - 관리자 정보 저장
//   책임을 한 클래스에 모두 몰아넣음
class UserInfo {
private:
    // 사용자 정보
    string userName;
    string userEmail;

public:
    UserInfo(const string& userName,const string& userEmail)
    :userName(userName),userEmail(userEmail){}
    const string& getName() const { return userName; };
    const string& getEmail() const { return userEmail; };

    // ① 사용자 정보 출력 책임
    void printUserInfo() const {
        cout << "[User] 이름: " << userName
             << ", 이메일: " << userEmail << endl;
    }
};
class ServerInfo{
private:
    // 서버 정보
    string serverIp;
    int serverPort;
public:
    ServerInfo( const string& serverIp,int serverPort)
    :serverIp(serverIp), serverPort(serverPort){}
    const string& getIp() const { return serverIp; };
    int getPort() const { return serverPort; };

    // ② 서버 정보 출력 책임
    void printServerInfo() const {
        cout << "[Server] IP: " << serverIp
             << ", Port: " << serverPort << endl;
    }
};

int main() {
    UserInfo user("홍길동", "hong@example.com");
    ServerInfo ServerInfo("192.168.0.10", 8080);
        

    user.printUserInfo();
    ServerInfo.printServerInfo();           

    return 0;
}
