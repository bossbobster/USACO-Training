#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <math.h>
#include <vector>
#include <stack>
#include <queue>
#include <bitset>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
using namespace std;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef long long ll;
typedef pair<ll, ll> pll;
#define max(n, m) ((n>m)?n:m)
#define min(n, m) ((n<m)?n:m)
#define f first
#define s second

ifstream fin("cowmbat.in");
ofstream fout("cowmbat.out");

int dist[26][26];
int dp[100010][26];
int sum[26];
int main()
{
    int n, m, k, ans = 2000000000;
    string st;
    fin >> n >> m >> k >> st;
    st += "a";
    for(int i = 0; i < m; i ++)
        for(int j = 0; j < m; j ++)
            fin >> dist[i][j];
    for(int k = 0; k < m; k ++)
        for(int i = 0; i < m; i ++)
            for(int j = 0; j < m; j ++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < m; j ++)
            if(i != k - 1)
                dp[i][j] = 1000000000;
    for(int i = 0; i < m; i ++)
        for(int j = 0; j < k; j ++)
        {
            dp[k - 1][i] += dist[st[j] - 'a'][i];
            sum[i] += dist[st[j] - 'a'][i];
        }
    for(int i = k; i < n; i ++)
    {
        for(int j = 0; j < m; j ++)
        {
            sum[j] -= dist[st[i - k] - 'a'][j];
            sum[j] += dist[st[i] - 'a'][j];
        }
        for(int j = 0; j < m; j ++)
        {
            for(int l = 0; l < m; l ++)
            {
                if(j == l)
                    dp[i][j] = min(dp[i][j], dp[i - 1][j] + dist[st[i] - 'a'][j]);
                else
                    dp[i][l] = min(dp[i][l], dp[i - k][j] + sum[l]);
            }
        }
    }
    for(int i = 0; i < m; i ++)
        ans = min(ans, dp[n - 1][i]);
    fout << ans << "\n";
}
