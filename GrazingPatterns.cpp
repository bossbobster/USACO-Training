#include <iostream>
#include <algorithm>
using namespace std;

int k, n1, n2, ans = 0;
bool visited[5][5];

void dfs(int r, int c, int idx, int cow)
{
    if(r < 0 || r >= 5 || c < 0 || c >= 5) return;
    if(visited[r][c]) return;
    if(r == 4 && c == 4 && idx == 25 - k)
    {
        ans ++; return;
    }
    visited[r][c] = true;
    dfs(r + 1, c, idx + 1, cow);
    dfs(r - 1, c, idx + 1, cow);
    dfs(r, c + 1, idx + 1, cow);
    dfs(r, c - 1, idx + 1, cow);
    visited[r][c] = false;
}

int main()
{
    cin >> k;
    for(int i = 0; i < k; i ++)
    {
        cin >> n1 >> n2;
        visited[n1 - 1][n2 - 1] = true;
    }
    dfs(0, 0, 1, 0);
    dfs(4, 4, 1, 1);
    cout << ans << endl;
}
