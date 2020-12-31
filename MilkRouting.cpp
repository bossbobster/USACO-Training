#include <iostream>
#include <algorithm>
#include <math.h>
#include <queue>
#include <vector>
#include <unordered_map>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef pair<int, int> pii;

struct edge
{
    int node, d, c;
    const bool operator>(const edge& other) const
    {
        return d < other.d;
    }
};

gp_hash_table<int, int> len[510];
priority_queue<edge, vector<edge>, greater<edge>> nextInLine;
vector<edge> adj[510];
int main()
{
    int n, m, x, curN, curD, curC, tmpC, one, two, three, four, ans = 2000000000;
    cin >> n >> m >> x;
    for(int i = 0; i < m; i ++)
    {
        cin >> one >> two >> three >> four;
        adj[one - 1].push_back({two - 1, three, four});
        adj[two - 1].push_back({one - 1, three, four});
        for(int j = 0; j < n; j ++)
            len[j][four] = 2000000000;
    }
    nextInLine.push({0, 0, 2000000000});
    len[0][2000000000] = 0;
    while(!nextInLine.empty())
    {
        curD = nextInLine.top().d;
        curN = nextInLine.top().node;
        curC = nextInLine.top().c;
        nextInLine.pop();
        for(int i = 0; i < adj[curN].size(); i ++)
        {
            tmpC = min(curC, adj[curN][i].c);
            if(len[curN][curC] + adj[curN][i].d < len[adj[curN][i].node][tmpC])
            {
                len[adj[curN][i].node][tmpC] = len[curN][curC] + adj[curN][i].d;
                nextInLine.push({adj[curN][i].node, len[adj[curN][i].node][tmpC], tmpC});
            }
        }
    }
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < adj[i].size(); j ++)
            ans = min(ans, len[n - 1][adj[i][j].c] + (x / adj[i][j].c));
    cout << ans << "\n";
}
