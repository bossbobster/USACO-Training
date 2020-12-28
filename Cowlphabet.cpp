#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

string st[210];
int dp[100][260][260];
bool good[100][100];
int main()
{
    int u, l, p, ans = 0;
    cin >> u >> l >> p;
    for(int i = 0; i < p; i ++)
    {
        cin >> st[i];
        good[st[i][0] - 'A'][st[i][1] - 'A'] = true;
    }
    for(int i = 'A'; i < 'A' + 70; i ++)
    {
        if(!(i <= 'Z' || (i >= 'a' && i <= 'z'))) continue;
        dp[i - 'A'][((i<='Z')?1:0)][((i<='Z')?0:1)] ++;
    }
    for(int i = 0; i <= u; i ++)
        for(int j = 0; j <= l; j ++)
        {
            if(i == 0 && j == 0) continue;
            for(int k = 'A'; k < 'A' + 70; k ++)
            {
                if(!(k <= 'Z' || (k >= 'a' && k <= 'z'))) continue;
                for(int l = 'A'; l < 'A' + 70; l ++)
                {
                    if(!(l <= 'Z' || (l >= 'a' && l <= 'z'))) continue;
                    if(!good[k - 'A'][l - 'A']) continue;
                    dp[l - 'A'][i + ((l<='Z')?1:0)][j + ((l<='Z')?0:1)] = (dp[l - 'A'][i + ((l<='Z')?1:0)][j + ((l<='Z')?0:1)] + dp[k - 'A'][i][j]) % 97654321;
                }
            }
        }
    for(int i = 0; i < 100; i ++)
        ans = (ans + dp[i][u][l]) % 97654321;
    cout << ans << "\n";
}
