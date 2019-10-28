#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    string s, t;
    int idx = 0;
    cin >> s >> t;
    while(idx < (s.length() - t.length()))
    {
        if(s.substr(idx, t.length()) == t)
        {
            s = s.substr(0, idx) + s.substr(idx + t.length(), s.length() - idx - t.length());
            idx -= (t.length() + 1);
        }
        idx ++;
        if(idx < 0)
            idx = 0;
    }
    cout << s;
}
