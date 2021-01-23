#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
typedef long long ll;

int mod = 1000000007;
ll dp[100010][5][5][5];
char hsh[4] = {'A', 'C', 'T', 'G'};
int main()
{
    string s;
    cin >> s;
    int n = (int)s.length(), ans = 0;
    for(int now = 0; now < 4; now ++)
        if(s[0] == '?' || s[0] == hsh[now])
            for(int i = 0; i < 4; i ++)
                dp[0][i][now][now] = 1;
    for(int i = 1; i < n; i ++)
        for(int now = 0; now < 4; now ++)
            if(s[i] == '?' || s[i] == hsh[now])
                for(int j = 0; j < 4; j ++)
                    for(int k = 0; k < 4; k ++)
                        for(int l = 0; l < 4; l ++)
                        {
                            if(l != now)
                                dp[i][j][k][now] = (dp[i][j][k][now] + dp[i - 1][j][k][l]) % mod;
                            if(j == l)
                                dp[i][k][now][now] = (dp[i][k][now][now] + dp[i - 1][j][k][l]) % mod;
                        }
    for(int now = 0; now < 4; now ++)
        if(s[n - 1] == '?' || s[n - 1] == hsh[now])
            for(int j = 0; j < 4; j ++)
                ans = (ans + dp[n - 1][now][j][now]) % mod;
    cout << ans << "\n";
}
