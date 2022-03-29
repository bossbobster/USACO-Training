#include <iostream>
#include <iomanip>
#include <algorithm>
#include <math.h>
#include <vector>
#include <stack>
using namespace std;
typedef pair<int, int> pii;
#define max(n, m) ((n>m)?n:m)
#define min(n, m) ((n<m)?n:m)
#define f first
#define s second

/*int nums[110];
int dp[210][10][210]; // current index, doors used, prev door
int main()
{
    int n, m, ans = 2000000000;
    cin >> n >> m;
    for(int i = 0; i < n; i ++)
        cin >> nums[i];
    for(int first = 0; first < n; first ++)
    {
        for(int i = 0; i <= n * 2; i ++)
            for(int j = 0; j <= m; j ++)
                for(int k = 0; k <= n * 2; k ++)
                    dp[i][j][k] = 2000000000;
        dp[first][1][first] = 0;
        for(int i = first; i < first + n; i ++)
            for(int j = 1; j <= m; j ++)
                for(int k = first; k <= i; k ++)
                {
                    dp[i + 1][j][k] = min(dp[i + 1][j][k], dp[i][j][k] + (i + 1 - k) * nums[(i + 1) % n]);
                    dp[i + 1][j + 1][i + 1] = min(dp[i + 1][j + 1][i + 1], dp[i][j][k]);
                }
        for(int i = first; i <= first + n; i ++)
            ans = min(ans, dp[first + n - 1][m][i]);
    }
    cout << ans << "\n";
}*/

ll nums[110], pre[310][310];
ll dp[210][10]; // current index, doors used
int main()
{
    ll n, m, ans = 20000000000000000;
    fin >> n >> m;
    for(int i = 0; i < n; i ++)
        fin >> nums[i];
    for(int i = 0; i <= 2*n; i ++)
        pre[i][i] = nums[i%n];
    for(int i = 0; i <= 3*n; i ++)
        for(int j = i+1; j <= 3*n; j ++)
            pre[i][j] = pre[i][j-1]+nums[j%n]*(j-i+1);
    for(int first = 0; first < n; first ++)
    {
        for(int i = 0; i <= n*2; i ++)
            for(int j = 0; j <= m; j ++)
                dp[i][j] = 2000000000000000;
        dp[first][1] = 0;
        for(int i = first+1; i < first+n; i ++)
            for(int j = 2; j <= m; j ++)
                for(int k = first; k < i; k ++)
                    dp[i][j] = min(dp[i][j], dp[k][j-1] + pre[k+1][i-1]);
        for(int i = first; i < first+n; i ++)
            ans = min(ans, dp[i][m]+pre[i+1][first+n-1]);
    }
    fout << ans << "\n";
}
