#include <iostream>
#include <algorithm>
using namespace std;

int dp[1010];
string s1, s2;
int main()
{
    int ans = 0;
    cin >> s1 >> s2;
    for(int i = 0; i < s1.length(); i ++)
        for(int j = s2.length() - 1; j >= 0; j --)
        {
            if(s1[i] == s2[j])
                dp[j + 1] = dp[j] + 1;
            else
                dp[j + 1] = 0;
            ans = max(ans, dp[j + 1]);
        }
    cout << ans << "\n";
}
