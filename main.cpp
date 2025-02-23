#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    string t;
    cout << "Input : ";
    cin >> t;
    if(t == "가나")
    {
        cout << "True";
    }
    else
    {
        cout << "False";
    }

    fstream outfile("test.txt", ios::out);
    if(!outfile)
    {
        cout << "Can't open text.txt\n";
        return -1;
    }

    outfile << t << '\n';
    cout << "Complete!\n";
    outfile.close();

    return 0;
}