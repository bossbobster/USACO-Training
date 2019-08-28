#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("palsquare.in");
ofstream fout("palsquare.out");
char numbers[20] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
string toBaseX(int num, int base)
{
    int exp = 1;
    string endNum = "";
    while(exp * base <= num)
    {
        exp = exp * base;
    }
    while(exp >= 1)
    {
        for(int i = base - 1; i >= 0; i --)
        {
            if(exp * i <= num)
            {
                num -= exp * i;
                endNum += numbers[i];
                break;
            }
        }
        exp = exp / base;
    }
    return endNum;
}

bool isPal(string st)
{
    bool pal = true;
    for(int i = 0; i < st.length() / 2; i ++)
    {
        if(st[i] != st[st.length() - i - 1])
        {
            pal = false;
            break;
        }
    }
    return pal;
}
int main()
{
    int n;
    fin >> n;
    for(int i = 1; i <= 300; i ++)
    {
        string s = toBaseX(i * i, n);
        if(isPal(s))
        {
            fout << toBaseX(i, n) << " " << s << endl;
        }
    }
}
