#include <iostream>
using namespace std;

int n, z, o, ans = 0;
void printAll(int n1, string s)
{
    if(n1 == 0)
    {
        z = o = 0;
        for(int i = 0; i < s.length(); i ++)
        {
            if(s[i] == '0') z ++;
            else o ++;
        }
        if(o > z)
        {
            cout << s << "\n"; ans ++;
        }
        return;
    }
    printAll(n1 - 1, s + "0");
    printAll(n1 - 1, s + "1");
}
int main()
{
    cin >> n;
    printAll(n, "");
    cout << ans << endl;
}
