#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define f first
#define s second

struct dsu
{
    int sz[200010];
    int par[200010];
    dsu(int n)
    {
        for(int i = 0; i <= n; i ++)
        {
            sz[i] = 1;
            par[i] = i;
        }
    }
    int root(int cur)
    {
        if(par[cur] == cur) return cur;
        return par[cur] = root(par[cur]);
    }
    bool same(int n, int m)
    {
        return (root(n) == root(m));
    }
    void un(int n, int m)
    {
        n = root(n);
        m = root(m);
        if(n == m) return;
        if(sz[n] < sz[m]) swap(n, m);
        par[m] = n;
        sz[n] += sz[m];
    }
};
int n, ans = 0;
int node[100010][4];
vector<int> portals[200010];
int cost[100010];
pii sorted[100010];
int main()
{
    cin >> n;
    dsu d = dsu(n*2);
    for(int i = 0; i < n; i ++)
    {
        cin >> cost[i];
        sorted[i].f = cost[i]; sorted[i].s = i;
        for(int j = 0; j < 4; j ++)
        {
            cin >> node[i][j]; node[i][j] --;
            portals[node[i][j]].push_back(i*2 + j/2);
        }
    }
    sort(sorted, sorted + n);
    for(int i = 0; i < 2 * n; i ++)
        d.un(portals[i][0], portals[i][1]);
    int i;
    for(int j = 0; j < n; j ++)
    {
        i = sorted[j].s;
        if(d.same(i*2, i*2 + 1)) continue;
        ans += cost[i];
        d.un(i*2, i*2 + 1);
    }
    cout << ans << "\n";
    return 0;
}
