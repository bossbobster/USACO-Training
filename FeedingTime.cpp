#include <iostream>
using namespace std;

bool lakes[750][750];
bool visited[750][750];
int n, m, ans = 0, cnt = 0;

void rec(int r, int c)
{
    if(r < 0 || r >= n || c < 0 || c >= n) return;
    cnt ++;
    visited[r][c] = true;
    if(!visited[r + 1][c] && lakes[r + 1][c]) rec(r + 1, c);
    if(!visited[r - 1][c] && lakes[r - 1][c])rec(r - 1, c);
    if(!visited[r][c + 1] && lakes[r][c + 1])rec(r, c + 1);
    if(!visited[r][c - 1] && lakes[r][c - 1])rec(r, c - 1);
    if(!visited[r + 1][c + 1] && lakes[r + 1][c + 1])rec(r + 1, c + 1);
    if(!visited[r + 1][c - 1] && lakes[r + 1][c - 1])rec(r + 1, c - 1);
    if(!visited[r - 1][c + 1] && lakes[r - 1][c + 1])rec(r - 1, c + 1);
    if(!visited[r - 1][c - 1] && lakes[r - 1][c - 1])rec(r - 1, c - 1);
}

int main()
{
    char c;
    cin >> m >> n;
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < m; j ++)
        {
            cin >> c;
            if(c == '.') lakes[i][j] = true;
            else lakes[i][j] = false;
        }
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < m; j ++)
        {
            if(visited[i][j] || !lakes[i][j]) continue;
            cnt = 0;
            rec(i, j);
            ans = max(ans, cnt);
        }
    cout << ans << endl;    
}
