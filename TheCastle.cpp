#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> pii;

vector<pii> adj[60][60];
int cc[60][60];
queue<pii> nextInLine;
bool visited[60][60];
int sizes[4000];
int main()
{
    int n, m, cur, r, c, ans1 = 0, ans2 = 0, ans3 = 0, curSize;
    bool l, ri, u, d;
    cin >> m >> n;
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < m; j ++)
        {
            l = ri = u = d = true;
            cin >> cur;
            if(cur >= 8) { cur -= 8; d = false; }
            if(cur >= 4) { cur -= 4; ri = false; }
            if(cur >= 2) { cur -= 2; u = false; }
            if(cur >= 1) { cur -= 1; l = false; }
            if(d) adj[i][j].push_back(pii(i + 1, j));
            if(ri) adj[i][j].push_back(pii(i, j + 1));
            if(u) adj[i][j].push_back(pii(i - 1, j));
            if(l) adj[i][j].push_back(pii(i, j - 1));
        }
    cur = 0;
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < m; j ++)
        {
            if(visited[i][j]) continue;
            cur ++;
            curSize = 0;
            nextInLine.push(pii(i, j));
            while(!nextInLine.empty())
            {
                r = nextInLine.front().first;
                c = nextInLine.front().second;
                nextInLine.pop();
                if(visited[r][c]) continue;
                visited[r][c] = true;
                curSize ++;
                ans2 = max(ans2, curSize);
                cc[r][c] = cur;
                for(int i = 0; i < adj[r][c].size(); i ++)
                    nextInLine.push(pii(adj[r][c][i].first, adj[r][c][i].second));
            }
            sizes[cur] = curSize;
        }
    ans1 = cur;
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < m; j ++)
        {
            if(i != 0)
                if(cc[i][j] != cc[i - 1][j])
                    ans3 = max(ans3, sizes[cc[i][j]] + sizes[cc[i - 1][j]]);
            if(i != n - 1)
                if(cc[i][j] != cc[i + 1][j])
                    ans3 = max(ans3, sizes[cc[i][j]] + sizes[cc[i + 1][j]]);
            if(j != 0)
                if(cc[i][j] != cc[i][j - 1])
                    ans3 = max(ans3, sizes[cc[i][j]] + sizes[cc[i][j - 1]]);
            if(j != m - 1)
                if(cc[i][j] != cc[i][j + 1])
                    ans3 = max(ans3, sizes[cc[i][j]] + sizes[cc[i][j + 1]]);
        }
    cout << ans1 << "\n" << ans2 << "\n" << ans3 << "\n";
}
