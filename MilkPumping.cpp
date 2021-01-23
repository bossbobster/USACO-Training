#include <iostream>
#include <fstream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> pii;

ifstream fin("pump.in");
ofstream fout("pump.out");

struct edge
{
    int other, d, f;
};
struct st
{
    int cur, d, f;
    const bool operator>(const st& other) const
    {
        return d > other.d;
    }
};

vector<edge> adj[1010];
int len[1010][1010];
priority_queue<st, vector<st>, greater<st>> nextInLine;
int main()
{
    int n, m, one, two, three, four, curN, curD, curF;
    long long ans = 0;
    fin >> n >> m;
    for(int i = 0; i < m; i ++)
    {
        fin >> one >> two >> three >> four;
        adj[one - 1].push_back({two - 1, three, four});
        adj[two - 1].push_back({one - 1, three, four});
    }
    for(int i = 0; i < n; i ++)
        for(int j = 0; j <= 1000; j ++)
            len[i][j] = 2000000000;
    len[0][1001] = 0;
    nextInLine.push({0, 0, 1001});
    while(!nextInLine.empty())
    {
        curN = nextInLine.top().cur;
        curD = nextInLine.top().d;
        curF = nextInLine.top().f;
        nextInLine.pop();
        if(len[curN][curF] < curD) continue;
        for(int i = 0; i < adj[curN].size(); i ++)
        {
            if(len[adj[curN][i].other][min(adj[curN][i].f, curF)] > len[curN][curF] + adj[curN][i].d)
            {
                len[adj[curN][i].other][min(adj[curN][i].f, curF)] = len[curN][curF] + adj[curN][i].d;
                nextInLine.push({adj[curN][i].other, len[curN][curF] + adj[curN][i].d, min(adj[curN][i].f, curF)});
            }
        }
    }
    for(int i = 1; i <= 1000; i ++)
        ans = max(ans, (long long)((double)i / (double)len[n - 1][i] * 1000000));
    fout << ans << "\n";
}
