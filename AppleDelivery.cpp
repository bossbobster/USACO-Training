#include <iostream>
#include <algorithm>
#include <math.h>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int, int> pii;

int lens[100010];
int len1[100010];
priority_queue<pii, vector<pii>, greater<pii>> nextInLine;
vector<pii> adj[100010];
int main()
{
    int c, p, pb, pa1, pa2, curN, curD, one, two, three;
    cin >> c >> p >> pb >> pa1 >> pa2;
    for(int i = 0; i < c; i ++)
    {
        cin >> one >> two >> three;
        adj[one].push_back(pii(two, three));
        adj[two].push_back(pii(one, three));
    }
    for(int i = 0; i <= p; i ++)
        lens[i] = len1[i] = 2000000000;
    nextInLine.push(pii(0, pb));
    lens[pb] = 0;
    while(!nextInLine.empty())
    {
        curD = nextInLine.top().first;
        curN = nextInLine.top().second;
        nextInLine.pop();
        for(int i = 0; i < adj[curN].size(); i ++)
            if(lens[curN] + adj[curN][i].second < lens[adj[curN][i].first])
            {
                lens[adj[curN][i].first] = lens[curN] + adj[curN][i].second;
                nextInLine.push(pii(lens[adj[curN][i].first], adj[curN][i].first));
            }
    }
    nextInLine.push(pii(0, pa1));
    len1[pa1] = 0;
    while(!nextInLine.empty())
    {
        curD = nextInLine.top().first;
        curN = nextInLine.top().second;
        nextInLine.pop();
        for(int i = 0; i < adj[curN].size(); i ++)
            if(len1[curN] + adj[curN][i].second < len1[adj[curN][i].first])
            {
                len1[adj[curN][i].first] = len1[curN] + adj[curN][i].second;
                nextInLine.push(pii(len1[adj[curN][i].first], adj[curN][i].first));
            }
    }
    cout << min(lens[pa1] + len1[pa2], lens[pa2] + len1[pa2]) << "\n";
}
