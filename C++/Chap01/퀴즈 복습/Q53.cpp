--C++ STL을 활용해 로또번호 구하기--
#include <iostream>
#include <cstdlib>
#include <random>
#include <numeric>
#include <algorithm>
#include <vector>
using namespace std;

class Lotto{
public:
    void generate(){
        random_device rd;
        mt19937 gen(rd());

        vector<int> pool(45);
        iota(pool.begin(), pool.end(), 1);

        shuffle(pool.begin(), pool.end(), gen);

        vector<int> lotto(pool.begin(), pool.begin() + 6);
        int bonus = pool[6];

        sort(lotto.begin(), lotto.end());

        cout << "로또 번호: ";
        for(int n : lotto){
            cout << n << ' ';
        }
        cout << "\n보너스 번호: " << bonus << endl;

    }
};

int main(int argc, char* avgr[])
{
    Lotto lotto;
    lotto.generate();
    return 0;
}
