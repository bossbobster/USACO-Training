#include <iostream>
#include <algorithm>
using namespace std;

int n, m, minN = 2000000000, curN;
bool grid[20][20];
bool og[20][20];
bool changed[20][20];
bool ans[20][20];
bool done = false;
void rec(int r, int c)
{
    if(c == m) return rec(r + 1, 0);
    if(r == n)
    {
        curN = 0;
        for(int i = 0; i < n; i ++)
            for(int j = 0; j < m; j ++)
                if(grid[i][j] != 0)
                    return;
        for(int i = 0; i < n; i ++)
            for(int j = 0; j < m; j ++)
                curN += changed[i][j];
        if(curN < minN)
        {
            minN = curN;
            for(int i = 0; i < n; i ++)
                for(int j = 0; j < m; j ++)
                    ans[i][j] = changed[i][j];
        }
        done = true;
        return;
    }
    if(r == 0)
    {
        changed[r][c] = 0;
        rec(r, c + 1);
        changed[r][c] = 1;
        grid[r][c] = !grid[r][c];
        if(r - 1 >= 0) grid[r - 1][c] = !grid[r - 1][c];
        if(r + 1 < n) grid[r + 1][c] = !grid[r + 1][c];
        if(c - 1 >= 0) grid[r][c - 1] = !grid[r][c - 1];
        if(c + 1 < m) grid[r][c + 1] = !grid[r][c + 1];
        rec(r, c + 1);
        grid[r][c] = !grid[r][c];
        if(r - 1 >= 0) grid[r - 1][c] = !grid[r - 1][c];
        if(r + 1 < n) grid[r + 1][c] = !grid[r + 1][c];
        if(c - 1 >= 0) grid[r][c - 1] = !grid[r][c - 1];
        if(c + 1 < m) grid[r][c + 1] = !grid[r][c + 1];
    }
    else
    {
        if(c != 0)
        {
            if(grid[r - 1][c] == 1)
                changed[r][c] = 1;
            else
                changed[r][c] = 0;
        }
        else
        {
            if(grid[r - 1][c] == 1)
                changed[r][c] = 1;
            else
                changed[r][c] = 0;
        }
        if(changed[r][c] == 1)
        {
            grid[r][c] = !grid[r][c];
            if(r - 1 >= 0) grid[r - 1][c] = !grid[r - 1][c];
            if(r + 1 < n) grid[r + 1][c] = !grid[r + 1][c];
            if(c - 1 >= 0) grid[r][c - 1] = !grid[r][c - 1];
            if(c + 1 < m) grid[r][c + 1] = !grid[r][c + 1];
        }
        rec(r, c + 1);
        if(changed[r][c] == 1)
        {
            grid[r][c] = !grid[r][c];
            if(r - 1 >= 0) grid[r - 1][c] = !grid[r - 1][c];
            if(r + 1 < n) grid[r + 1][c] = !grid[r + 1][c];
            if(c - 1 >= 0) grid[r][c - 1] = !grid[r][c - 1];
            if(c + 1 < m) grid[r][c + 1] = !grid[r][c + 1];
        }
    }
}
int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < m; j ++)
        {
            cin >> grid[i][j];
            og[i][j] = grid[i][j];
        }
    rec(0, 0);
    if(!done) cout << "IMPOSSIBLE" << "\n";
    else
        for(int i = 0; i < n; i ++)
        {
            for(int j = 0; j < m; j ++)
                cout << ans[i][j] << " ";
            cout << "\n";
        }
}
