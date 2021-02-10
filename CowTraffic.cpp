#include <iostream>
#include <iomanip>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
#define max(n, m) ((n>m)?n:m)
#define min(n, m) ((n<m)?n:m)
#define f first
#define s second

vector<int> adj[5010];
vector<int> revAdj[5010];
int in[5010];
int dp1[5010];
int dp2[5010];
vector<int> gr;
int main()
{
    int n, m, one, two, ans = 0;
    cin >> n >> m;
    for(int i = 0; i < m; i ++)
    {
        cin >> one >> two;
        one --; two --;
        adj[one].push_back(two);
        revAdj[two].push_back(one);
        in[two] ++;
    }
    for(int i = 0; i < n; i ++)
        if(in[i] == 0)
            gr.push_back(i);
    for(int i = 0; i < gr.size(); i ++)
        dp1[gr[i]] = 1;
    for(int i = 1; i < n; i ++)
        for(int other : revAdj[i])
            dp1[i] += dp1[other];
    dp2[n - 1] = 1;
    for(int i = n - 2; i >= 0; i --)
        for(int other : adj[i])
            dp2[i] += dp2[other];
    for(int i = 0; i < n; i ++)
        for(int other : adj[i])
            ans = max(ans, dp1[i] * dp2[other]);
    cout << ans << "\n";
}
