#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

vector<int> adj[1010];
queue<int> nextInLine;
bool visited[1010];
int com[1010];
int main()
{
    int n, m, q, one, two, curComp = 0, cur;
    cin >> n >> m >> q;
    for(int i = 0; i < m; i ++)
    {
        cin >> one >> two;
        adj[one].push_back(two);
        adj[two].push_back(one);
    }
    for(int i = 1; i <= n; i ++)
        if(!visited[i])
        {
            curComp ++;
            nextInLine.push(i);
            while(!nextInLine.empty())
            {
                cur = nextInLine.front();
                nextInLine.pop();
                if(visited[cur]) continue;
                visited[cur] = true;
                com[cur] = curComp;
                for(int j = 0; j < adj[cur].size(); j ++)
                    nextInLine.push(adj[cur][j]);
            }
        }
    for(int i = 0; i < q; i ++)
    {
        cin >> one >> two;
        if(com[one] == com[two]) cout << "Y" << "\n";
        else cout << "N" << "\n";
    }
}
