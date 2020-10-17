#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <queue>
using namespace std;
typedef pair<int, int> pii;

vector<int> adj[40010];
bitset<40010> visited;
int dist1[40010];
int dist2[40010];
int distn[40010];
queue<pii> nextInLine;
int main()
{
    int b, e, p, n, m, one, two, curN, curD, ans = 2000000000;
    cin >> b >> e >> p >> n >> m;
    for(int i = 0; i < m; i ++)
    {
        cin >> one >> two;
        adj[one].push_back(two);
        adj[two].push_back(one);
    }
    nextInLine.push(pii(1, 0));
    while(!nextInLine.empty())
    {
        curN = nextInLine.front().first;
        curD = nextInLine.front().second;
        nextInLine.pop();
        if(visited[curN]) continue;
        visited[curN] = true;
        dist1[curN] = curD;
        for(int i = 0; i < adj[curN].size(); i ++)
            nextInLine.push(pii(adj[curN][i], curD + 1));
    }
    visited.reset();
    nextInLine.push(pii(2, 0));
    while(!nextInLine.empty())
    {
        curN = nextInLine.front().first;
        curD = nextInLine.front().second;
        nextInLine.pop();
        if(visited[curN]) continue;
        visited[curN] = true;
        dist2[curN] = curD;
        for(int i = 0; i < adj[curN].size(); i ++)
            nextInLine.push(pii(adj[curN][i], curD + 1));
    }
    visited.reset();
    nextInLine.push(pii(n, 0));
    while(!nextInLine.empty())
    {
        curN = nextInLine.front().first;
        curD = nextInLine.front().second;
        nextInLine.pop();
        if(visited[curN]) continue;
        visited[curN] = true;
        distn[curN] = curD;
        for(int i = 0; i < adj[curN].size(); i ++)
            nextInLine.push(pii(adj[curN][i], curD + 1));
    }
    for(int i = 1; i <= n; i ++)
        ans = min(ans, b * dist1[i] + e * dist2[i] + p * distn[i]);
    cout << ans << "\n";
}
