#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <bitset>
#include <stack>
#include <set>
using namespace std;
typedef pair<int, int> pii;

int k, n, m, one, two, three, curSCC = 1, ans = 0, cur;
int cows[110];
int isCow[1010];
vector<int> adj[1010];
vector<int> rev[1010];
vector<int> compressed[1010];
bitset<1010> visited;
stack<int> order;
int scc[1010];
queue<int> nextInLine;
int indegree[1010];
int numNodes[1010];
int numCows[1010];
set<int> compressedList[1010];
set<pii> already;
void dfsAssignValues(int cur)
{
    if(visited[cur]) return;
    visited[cur] = true;
    for(int i = 0; i < rev[cur].size(); i ++)
        dfsAssignValues(rev[cur][i]);
    order.push(cur);
}
void dfsFindSCC(int cur)
{
    if(scc[cur] != 0) return;
    scc[cur] = curSCC;
    for(int i = 0; i < adj[cur].size(); i ++)
        dfsFindSCC(adj[cur][i]);
}
int main()
{
    cin >> k >> n >> m;
    for(int i = 0; i < k; i ++)
    {
        cin >> cows[i];
        isCow[cows[i] - 1] ++;
    }
    for(int i = 0; i < m; i ++)
    {
        cin >> one >> two;
        if(already.find(pii(one, two)) != already.end()) continue;
        already.insert(pii(one, two));
        adj[one - 1].push_back(two - 1);
        rev[two - 1].push_back(one - 1);
    }
    for(int i = 0; i < n; i ++)
        dfsAssignValues(i);
    for(int i = 0; i < n; i ++)
    {
        if(order.empty()) break;
        int now = order.top();
        order.pop();
        if(scc[now] != 0) continue;
        dfsFindSCC(now);
        curSCC ++;
    }
    for(int i = 0; i < n; i ++)
    {
        numCows[scc[i]] += isCow[i];
        numNodes[scc[i]] ++;
        for(int j = 0; j < adj[i].size(); j ++)
        {
            int c = scc[adj[i][j]];
            if(c == scc[i]) continue;
            if(compressedList[scc[i]].find(c) != compressedList[scc[i]].end()) continue;
            compressedList[scc[i]].insert(c);
            compressed[scc[i]].push_back(c);
            indegree[c] ++;
        }
    }
    for(int i = 1; i <= curSCC; i ++)
        if(indegree[i] == 0)
            nextInLine.push(i);
    while(!nextInLine.empty())
    {
        cur = nextInLine.front();
        nextInLine.pop();
        if(numCows[cur] == k)
            ans += numNodes[cur];
        for(int i = 0; i < compressed[cur].size(); i ++)
        {
            numCows[compressed[cur][i]] += numCows[cur];
            indegree[compressed[cur][i]] --;
            if(indegree[compressed[cur][i]] == 0)
                nextInLine.push(compressed[cur][i]);
        }
    }
    cout << ans << "\n";
}
