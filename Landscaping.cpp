#include <iostream>
#include <algorithm>
using namespace std;

int dp[1010][1010];
int s1[1010];
int s2[1010];
int main()
{
    int n, x, y, z, one, two, idx1 = 0, idx2 = 0;
    cin >> n >> x >> y >> z;
    for(int i = 0; i < n; i ++)
    {
        cin >> one >> two;
        for(int j = 0; j < one; j ++) { s1[idx1] = i; idx1 ++; }
        for(int j = 0; j < two; j ++) { s2[idx2] = i; idx2 ++; }
    }
    for(int i = 0; i <= idx1; i ++)
        for(int j = 0; j <= idx2; j ++)
            dp[i][j] = 2000000000;
    dp[0][0] = 0;
    for(int i = 0; i <= idx1; i ++)
        for(int j = 0; j <= idx2; j ++)
        {
            dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + y);
            dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + x);
            if(s1[i] == s2[j])
                dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j]);
            else
                dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + (z * (abs(s1[i] - s2[j]))));
        }
    cout << dp[idx1][idx2] << "\n";
}
