#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> sco_vec;
    int a;
    int b;
    int c;
    cout << "국어, 영어, 수학 성적을 입력하시오 : ";
    cin >> a >> b >> c;
    sco_vec.push_back(a);
    sco_vec.push_back(b);
    sco_vec.push_back(c);

    int sum;
    sum = sco_vec[0] + sco_vec[1] + sco_vec[2];
    cout << "총점 : " << sum << endl;

    double avg;
    avg = (sco_vec[0] + sco_vec[1] + sco_vec[2]) / 3.0;
    cout << "평균 : " << avg << endl;

    return 0;
}
