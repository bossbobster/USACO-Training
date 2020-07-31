#include <iostream>
#include <algorithm>
using namespace std;

int dp[2][30][3];
int main()
{
    int n, k, cur = 0, ans = 0;
    char curC;
    cin >> n >> k;
    cin >> curC;
    if(curC == 'H') cur = 0;
    if(curC == 'P') cur = 1;
    if(curC == 'S') cur = 2;
    dp[0][0][cur] = 1;
    for(int i = 0; i < n; i ++)
    {
        for(int j = 0; j <= k; j ++)
            for(int l = 0; l < 3 && i != 0; l ++)
            {
                if(cur == l) dp[i % 2][j][l] = max(dp[i % 2][j][l], dp[(i - 1) % 2][j][l] + 1);
                else dp[i % 2][j][l] = max(dp[i % 2][j][l], dp[(i - 1) % 2][j][l]);
                if(j > 0) dp[i % 2][j][l] = max(dp[i % 2][j][l], dp[(i - 1) % 2][j - 1][cur] + 1);
            }
        cin >> curC;
        if(curC == 'H') cur = 0;
        if(curC == 'P') cur = 1;
        if(curC == 'S') cur = 2;
    }
    for(int i = 0; i <= k; i ++)
        ans = max(max(ans, dp[(n - 1) % 2][i][0]), max(dp[(n - 1) % 2][i][1], dp[(n - 1) % 2][i][2]));
    cout << ans << "\n";
}
