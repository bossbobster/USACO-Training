#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> pii;

vector<pii> adj[510];
bool finalized[510];
int minDist[510];
int totalDist[510];
int fav[510];
int main()
{
    int p, f, c, one, two, three, ans1 = 2000000000, ans2 = 0, curN, curD;
    cin >> p >> f >> c;
    for(int i = 0; i < f; i ++)
        cin >> fav[i];
    for(int i = 0; i < c; i ++)
    {
        cin >> one >> two >> three;
        adj[one].push_back(pii(two, three));
        adj[two].push_back(pii(one, three));
    }
    for(int k = 0; k < f; k ++)
    {
        for(int i = 1; i <= p; i ++)
        {
            minDist[i] = 2000000000;
            finalized[i] = false;
        }
        minDist[fav[k]] = 0;
        for(int i = 1; i <= p; i ++)
        {
            curD = 2000000000;
            for(int j = 1; j <= p; j ++)
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
                minDist[adj[curN][j].first] = min(minDist[adj[curN][j].first], minDist[curN] + adj[curN][j].second);
            }
        }
        for(int i = 1; i <= p; i ++)
            totalDist[i] += minDist[i];
    }
    for(int i = 1; i <= p; i ++)
        if(totalDist[i] < ans1)
        {
            ans1 = totalDist[i];
            ans2 = i;
        }
    cout << ans2 << "\n";
}
