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

long long n, k, one, two, curAdd, mod = 1000000007;
vector<int> adj[100010];
long long nums[100010];
long long dp[100010][5];
long long dfs(int cur, int c, int par)
{
    if(nums[cur] != -1 && nums[cur] != c) { dp[cur][c] = 0; return 0; }
    if(dp[cur][c] != -1) return dp[cur][c];
    dp[cur][c] = 1;
    for(int other : adj[cur])
    {
        if(other == par) continue;
        curAdd = 0;
        for(int i = 0; i < 3; i ++)
            if(i != c)
                curAdd = (curAdd + dfs(other, i, cur)) % mod;
        dp[cur][c] = (dp[cur][c] * curAdd) % mod;
    }
    return dp[cur][c];
}
int main()
{
    cin >> n >> k;
    for(int i = 0; i < n - 1; i ++)
    {
        cin >> one >> two;
        one --; two --;
        adj[one].push_back(two);
        adj[two].push_back(one);
        nums[i] = -1;
    }
    nums[n - 1] = -1;
    for(int i = 0; i < k; i ++)
    {
        cin >> one >> two;
        one --; two --;
        nums[one] = two;
    }
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < 5; j ++)
            dp[i][j] = -1;
    cout << (dfs(0, 0, -1) + dfs(0, 1, -1) + dfs(0, 2, -1)) % mod << "\n";
}
