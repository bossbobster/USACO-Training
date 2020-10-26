#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <math.h>
using namespace std;

struct edge
{
    int r1, r2, c1, c2, cost;
};
int ans = -1, current, siz;
struct dsu
{
    // parent array
    int par[250020];
    // size array
    int size[250020];
    // constructor
    dsu(int s)
    {
        for(int i = 0; i <= s; i ++)
        {
            par[i] = i; size[i] = 1;
        }
    }
    // find root of n
    int root(int n1)
    {
        if(par[n1] == n1 || par[n1] == -1)
            return n1;
        return par[n1] = root(par[n1]);
    }
    // return true if n and m are in the same CC
    bool con(int n1, int n2, int m1, int m2)
    {
        return (root(n1 * siz + n2) == root(m1 * siz + m2));
    }
    // connect n and m
    void un(int n1, int n2, int m1, int m2, int wanted)
    {
        n1 = root(n1 * siz + n2); m1 = root(m1 * siz + m2);
        if(n1 == m1) return;
        if(size[n1] < size[m1])
            swap(n1, m1);
        par[m1] = n1;
        size[n1] += size[m1];
        if(size[n1] >= wanted)
            ans = current;
    }
};
bool comp(edge e1, edge e2)
{
    return e1.cost < e2.cost;
}
int board[510][510];
vector<edge> edges;
int main()
{
    int n, w;
    edge cur;
    cin >> n;
    siz = n;
    if(n % 2 == 0) w = n * n / 2;
    else w = n * n / 2 + 1;
    dsu d = dsu(n * n + 10);
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < n; j ++)
            cin >> board[i][j];
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < n - 1; j ++)
        {
            edge tmp;
            tmp.r1 = i; tmp.r2 = i;
            tmp.c1 = j; tmp.c2 = j + 1;
            tmp.cost = abs(board[i][j] - board[i][j + 1]);
            edges.push_back(tmp);
        }
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < n - 1; j ++)
        {
            edge tmp;
            tmp.c1 = i; tmp.c2 = i;
            tmp.r1 = j; tmp.r2 = j + 1;
            tmp.cost = abs(board[j][i] - board[j + 1][i]);
            edges.push_back(tmp);
        }
    sort(edges.begin(), edges.end(), comp);
    for(int i = 0; i < edges.size(); i ++)
    {
        cur = edges[i];
        current = cur.cost;
        d.un(cur.r1, cur.c1, cur.r2, cur.c2, w);
        if(ans != -1)
        {
            cout << ans << "\n";
            return 0;
        }
    }
    cout << "???";
}
