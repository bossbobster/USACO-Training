#include <iostream>
using namespace std;

int main()
{
    int n, c = 0;
    long long add = 0, ans = 0;
    char cur;
    cin >> n;
    for(int i = 0; i < n; i ++)
    {
        cin >> cur;
        if(cur == 'C') c ++;
        if(cur == 'O') add += c;
        if(cur == 'W') ans += add;
    }
    cout << ans;
}
