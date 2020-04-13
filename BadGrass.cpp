#include <iostream>
#include <queue>
using namespace std;

void solve()
{
    struct thing
    {
        int row, column;
    };
    
    bool flood[1010][1010];
    bool visited[1010][1010];
    int n, m, row, column, totalN = 0, tmp;
    queue<thing> nextInLine;
    cin >> n >> m;
    for(int i = 0; i <= n + 5; i ++)
        for(int j = 0; j <= m + 5; j ++)
        {
            flood[i][j] = false;
            visited[i][j] = false;
        }
    for(int i = 1; i <= n; i ++)
    {
        for(int j = 1; j <= m; j ++)
        {
            cin >> tmp;
            if(tmp >= 1)
                flood[i][j] = true;
        }
    }
    for(int i = 1; i <= n; i ++)
    {
        for(int j = 1; j <= n; j ++)
        {
            if(!flood[i][j])
                continue;
            nextInLine.push({i, j});
            do
            {
                row = nextInLine.front().row;
                column = nextInLine.front().column;
                if(!flood[row][column] || visited[row][column])
                {
                    nextInLine.pop();
                    continue;
                }
                if(row == i && column == j)
                    totalN ++;
                visited[row][column] = true;
                nextInLine.push({row, column + 1});
                nextInLine.push({row, column - 1});
                nextInLine.push({row + 1, column});
                nextInLine.push({row - 1, column});
                nextInLine.push({row + 1, column + 1});
                nextInLine.push({row - 1, column - 1});
                nextInLine.push({row + 1, column - 1});
                nextInLine.push({row - 1, column + 1});
                nextInLine.pop();
            }while(!nextInLine.empty());
        }
    }
    cout << totalN;
}

int main()
{
    solve();
}
