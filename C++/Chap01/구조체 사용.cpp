#include <iostream>

struct studentinfo {
    char bloodtype;
    int stdNumber;
    float grade;
};
typedef struct studentinfo Studentinfo;

int main()
{
    using namespace std;

    Studentinfo si1 = { '0', 20031128, 3.5 };
    Studentinfo si2 = { 'A', 19961219, 2.3 };

    cout << "혈액형 : " << si1.bloodtype << endl;
    cout << "학번 : " << si1.stdNumber << endl;
    cout << "성적 : " << si1.grade << endl;

    cout << "혈액형 : " << si2.bloodtype << endl;
    cout << "학번 : " << si2.stdNumber << endl;
    cout << "성적 : " << si2.grade << endl;

   
    return 0;
}
-----------------------------배열 사용-----------------------------------------------
#include <iostream>

struct studentinfo {
    char bloodtype;
    int stdNumber;
    float grade;
};
typedef struct studentinfo Studentinfo;

int main()
{
    using namespace std;

    Studentinfo si[2] = {
        {'0', 20031128, 3.5}, {'A', 19961219, 2.3}
    };

    int cnt = sizeof(si) / sizeof(si[0]);
    for (int i = 0; i < cnt; i++) {
        cout << "혈액형 : " << si[i].bloodtype << endl;
        cout << "학번 : " << si[i].stdNumber << endl;
        cout << "성적 : " << si[i].grade << "\n\n" << endl;
    }
    
    return 0;
}



