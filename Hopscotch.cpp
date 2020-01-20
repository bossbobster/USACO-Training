#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

char grid[5][5];
string cur = "";
int total = 0;
bool visited[1000000];
void dfs(int r, int c, int d)
{
    if(d == 6)
    {
        if(!visited[stoi(cur)])
            total ++;
        visited[stoi(cur)] = true;
        return;
    }
    if(r < 0 || c < 0 || r >= 5 || c >= 5) return;
    cur[d] = grid[r][c];
    dfs(r + 1, c, d + 1); dfs(r - 1, c, d + 1); dfs(r, c + 1, d + 1); dfs(r, c - 1, d + 1);
}
int main()
{
    for(int i = 0; i < 5; i ++)
        for(int j = 0; j < 5; j ++)
        {
            cin >> grid[i][j];
        }
    cur += "000000";
    for(int i = 0; i < 5; i ++)
        for(int j = 0; j < 5; j ++)
        {
            cur[0] = grid[i][j];
            dfs(i, j, 0);
        }
    cout << total << endl;
}
