//WITHOUT MAIN FUNCTION

int n, m, startR, startC;
string maze[1000];
bool visited[1000][1000];
bool done = false;
string ans;

void dfs(int r, int c, string cur)
{
    if(done) return;
    if(r < 0 || r >= n || c < 0 || c >= m) return;
    if(maze[r][c] == '#') return;
    if(visited[r][c]) return;
    visited[r][c] = true;
    if(maze[r][c] == 'F')
    {
        done = true; ans = cur;
        return;
    }
    if(r < n - 1) if(!visited[r + 1][c]) dfs(r + 1, c, cur + "D");
    if(done) return;
    if(r > 0) if(!visited[r - 1][c]) dfs(r - 1, c, cur + "U");
    if(done) return;
    if(c < m - 1) if(!visited[r][c + 1]) dfs(r, c + 1, cur + "R");
    if(done) return;
    if(c > 0) if(!visited[r][c - 1]) dfs(r, c - 1, cur + "L");
    return;
}

string solve()
{
    cin >> n >> m;
    for(int i = 0; i < n; i ++)
    {
        cin >> maze[i];
        for(int j = 0; j < m; j ++)
            if(maze[i][j] == 'S')
            {
                startR = i; startC = j;
            }
    }
    dfs(startR, startC, "");
    return ans;
}
