#include <iostream>
#include <random>
using namespace std;

class Gambling
{
private :
    int *nums;
    int N;
    random_device rd;
    mt19937 gen;
    uniform_int_distribution<int> dist;
    bool flag;
public :
    Gambling();
    Gambling(int n);
    bool choose(string name);
};

Gambling::Gambling() :
gen(rd()), dist(0,2)
{
    N = 3;
    nums = new int[N];
    flag = true;
}

Gambling::Gambling(int n) :
gen(rd()), dist(0,n)
{
    N = n;
    nums = new int[N];
    flag = true;
}

bool Gambling::choose(string name)
{
    flag = true;
    cout << "\t\t";
    while(flag)
    {
        for(int i = 0; i < N; i++)
        {
            nums[i] = dist(gen);
            if(i == 2)
            {
                if(nums[0] == nums[1] && nums[1] == nums[2])
                {
                    flag = false;
                }
            }
            cout << nums[i] << '\t';
        }
        if(flag)
        {
            cout << name << "님 승리!!\n";
        }
        else
        {
            cout << "아쉽군요!\n";
        }
    }
    

    return flag;
}

int main()
{
    string *name = new string[2];
    cout << "*****\t 겜블링게임을 시작합니다. \t*****\n";
    cout << "첫번째 사람의 이름을 입력하여 주십시오 : ";
    cin >> name[0];
    cout << "두번째 사람의 이름을 입력하여 주십시오 : ";
    cin >> name[1];
    
    Gambling Game;
    bool flag = true;

    if(flag)
    {
        for(int i=0; i<2 && flag; i++)
        {
            string t;
            cout << name[i];
            cout << ":<Enter>";
            cin >> t;
            if(!flag)
            {
                break;
            }
            flag = Game.choose(name[i]);
        }
    }


    return 0;
}