#include <iostream>
#include <fstream>
#include <algorithm>
#include <math.h>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int, int> pii;

ifstream fin("timeline.in");
ofstream fout("timeline.out");

vector<pii> adj[100010];
int in[100010];
int ans[100010];
queue<int> nextInLine;
int main()
{
    int n, m, c, one, two, three, curN;
    fin >> n >> m >> c;
    for(int i = 0; i < n; i ++)
        fin >> ans[i];
    for(int i = 0; i < c; i ++)
    {
        fin >> one >> two >> three;
        adj[one - 1].push_back(pii(two - 1, three));
        in[two - 1] ++;
    }
    for(int i = 0; i < n; i ++)
        if(in[i] == 0)
            nextInLine.push(i);
    while(!nextInLine.empty())
    {
        curN = nextInLine.front();
        nextInLine.pop();
        for(int i = 0; i < adj[curN].size(); i ++)
        {
            ans[adj[curN][i].first] = max(ans[adj[curN][i].first], ans[curN] + adj[curN][i].second);
            in[adj[curN][i].first] --;
            if(in[adj[curN][i].first] == 0)
                nextInLine.push(adj[curN][i].first);
        }
    }
    for(int i = 0; i < n; i ++)
        fout << ans[i] << "\n";
}
