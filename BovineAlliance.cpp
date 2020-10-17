#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

struct dsu
{
    // parent array
    int par[100010];
    // size array
    int size[100010];
    int edges[100010];
    // constructor
    dsu(int s)
    {
        for(int i = 0; i <= s; i ++)
        {
            par[i] = i; size[i] = 1; edges[i] = 0;
        }
    }
    // find root of n
    int root(int n)
    {
        if(par[n] == n || par[n] == -1)
            return n;
        return par[n] = root(par[n]);
    }
    // return true if n and m are in the same CC
    bool con(int n, int m)
    {
        return (root(n) == root(m));
    }
    // connect n and m
    void un(int n, int m)
    {
        n = root(n); m = root(m);
        if(size[n] < size[m])
            swap(n, m);
        edges[n] ++;
        if(n == m) return;
        par[m] = n;
        size[n] += size[m];
        edges[n] += edges[m];
    }
};
set<int> visited;
int main()
{
    int n, m, one, two;
    long long ans = 1;
    cin >> n >> m;
    dsu d = dsu(n);
    for(int i = 0; i < m; i ++)
    {
        cin >> one >> two;
        d.un(one - 1, two - 1);
    }
    for(int i = 0; i < n; i ++)
    {
        if(visited.find(d.root(i)) != visited.end()) continue;
        visited.insert(d.root(i));
        int cur = d.root(i);
        if(d.edges[cur] > d.size[cur]) ans *= 0;
        else if(d.edges[cur] == d.size[cur]) ans *= 2;
        else ans *= d.size[cur];
        ans = ans % 1000000007;
    }
    cout << ans << "\n";
}
