// NOT A USACO PROBLEM
#include <iostream>
#include <algorithm>
using namespace std;

int dp[2][1010];
string s1, s2;
int main()
{
    cin >> s1 >> s2;
    for(int i = 0; i <= s1.length(); i ++)
        for(int j = 0; j <= s2.length(); j ++)
        {
            dp[(i + 1) % 2][j] = max(dp[(i + 1) % 2][j], dp[i % 2][j]);
            dp[i % 2][j + 1] = max(dp[i % 2][j + 1], dp[i % 2][j]);
            if(s1[i] == s2[j])
                dp[(i + 1) % 2][j + 1] = max(dp[(i + 1) % 2][j + 1], dp[i % 2][j] + 1);
        }
    cout << max(dp[0][s2.length()], dp[1][s2.length()]) << "\n";
}
