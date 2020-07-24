#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <math.h>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int, int> pii;

int v, e, curN, curD, one, two, three, best, ans = 0, dist;
int len[110];
priority_queue<pii, vector<pii>, greater<pii>> nextInLine;
vector<pii> adj[110];
int prevN[110];
vector<int> shortest;
void dij(int start, int f, int s)
{
    for(int i = 0; i < v; i ++)
        len[i] = 2000000000;
    nextInLine.push(pii(0, start));
    len[start] = 0;
    while(!nextInLine.empty())
    {
        curD = nextInLine.top().first;
        curN = nextInLine.top().second;
        nextInLine.pop();
        
        for(int i = 0; i < adj[curN].size(); i ++)
        {
            if((curN == f && adj[curN][i].first == s) || (curN == s && adj[curN][i].first == f))
                dist = adj[curN][i].second * 2;
            else
                dist = adj[curN][i].second;
            if(len[curN] + dist < len[adj[curN][i].first])
            {
                prevN[adj[curN][i].first] = curN;
                len[adj[curN][i].first] = len[curN] + dist;
                nextInLine.push(pii(len[adj[curN][i].first], adj[curN][i].first));
            }
        }
    }
}
int main()
{
    cin >> v >> e;
    for(int i = 0; i < e; i ++)
    {
        cin >> one >> two >> three;
        adj[one - 1].push_back(pii(two - 1, three));
        adj[two - 1].push_back(pii(one - 1, three));
    }
    dij(0, -1, -1);
    best = len[v - 1];
    one = v - 1;
    while(one != 0)
    {
        shortest.push_back(one);
        one = prevN[one];
    }
    shortest.push_back(0);
    for(int i = (int)shortest.size() - 1; i > 0; i --)
    {
        dij(0, shortest[i], shortest[i - 1]);
        ans = max(ans, len[v - 1] - best);
    }
    cout << ans << "\n";
}
