#include <iostream>
#include <algorithm>
using namespace std;

long long n, mx;
string s;

char rev(long long num)
{
    if(num <= s.length() && num != 0)
        return s[num - 1];
    if(num == 0)
        return s[num];
    mx = s.length();
    while(mx < num)
        mx *= 2;
    mx /= 2;
    return rev(num - mx - 1);
}

int main()
{
    cin >> s >> n;
    cout << rev(n);
}
