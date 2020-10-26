#include <iostream>
#include <algorithm>
#include <math.h>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int, int> pii;

struct edge
{
    int a, b, p, q;
};
edge edges[50010];
int len[10010];
int par1[10010];
int par2[10010];
priority_queue<pii, vector<pii>, greater<pii>> nextInLine;
vector<pii> adj1[10010];
vector<pii> adj2[10010];
vector<int> adj3[10010];
int main()
{
    int n, m, curN, curD, cur;
    cin >> n >> m;
    for(int i = 0; i < m; i ++)
    {
        cin >> edges[i].a >> edges[i].b >> edges[i].p >> edges[i].q;
        edges[i].a --; edges[i].b --;
        adj1[edges[i].b].push_back(pii(edges[i].a, edges[i].p));
        adj2[edges[i].b].push_back(pii(edges[i].a, edges[i].q));
    }
    for(int i = 0; i < n; i ++)
    {
        len[i] = 2000000000;
        par1[i] = par2[i] = -1;
    }
    nextInLine.push(pii(0, n - 1));
    len[n - 1] = 0;
    while(!nextInLine.empty())
    {
        curD = nextInLine.top().first;
        curN = nextInLine.top().second;
        nextInLine.pop();
        for(int i = 0; i < adj1[curN].size(); i ++)
            if(len[curN] + adj1[curN][i].second < len[adj1[curN][i].first])
            {
                len[adj1[curN][i].first] = len[curN] + adj1[curN][i].second;
                nextInLine.push(pii(len[adj1[curN][i].first], adj1[curN][i].first));
                par1[adj1[curN][i].first] = curN;
            }
    }
    for(int i = 0; i < n; i ++)
        len[i] = 2000000000;
    nextInLine.push(pii(0, n - 1));
    len[n - 1] = 0;
    while(!nextInLine.empty())
    {
        curD = nextInLine.top().first;
        curN = nextInLine.top().second;
        nextInLine.pop();
        for(int i = 0; i < adj2[curN].size(); i ++)
            if(len[curN] + adj2[curN][i].second < len[adj2[curN][i].first])
            {
                len[adj2[curN][i].first] = len[curN] + adj2[curN][i].second;
                nextInLine.push(pii(len[adj2[curN][i].first], adj2[curN][i].first));
                par2[adj2[curN][i].first] = curN;
            }
    }
    for(int i = 0; i < m; i ++)
        adj3[edges[i].a].push_back(edges[i].b);
    for(int i = 0; i < n; i ++)
        len[i] = 2000000000;
    nextInLine.push(pii(0, 0));
    len[0] = 0;
    while(!nextInLine.empty())
    {
        curD = nextInLine.top().first;
        curN = nextInLine.top().second;
        nextInLine.pop();
        for(int i = 0; i < adj3[curN].size(); i ++)
        {
            cur = 0;
            if(par1[curN] != adj3[curN][i]) cur ++;
            if(par2[curN] != adj3[curN][i]) cur ++;
            if(len[curN] + cur < len[adj3[curN][i]])
            {
                len[adj3[curN][i]] = len[curN] + cur;
                nextInLine.push(pii(len[adj3[curN][i]], adj3[curN][i]));
            }
        }
    }
    cout << len[n - 1] << "\n";
}
