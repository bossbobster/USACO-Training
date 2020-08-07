#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;
typedef pair<int, int> pii;

double maxDub(double l1, double l2)
{
    return (l1 > l2)?l1:l2;
}
double minDub(double l1, double l2)
{
    return (l1 < l2)?l1:l2;
}
string curS;
int n, cur, curCC = 0;
double ans = 2000000000;
int matrix[160][160];
pii coo[160];
vector<pii> adj[160];
int cc[160];
queue<int> nextInLine;
bool visited[160];
vector<int> com[160];
double dis[160][160][160];
double maxD[160][160];
double dist(int i, int j)
{
    return ((coo[i].first - coo[j].first) * (coo[i].first - coo[j].first)) + ((coo[i].second - coo[j].second) * (coo[i].second - coo[j].second));
}
void fw(int type)
{
    for(int i = 0; i < com[type].size(); i ++)
        for(int j = 0; j < com[type].size(); j ++)
        {
            if(matrix[com[type][i]][com[type][j]])
                dis[type][i][j] = sqrt(dist(com[type][i], com[type][j]));
            else dis[type][i][j] = 2000000000;
        }
    for(int k = 0; k < com[type].size(); k ++)
        for(int i = 0; i < com[type].size(); i ++)
            for(int j = 0; j < com[type].size(); j ++)
                dis[type][i][j] = minDub(dis[type][i][j], dis[type][i][k] + dis[type][k][j]);
    for(int i = 0; i < com[type].size(); i ++)
        for(int j = 0; j < com[type].size(); j ++)
            if(i != j)
                maxD[type][i] = maxDub(maxD[type][i], dis[type][i][j]);
}
int main()
{
    cin >> n;
    for(int i = 0; i < n; i ++)
        cin >> coo[i].first >> coo[i].second;
    for(int i = 0; i < n; i ++)
    {
        cin >> curS;
        for(int j = 0; j < n; j ++)
        {
            matrix[i][j] = curS[j] - '0';
            if(curS[j] == '1')
                adj[i].push_back(pii(j, dist(i, j)));
        }
    }
    for(int i = 0; i < n; i ++)
    {
        if(visited[i]) continue;
        curCC ++;
        nextInLine.push(i);
        while(!nextInLine.empty())
        {
            cur = nextInLine.front();
            nextInLine.pop();
            if(visited[cur]) continue;
            visited[cur] = true;
            cc[cur] = curCC;
            for(int i = 0; i < adj[cur].size(); i ++)
                nextInLine.push(adj[cur][i].first);
        }
    }
    for(int i = 0; i < n; i ++)
        com[cc[i] - 1].push_back(i);
    for(int i = 0; i < curCC; i ++)
        fw(i);
    for(int k = 0; k < curCC - 1; k ++)
        for(int l = k + 1; l < curCC; l ++)
            for(int i = 0; i < com[k].size(); i ++)
                for(int j = 0; j < com[l].size(); j ++)
                    ans = min(ans, (maxD[k][i] + maxD[l][j] + sqrt((double)dist(com[k][i], com[l][j]))));
    for(int i = 0; i < curCC - 1; i ++)
        for(int j = 0; j < com[i].size(); j ++)
            ans = max(ans, maxD[i][j]);
    cout << setprecision(6) << fixed;
    cout << ans << "\n";
}
