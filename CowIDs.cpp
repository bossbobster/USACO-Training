#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;

int dp[5010][20];
int main()
{
    int n, k, curK;
    bool one = false;
    string ans = "";
    cin >> n >> k;
    curK = k;
    if(k == 1)
    {
        ans = "1";
        for(int i = 0; i < n - 1; i ++) ans += "0";
        cout << ans << "\n";
        return 0;
    }
    dp[0][0] = 1;
    for(int i = 1; i < 5010; i ++)
        for(int j = 0; j < 20; j ++)
        {
            if(j == 0 || j == i) dp[i][j] = 1;
            else dp[i][j] = min(20000000, dp[i - 1][j] + dp[i - 1][j - 1]);
        }
    for(int i = 5009; i >= 0; i --)
    {
        if(dp[i][curK] < n)
        {
            ans += "1";
            n -= dp[i][curK];
            curK = max(0, curK - 1);
            one = true;
        }
        else if(one) ans += "0";
    }
    cout << ans << "\n";
}
