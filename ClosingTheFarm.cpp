#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

struct dsu
{
    // parent array
    int par[200010];
    // size array
    int size[200010];
    // constructor
    dsu(int s)
    {
        for(int i = 0; i <= s; i ++)
        {
            par[i] = i; size[i] = 1;
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
        if(n == m) return;
        if(size[n] < size[m])
            swap(n, m);
        par[m] = n;
        size[n] += size[m];
    }
};

vector<int> adj[200010];
stack<int> ord;
stack<string> ans;
bool used[200010];
int main()
{
    int n, m, one, two, cur, first, cnt = 0;
    cin >> n >> m;
    dsu d = dsu(n + 10);
    for(int i = 0; i < m; i ++)
    {
        cin >> one >> two;
        adj[one].push_back(two);
        adj[two].push_back(one);
    }
    for(int i = 0; i < n; i ++)
    {
        cin >> one;
        ord.push(one);
    }
    first = ord.top();
    while(!ord.empty())
    {
        cur = ord.top(); ord.pop();
        used[cur] = true;
        cnt ++;
        for(int i = 0; i < adj[cur].size(); i ++)
            if(used[adj[cur][i]])
                d.un(cur, adj[cur][i]);
        if(d.size[d.root(first)] == cnt) ans.push("YES");
        else ans.push("NO");
    }
    while(!ans.empty())
    {
        cout << ans.top() << "\n";
        ans.pop();
    }
}
