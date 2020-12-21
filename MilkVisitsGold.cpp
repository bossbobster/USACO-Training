#include <iostream>
#include <fstream>
#include <algorithm>
#include <math.h>
#include <set>
#include <vector>
using namespace std;
typedef pair<int, int> pii;

ifstream fin("milkvisits.in");
ofstream fout("milkvisits.out");

struct q
{
    int other, c, idx;
};
struct node
{
    int val, dep;
};

pii endpts[100010];
int types[100010];
vector<int> adj[100010];
vector<q> qs[100010];
bool ans[100010];
vector<int> path;
vector<node> each[100010];

int cnt = 0;
void euler(int cur, int par)
{
    endpts[cur].first = cnt ++;
    for(int i = 0; i < adj[cur].size(); i ++)
        if(adj[cur][i] != par)
            euler(adj[cur][i], cur);
    endpts[cur].second = cnt - 1;
}
bool isAncestor(int anc, int node)
{
    return endpts[anc].first <= endpts[node].first && endpts[anc].second >= endpts[node].second;
}
void solve(int cur, int par)
{
    each[types[cur]].push_back({cur, (int)path.size()});
    path.push_back(cur);
    for(int i = 0; i < qs[cur].size(); i ++)
    {
        if(!each[qs[cur][i].c].size()) continue;
        node curN = each[qs[cur][i].c].back();
        if(curN.val == cur) ans[qs[cur][i].idx] = true;
        else
        {
            if(curN.dep + 1 >= path.size()) continue;
            int curN2 = path[curN.dep + 1];
            if(!isAncestor(curN2, qs[cur][i].other)) ans[qs[cur][i].idx] = true;
        }
    }
    for(int i = 0; i < adj[cur].size(); i ++)
        if(adj[cur][i] != par)
            solve(adj[cur][i], cur);
    path.pop_back();
    each[types[cur]].pop_back();
}
int main()
{
    int n, m, one, two, three;
    fin >> n >> m;
    for(int i = 0; i < n; i ++)
        fin >> types[i];
    for(int i = 0; i < n - 1; i ++)
    {
        fin >> one >> two;
        adj[one - 1].push_back(two - 1);
        adj[two - 1].push_back(one - 1);
    }
    for(int i = 0; i < m; i ++)
    {
        fin >> one >> two >> three;
        q query;
        query.other = two - 1; query.c = three; query.idx = i;
        qs[one - 1].push_back(query);
        query.other = one - 1;
        qs[two - 1].push_back(query);
    }
    euler(0, -1);
    solve(0, -1);
    for(int i = 0; i < m; i ++)
        fout << ans[i];
    fout << "\n";
}
