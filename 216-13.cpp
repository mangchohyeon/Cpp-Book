#include <iostream>
#include <string>
using namespace std;

class Histogram
{
    string content;
    int *count;
    int start,end,res_count = 0;
public :
    Histogram(string temp);
    void put(string content_add);
    void putc(char c);
    void print();
    void check();
};

void Histogram::check()
{
    for(int i = start; i < end; i++)
    {
        int t;
        if(content[i] >= 65 || content[i] <= 90)    // 대문자라면 소문자 글자수 ++
        {
            t = content[i] - 65;
            res_count ++;
        }

        else if(content[i] >= 97 || content[i] <= 122)  // 소문자라면 그냥 ++
        {
            t = content[i] - 97;
            res_count++;
        }

        else
        {
            continue;                                   // 대문자도 소문자도 아니라면 건너 뛰기기
        }
        
        count[t]++;
    }

    start = end;
}

Histogram::Histogram(string temp)
{
    content = temp;
    count = new int[26];
    for(int i = 0; i < 26; i++)
    {
        count[i] = 0;
    }
    start = 0;
    end = content.length();
    check();
}

void Histogram::put(string content_add)
{
    content.append(content_add);
    int t = content_add.length();
    end = start + t;
    check();
}

void Histogram::putc(char c)
{
    string temp(1, c);
    content.append(temp);
    end = start+1;
    check();
}

void Histogram::print()
{
    cout << "입력하신 문자열\n";
    cout << content;
    cout << '\n';
    cout << "총 알파벳 수 : ";
    cout << res_count << "\n\n";

    for(int i = 97; i <= 122; i++)
    {
        int t = i - 97;
        cout << ((char)i) << " (" << count[t] << ")     : ";
        for(int j = 0; j < count[t]; j++)
        {
            cout << '*';
        }
        cout << '\n';
    }
}

int main()
{
    Histogram t("");

    cout << "Histogram을 보고 싶은 문자열을 입력하세요.\n";
    cout << "End를 입력하면 종료합니다.";

    while(true)
    {
        string temp;
        cout << "Histogram을 보고 싶은 문자열을 입력하세요 : ";
        getline(cin, temp);
        if(temp == "end" || temp == "End")
        {
            break;
        }
        t.put(temp);
    }

    t.print();

    

    return 0;
}