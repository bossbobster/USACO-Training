#include <iostream>
#include <algorithm>
using namespace std;

int n, m, k, cur = 1, ans = 0;
bool visited[5][5];
char board[5][5];
void rec(int r, int c)
{
    if(r < 0 || r >= n || c < 0 || c >= m) return;
    if(board[r][c] == 'T' || visited[r][c]) return;
    if(r == 0 && c == m - 1)
    {
        if(cur <= k) ans ++;
        return;
    }
    visited[r][c] = true;
    cur ++;
    rec(r + 1, c);
    rec(r - 1, c);
    rec(r, c + 1);
    rec(r, c - 1);
    cur --;
    visited[r][c] = false;
}

int main()
{
    cin >> n >> m >> k;
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < m; j ++)
            cin >> board[i][j];
    rec(n - 1, 0);
    cout << ans << endl;
}
