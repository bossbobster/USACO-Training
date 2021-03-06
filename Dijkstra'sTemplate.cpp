// NOT A USACO PROBLEM
#include <iostream>
#include <algorithm>
#include <math.h>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int, int> pii;

int len[50010];
priority_queue<pii, vector<pii>, greater<pii>> nextInLine;
vector<pii> adj[50010];
int main()
{
    int v, e, s, curN, curD, one, two, three;
    cin >> v >> e >> s;
    s --;
    for(int i = 0; i < e; i ++)
    {
        cin >> one >> two >> three;
        adj[one - 1].push_back(pii(two - 1, three));
        adj[two - 1].push_back(pii(one - 1, three));
    }
    for(int i = 0; i < v; i ++)
        len[i] = 2000000000;
    nextInLine.push(pii(0, s));
    len[s] = 0;
    while(!nextInLine.empty())
    {
        curD = nextInLine.top().first;
        curN = nextInLine.top().second;
        nextInLine.pop();
        if(len[curN] < curD) continue;
        for(int i = 0; i < adj[curN].size(); i ++)
            if(len[curN] + adj[curN][i].second < len[adj[curN][i].first])
            {
                len[adj[curN][i].first] = len[curN] + adj[curN][i].second;
                nextInLine.push(pii(len[adj[curN][i].first], adj[curN][i].first));
            }
    }
    for(int i = 0; i < v; i ++)
    {
        if(len[i] != 2000000000) cout << len[i] << "\n";
        else cout << -1 << "\n";
    }
}
