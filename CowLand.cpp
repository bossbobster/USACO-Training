#include <iostream>
#include <fstream>
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

ifstream fin("cowland.in");
ofstream fout("cowland.out");

struct queryS
{
    int t, a, b;
};

int n, q, one, two;
int nums[100010];
vector<int> adj[100010];
int lca[100010][20];
int size[100010];
int depth[100010];
queryS qs[100010];
int seg[400010];
int ogToSeg[100010];
int top[100010];

// update seg tree
void segUpdate(int cur, int l, int r, int idx, int val)
{
    if(l == r) seg[cur] = val;
    else
    {
        int mid = (l + r) / 2;
        if(idx <= mid) segUpdate(cur * 2, l, mid, idx, val);
        else segUpdate(cur * 2 + 1, mid + 1, r, idx, val);
        seg[cur] = seg[cur * 2] ^ seg[cur * 2 + 1];
    }
}
void up(int idx, int val) { return segUpdate(1, 0, n - 1, idx, val); }

// query seg tree
int segSum(int cur, int l, int r, int lq, int rq)
{
    if(l >= lq && r <= rq) return seg[cur];
    int mid = (l + r) / 2, ans = 0;
    if(mid >= lq) ans ^= segSum(cur * 2, l, mid, lq, rq);
    if(mid + 1 <= rq) ans ^= segSum(cur * 2 + 1, mid + 1, r, lq, rq);
    return ans;
}
int sm(int lq, int rq) { return segSum(1, 0, n - 1, lq, rq); }

// function for getting LCA of nodes a and b, works in log(N)
int LCA(int a, int b)
{
    if(depth[b] > depth[a]) swap(a, b);
    for(int i = 19; i >= 0; i --)
        if(depth[a] - (1 << i) >= depth[b])
            a = lca[a][i];
    for(int i = 19; i >= 0; i --)
        if(lca[a][i] != lca[b][i])
        {
            a = lca[a][i]; b = lca[b][i];
        }
    if(a != b)
        a = lca[a][0];
    return a;
}

// initial DFS for size of each subtree and getting parents & depths of each node
void dfs(int cur, int par)
{
    size[cur] ++;
    for(int other : adj[cur])
    {
        if(other == par) continue;
        depth[other] = depth[cur] + 1;
        lca[other][0] = cur;
        dfs(other, cur);
        size[cur] += size[other];
    }
}

// DFS for heavy-light decomposition (dividing up the tree into around log(N) chains)
void dfsHLD(int cur, int topIdx, int par, int& idx)
{
    ogToSeg[cur] = idx; idx ++;
    up(ogToSeg[cur], nums[cur]);
    top[cur] = topIdx;
    int maxN = -1, maxIdx = -1;
    for(int other : adj[cur])
    {
        if(other == par) continue;
        if(size[other] > maxN)
        {
            maxN = size[other];
            maxIdx = other;
        }
    }
    if(maxIdx < 0) return;
    dfsHLD(maxIdx, topIdx, cur, idx);
    for(int other : adj[cur])
        if(other != par && other != maxIdx)
            dfsHLD(other, other, cur, idx);
}

// get total XOR of path from a to b
int pathUtil(int cur, int par)
{
    int ans = 0;
    while(cur != par)
    {
        if(top[cur] == cur)
        {
            ans ^= nums[cur];
            cur = lca[cur][0];
        }
        else if(depth[top[cur]] > depth[par])
        {
            ans ^= sm(ogToSeg[top[cur]], ogToSeg[cur]);
            cur = lca[top[cur]][0];
        }
        else
        {
            ans ^= sm(ogToSeg[par] + 1, ogToSeg[cur]);
            break;
        }
    }
    return ans;
}
int path(int a, int b)
{
    int lcaAB = LCA(a, b);
    return pathUtil(a, lcaAB) ^ pathUtil(b, lcaAB) ^ nums[lcaAB];
}

int main()
{
    fin >> n >> q;
    for(int i = 0; i < n; i ++)
        fin >> nums[i];
    for(int i = 0; i < n - 1; i ++)
    {
        fin >> one >> two;
        one --; two --;
        adj[one].push_back(two);
        adj[two].push_back(one);
    }
    for(int i = 0; i < q; i ++)
        fin >> qs[i].t >> qs[i].a >> qs[i].b;
    dfs(0, -1);
    for(int i = 1; i < 20; i ++)
        for(int j = 0; j < n; j ++)
            lca[j][i] = lca[lca[j][i - 1]][i - 1];
    int idx = 0;
    dfsHLD(0, 0, -1, idx);
    for(int i = 0; i < q; i ++)
    {
        if(qs[i].t == 1)
        {
            qs[i].a --;
            nums[qs[i].a] = qs[i].b;
            up(ogToSeg[qs[i].a], qs[i].b);
        }
        else
            fout << path(qs[i].a - 1, qs[i].b - 1) << "\n";
    }
}
