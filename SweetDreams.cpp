#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
#include <set>
using namespace std;
typedef pair<int, int> pii;

int len[50010];
int len2[50010];
priority_queue<pii, vector<pii>, greater<pii>> nextInLine;
vector<pii> adj[50010];
int yum[50010];
int main()
{
    int n, m, k, curN, curD, one, two, three;
    cin >> n >> m >> k;
    for(int i = 0; i < m; i ++)
    {
        cin >> one >> two >> three;
        adj[one - 1].push_back(pii(two - 1, three));
        adj[two - 1].push_back(pii(one - 1, three));
    }
    for(int i = 0; i < k; i ++)
    {
        cin >> one >> two;
        yum[one - 1] = max(yum[one - 1], two);
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
        for(int i = 0; i < adj[curN].size(); i ++)
            if(len[curN] + adj[curN][i].second < len[adj[curN][i].first])
            {
                len[adj[curN][i].first] = len[curN] + adj[curN][i].second;
                nextInLine.push(pii(len[adj[curN][i].first], adj[curN][i].first));
            }
    }
    for(int i = 0; i < n; i ++)
        len2[i] = 2000000000;
    for(int i = 0; i < n; i ++)
        if(yum[i] != 0)
        {
            nextInLine.push(pii(len[i] - yum[i], i));
            len2[i] = len[i] - yum[i];
        }
    while(!nextInLine.empty())
    {
        curD = nextInLine.top().first;
        curN = nextInLine.top().second;
        nextInLine.pop();
        for(int i = 0; i < adj[curN].size(); i ++)
            if(len2[curN] + adj[curN][i].second < len2[adj[curN][i].first])
            {
                len2[adj[curN][i].first] = len2[curN] + adj[curN][i].second;
                nextInLine.push(pii(len2[adj[curN][i].first], adj[curN][i].first));
            }
    }
    for(int i = 0; i < n - 1; i ++)
        cout << ((len[i]<len2[i])?0:1) << "\n";
}
