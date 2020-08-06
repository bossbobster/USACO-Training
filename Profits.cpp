#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, cur, total = 0, ans = -2000000000;
    cin >> n;
    for(int i = 0; i < n; i ++)
    {
        cin >> cur;
        ans = max(ans, cur);
        if(total + cur < 0) { total = 0; continue; }
        else total += cur;
        ans = max(ans, total);
    }
    cout << ans << "\n";
}
