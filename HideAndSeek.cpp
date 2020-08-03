#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int, int> pii;

queue<pii> nextInLine;
vector<int> adj[50010];
bool visited[50010];
int main()
{
    int n, m, one, two, curN, curD, small = 2000000000, dist = 0, cnt = 0;
    cin >> n >> m;
    for(int i = 0; i < m; i ++)
    {
        cin >> one >> two;
        adj[one].push_back(two);
        adj[two].push_back(one);
    }
    nextInLine.push(pii(1, 0));
    while(!nextInLine.empty())
    {
        curN = nextInLine.front().first;
        curD = nextInLine.front().second;
        nextInLine.pop();
        if(visited[curN]) continue;
        visited[curN] = true;
        if(curD > dist) { dist = curD; cnt = 0; small = 2000000000; }
        if(curD == dist)
        {
            if(curN < small) small = curN;
            cnt ++;
        }
        for(int i = 0; i < adj[curN].size(); i ++)
            nextInLine.push(pii(adj[curN][i], curD + 1));
    }
    cout << small << " " << dist << " " << cnt << "\n";
}
