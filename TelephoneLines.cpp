#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
using namespace std;
typedef pair<int, int> pii;

int n, p, k, one, two, three, curN, curD, countEdge;
priority_queue<pii, vector<pii>, greater<pii>> nextInLine;
set<int> left[1010];
set<int> right[1010];
int len[1010];
vector<pii> adj[1010];
int bs(int l, int r)
{
    int mid = (l + r) / 2;
    if(l < r)
    {
        for(int i = 0; i <= n; i ++)
            len[i] = 2000000000;
        len[1] = 0;
        nextInLine.push(pii(0, 1));
        while(!nextInLine.empty())
        {
            curN = nextInLine.top().second;
            curD = nextInLine.top().first;
            nextInLine.pop();
            for(int i = 0; i < adj[curN].size(); i ++)
            {
                if(adj[curN][i].second > mid) countEdge = 1;
                else countEdge = 0;
                if(len[curN] + countEdge < len[adj[curN][i].first])
                {
                    len[adj[curN][i].first] = len[curN] + countEdge;
                    nextInLine.push(pii(len[adj[curN][i].first], adj[curN][i].first));
                }
            }
        }
        if(len[n] <= k) return bs(l, mid);
        if(l == r - 1) return r;
        return bs(mid, r);
    }
    return mid;
}
int main()
{
    cin >> n >> p >> k;
    for(int i = 0; i < p; i ++)
    {
        cin >> one >> two >> three;
        adj[one].push_back(pii(two, three));
        adj[two].push_back(pii(one, three));
    }
    int ans = bs(0, 2000000);
    cout << ((ans==2000000)?-1:ans) << "\n";
}
