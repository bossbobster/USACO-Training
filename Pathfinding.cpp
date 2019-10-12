#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <bitset>
using namespace std;

int n, m;
int visit[110][110];
vector<int> ans[110];
queue<pair<int, int>> nextInLine;
bitset<102> already;

class TT
{
public:
    int val, depth;
    TT()
    {
        val = 0;
        depth = 0;
    }
    void calcNextLev(int v, int d)
    {
        do
        {
            already[v] = true;
            ans[d].push_back(v);
            if(!nextInLine.empty())
                nextInLine.pop();
            else
                if(d != 0)
                    return;
            for(int i = 1; i <= n; i ++)
                if(visit[v][i] && !already[i])
                {
                    already[i] = true;
                    nextInLine.push(pair<int, int>(i, d + 1));
                }
            v = nextInLine.front().first;
            d = nextInLine.front().second;
        }   while(!nextInLine.empty());
    }
};

int main()
{
    cin >> n >> m;
    TT *tree = new TT;
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= n; j ++)
            cin >> visit[i][j];
    tree->calcNextLev(m, 0);
    for(int i = 0; i < 100; i ++)
    {
        if(!ans[i].empty())
        {
            sort(ans[i].begin(), ans[i].end());
            for(int j = 0; j < ans[i].size(); j ++)
                cout << ans[i][j] << " ";
            cout << endl;
        }
    }
}
