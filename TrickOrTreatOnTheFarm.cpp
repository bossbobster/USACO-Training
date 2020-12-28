#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> pii;

int n, curN, curD;
int other[100010];
vector<int> rev[100010];
bool visited[100010];
vector<int> cur;
int mark[100010];
int ans[100010];
int cycle[100010];
queue<pii> nextInLine;
void dfs(int node, int d)
{
    if(visited[node])
    {
        if(cycle[node]) return;
        if(mark[node] >= cur.size() || cur[mark[node]] != node) return;
        for(int i = mark[node]; i < d; i ++)
            cycle[cur[i]] = d - mark[node];
        return;
    }
    visited[node] = true;
    mark[node] = d;
    cur.push_back(node);
    dfs(other[node], d + 1);
}
int main()
{
    cin >> n;
    for(int i = 0; i < n; i ++)
    {
        cin >> other[i + 1];
        rev[other[i + 1]].push_back(i + 1);
    }
    for(int i = 1; i <= n; i ++)
    {
        cur.clear();
        dfs(i, 0);
    }
    for(int i = 1; i <= n; i ++)
    {
        visited[i] = false;
        if(cycle[i] != 0)
            nextInLine.push(pii(i, cycle[i]));
    }
    while(!nextInLine.empty())
    {
        curN = nextInLine.front().first;
        curD = nextInLine.front().second;
        nextInLine.pop();
        if(visited[curN]) continue;
        visited[curN] = true;
        ans[curN] = curD;
        for(int i = 0; i < rev[curN].size(); i ++)
            nextInLine.push(pii(rev[curN][i], curD + 1));
    }
    for(int i = 1; i <= n; i ++)
        cout << ans[i] << "\n";
}
