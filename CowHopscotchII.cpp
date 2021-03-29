#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef long long ll;
typedef pair<ll, ll> pll;
#define max(n, m) ((n>m)?n:m)
#define min(n, m) ((n<m)?n:m)
#define f first
#define s second

int board[260][260];
ll dp[260][260];
ll cnt[500010];
int main()
{
    int n, m, num, mod = 1000000007; ll sum = 0;
    cin >> n >> m >> num;
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < m; j ++)
            cin >> board[i][j];
    dp[0][0] = 1;
    for(int i = 1; i < n; i ++)
    {
        sum = 0;
        memset(cnt, 0, sizeof(cnt));
        for(int j = 1; j < m; j ++)
        {
            for(int k = 0; k < i; k ++)
            {
                sum = sum + dp[k][j - 1];
                cnt[board[k][j - 1]] = cnt[board[k][j - 1]] + dp[k][j - 1];
            }
            dp[i][j] = (sum - cnt[board[i][j]]) % mod;
        }
    }
    cout << dp[n - 1][m - 1] << "\n";
}
