#include <iostream>
#include <algorithm>
using namespace std;

int dp[1010][1010];
string s1, s2;
int main()
{
    cin >> s1 >> s2;
    for(int i = 0; i <= s1.length(); i ++)
        for(int j = 0; j <= s2.length(); j ++)
            dp[i][j] = 2000000000;
    dp[0][0] = 0;
    for(int i = 0; i <= s1.length(); i ++)
        for(int j = 0; j <= s2.length(); j ++)
        {
            dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + 1);
            dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + 1);
            if(s1[i] == s2[j])
                dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j]);
            else
                dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + 1);
        }
    cout << dp[s1.length()][s2.length()] << "\n";
}
