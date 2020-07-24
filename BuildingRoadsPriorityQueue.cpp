#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <math.h>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int, double> pid;
typedef pair<double, int> pdi;

double points[1010][2];
int roads[1010][2];
bool alr[1010][1010];
vector<pid> adj[1010];
double minDist[1010];
bool finalized[1010];
priority_queue<pdi, vector<pdi>, greater<pdi>> nextInLine;
int main()
{
    int n, m, curN;
    double curD;
    double ans = 0;
    cin >> n >> m;
    for(int i = 1; i <= n; i ++)
        cin >> points[i][0] >> points[i][1];
    for(int i = 0; i < m; i ++)
    {
        cin >> roads[i][0] >> roads[i][1];
        if(!alr[roads[i][0]][roads[i][1]])
        {
            adj[roads[i][0]].push_back(pid(roads[i][1], 0.0));
            adj[roads[i][1]].push_back(pid(roads[i][0], 0.0));
            alr[roads[i][0]][roads[i][1]] = alr[roads[i][1]][roads[i][0]] = true;
        }
    }
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= n; j ++)
            if(!alr[i][j] && !alr[j][i])
            {
                if(i == j) continue;
                long long first = (points[i][0] - points[j][0]) * (points[i][0] - points[j][0]);
                long long second = (points[i][1] - points[j][1]) * (points[i][1] - points[j][1]);
                double dist = sqrt((double)first + (double)second);
                adj[i].push_back(pid(j, dist));
            }
    for(int i = 1; i <= n; i ++)
    {
        minDist[i] = 2000000000;
        finalized[i] = false;
    }
    minDist[1] = 0;
    nextInLine.push(pdi(0, 1));
    while(!nextInLine.empty())
    {
        curD = nextInLine.top().first;
        curN = nextInLine.top().second;
        nextInLine.pop();
        if(finalized[curN]) continue;
        if(curD > minDist[curN]) continue;
        for(int i = 0; i < adj[curN].size(); i ++)
            if(adj[curN][i].second < minDist[adj[curN][i].first] && !finalized[adj[curN][i].first])
            {
                minDist[adj[curN][i].first] = adj[curN][i].second;
                nextInLine.push(pdi(minDist[adj[curN][i].first], adj[curN][i].first));
            }
        finalized[curN] = true;
    }
    for(int i = 1; i <= n; i ++)
        ans += minDist[i];
    cout << fixed;
    cout << setprecision(2);
    cout << ans << "\n";
}
