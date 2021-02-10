#include <iostream>
#include <iomanip>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
#define max(n, m) ((n>m)?n:m)
#define min(n, m) ((n<m)?n:m)
#define f first
#define s second

struct st
{
    int a, b;
    bool same;
};
struct con
{
    int other, idx;
    bool same;
};
struct dsu
{
    // parent array
    int par[100000];
    // size array
    int size[100000];
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

int n, m, one, two;
short cc[1010];
bool visited[1010];
bool used[1010];
char three;
st qs[10010];
vector<con> adj[1010];
queue<int> nextInLine;
int ans = 0;
void bs(int l, int r)
{
    int mid = (l + r) / 2;
    for(int i = 0; i < n; i ++) { cc[i] = 0; visited[i] = used[i] = false; }
    dsu d = dsu(n);
    for(int i = 0; i <= mid; i ++)
    {
        d.un(qs[i].a, qs[i].b);
        used[qs[i].a] = used[qs[i].b] = true;
    }
    for(int i = 0; i < n; i ++)
        if(used[d.root(i)])
        {
            cc[d.root(i)] = 1;
            nextInLine.push(d.root(i));
        }
    while(!nextInLine.empty())
    {
        int i = nextInLine.front();
        nextInLine.pop();
        if(visited[i] || !cc[i]) continue;
        visited[i] = true;
        for(int j = 0; j < adj[i].size(); j ++)
        {
            if(adj[i][j].idx > mid) continue;
            if(adj[i][j].same)
            {
                if(cc[adj[i][j].other] != 0 && cc[adj[i][j].other] != cc[i])
                {
                    if(l == mid) return;
                    return bs(l, mid);
                }
                else
                    cc[adj[i][j].other] = cc[i];
                nextInLine.push(adj[i][j].other);
            }
            else
            {
                if(cc[adj[i][j].other] != 0 && cc[adj[i][j].other] == cc[i])
                {
                    if(l == mid) return;
                    return bs(l, mid);
                }
                else
                    cc[adj[i][j].other] = ((cc[i]==1)?2:1);
                nextInLine.push(adj[i][j].other);
            }
        }
    }
    ans = max(ans, mid);
    if(r <= mid) return;
    return bs(mid + 1, r);
}
int main()
{
    cin >> n >> m;
    for(int i = 0; i < m; i ++)
    {
        cin >> one >> two >> three;
        qs[i].a = one - 1; qs[i].b = two - 1; qs[i].same = (three=='T');
        adj[one - 1].push_back({two - 1, i, (three=='T')});
        adj[two - 1].push_back({one - 1, i, (three=='T')});
    }
    bs(0, m - 1);
    cout << ans + 1 << "\n";
}
