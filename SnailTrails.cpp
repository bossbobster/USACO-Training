#include <iostream>
#include <algorithm>
#include <math.h>
#include <queue>
using namespace std;

int n, b;
bool grid[150][150];
bool visited[150][150];
int ans = 0;
void dfs(int r, int c, int cur, int dr, int dc)
{
    if(r < 0 || r >= n || c < 0 || c >= n) return;
    if(visited[r][c] || grid[r][c]) return;
    visited[r][c] = true;
    ans = max(ans, cur);
    if(r + dr == -1 || r + dr == n || c + dc == -1 || c + dc == n || grid[r + dr][c + dc])
    {
        dr = (dr + 1) % 2;
        dc = (dc + 1) % 2;
        dfs(r - dr, c - dc, cur + 1, -dr, -dc);
    }
    dfs(r + dr, c + dc, cur + 1, dr, dc);
    visited[r][c] = false;
}
int main()
{
    string cur;
    cin >> n >> b;
    for(int i = 0; i < b; i ++)
    {
        cin >> cur;
        grid[stoi(cur.substr(1, cur.length() - 1)) - 1][cur[0] - 'A'] = true;
    }
    dfs(0, 0, 0, 0, 1);
    dfs(0, 0, 0, 1, 0);
    cout << ans + 1 << "\n";
}
