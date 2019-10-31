#include <iostream>
using namespace std;

int hsh(char c)
{
    if(c == '(')
        return 1;
    return -1;
}

short para[100010];
int main()
{
    string pa;
    int total = 0, num = 0, tmp = 0;
    getline(cin, pa);
    for(int i = 0; i < pa.length(); i ++)
    {
        para[i] = hsh(pa[i]);
        total += para[i];
    }
    if(total > 0)
    {
        for(int i = pa.length() - 1; i >= 0; i --)
        {
            tmp += para[i];
            if(tmp == 1)
            {
                num = pa.length() - (i - 1);
                break;
            }
        }
    }
    if(total < 0)
    {
        for(int i = 0; i < pa.length(); i ++)
        {
            tmp += para[i];
            if(tmp == -1)
            {
                num = i + 2;
                break;
            }
        }
    }
    if(total == 0)
        cout << 0;
    else
        cout << num / 2;
}
