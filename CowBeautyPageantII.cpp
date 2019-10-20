#include <iostream>
#include <queue>
using namespace std;

void solve()
{
    struct thing
    {
        int row, column;
    };
    
    bool flood[60][60];
    bool visited[60][60];
    thing one[2500];
    thing two[2500];
    char ch;
    int n, m, row, column, total = 100000, num = 0, idx1 = 0, idx2 = 0;
    bool already = false;
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
            cin >> ch;
            if(ch == 'X')
                flood[i][j] = true;
        }
    }
    for(int i = 1; i <= n; i ++)
    {
        for(int j = 1; j <= m; j ++)
        {
            if(!flood[i][j])
                continue;
            nextInLine.push({i, j});
            already = false;
            do
            {
                row = nextInLine.front().row;
                column = nextInLine.front().column;
                if(!flood[row][column] || visited[row][column])
                {
                    nextInLine.pop();
                    continue;
                }
                if(!already)
                {
                    num ++;
                    already = true;
                }
                visited[row][column] = true;
                if(num == 1)
                {
                    one[idx1].row = row;
                    one[idx1].column = column;
                    idx1 ++;
                }
                else
                {
                    two[idx2].row = row;
                    two[idx2].column = column;
                    idx2 ++;
                }
                nextInLine.push({row, column + 1});
                nextInLine.push({row, column - 1});
                nextInLine.push({row + 1, column});
                nextInLine.push({row - 1, column});
                nextInLine.pop();
            }while(!nextInLine.empty());
        }
    }
    for(int i = 0; i < idx1; i ++)
        for(int j = 0; j < idx2; j ++)
            if(abs(one[i].row - two[j].row) + abs(one[i].column - two[j].column) < total)
                total = abs(one[i].row - two[j].row) + abs(one[i].column - two[j].column);
    cout << total - 1;
}

int main()
{
    solve();
}
