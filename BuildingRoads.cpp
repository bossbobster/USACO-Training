#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <math.h>
#include <set>
#include <vector>
using namespace std;
typedef pair<int, double> pid;

double points[1010][2];
int roads[1010][2];
bool alr[1010][1010];
vector<pid> adj[1010];
double minDist[1010];
bool finalized[1010];
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
                long long first = (points[i][0] - points[j][0]) * (points[i][0] - points[j][0]);
                long long second = (points[i][1] - points[j][1]) * (points[i][1] - points[j][1]);
                double dist = sqrt((double)first + (double)second);
                adj[i].push_back(pid(j, dist));
                adj[j].push_back(pid(i, dist));
            }
    for(int i = 1; i <= n; i ++)
    {
        minDist[i] = 2000000000;
        finalized[i] = false;
    }
    minDist[1] = 0;
    for(int i = 0; i < n; i ++)
    {
        curD = 2000000000;
        for(int j = 1; j <= n; j ++)
            if(minDist[j] < curD)
            {
                if(finalized[j]) continue;
                curD = minDist[j];
                curN = j;
            }
        finalized[curN] = true;
        for(int j = 0; j < adj[curN].size(); j ++)
        {
            if(finalized[adj[curN][j].first]) continue;
            if(adj[curN][j].second < minDist[adj[curN][j].first])
                minDist[adj[curN][j].first] = adj[curN][j].second;
        }
    }
    for(int i = 1; i <= n; i ++)
        ans += minDist[i];
    cout << fixed;
    cout << setprecision(2);
    cout << ans << "\n";
}
