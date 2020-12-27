// CROATIAN INFORMATICS OLYMPIAD PROBLEM (not USACO)
#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

struct d
{
    int a, b;
};
struct dsu
{
    int par[300010];
    dsu(int s)
    {
        for(int i = 0; i <= s; i ++)
            par[i] = i;
    }
    int root(int n)
    {
        if(par[n] == n || par[n] == -1)
            return n;
        return par[n] = root(par[n]);
    }
    void un(int n, int m)
    {
        n = root(n); m = root(m);
        if(n == m) return;
        par[n] = m;
    }
};

d nums[300010];
bool visited[300010];
bool ans[300010];
int main()
{
    int n, l, a, b;
    cin >> n >> l;
    dsu comp = dsu(l + 10);
    for(int i = 0; i < n; i ++)
        cin >> nums[i].a >> nums[i].b;
    for(int i = 0; i < n; i ++)
    {
        a = nums[i].a; b = nums[i].b;
        if(!visited[a])
        {
            ans[i] = visited[a] = true;
            comp.un(a, b);
        }
        else if(!visited[b])
        {
            ans[i] = visited[b] = true;
            comp.un(b, a);
        }
        else if(!visited[comp.root(a)])
        {
            ans[i] = visited[comp.root(a)] = true;
            comp.un(a, b);
        }
        else if(!visited[comp.root(b)])
        {
            ans[i] = visited[comp.root(b)] = true;
            comp.un(b, a);
        }
        else continue;
    }
    for(int i = 0; i < n; i ++)
        cout << ((ans[i])?"LADICA":"SMECE") << "\n";
}
