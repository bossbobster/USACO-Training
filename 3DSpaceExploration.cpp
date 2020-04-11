#include <iostream>
#include <queue>
using namespace std;

void solve()
{
    struct thing
    {
        int row, column, z;
    };
    
    bool flood[120][120][120];
    bool visited[120][120][120];
    char ch;
    int n, row, column, z, totalN = 0;
    queue<thing> nextInLine;
    cin >> n;
    for(int i = 0; i <= n + 5; i ++)
        for(int j = 0; j <= n + 5; j ++)
            for(int k = 0; k <= n + 5; k ++)
            {
                flood[i][j][k] = false;
                visited[i][j][k] = false;
            }
    for(int i = 1; i <= n; i ++)
    {
        for(int j = 1; j <= n; j ++)
        {
            for(int k = 1; k <= n; k ++)
            {
                cin >> ch;
                if(ch == '*')
                    flood[i][j][k] = true;
            }
        }
    }
    for(int i = 1; i <= n; i ++)
    {
        for(int j = 1; j <= n; j ++)
        {
            for(int k = 1; k <= n; k ++)
            {
                if(!flood[i][j][k])
                    continue;
                nextInLine.push({i, j, k});
                do
                {
                    row = nextInLine.front().row;
                    column = nextInLine.front().column;
                    z = nextInLine.front().z;
                    if(!flood[row][column][z] || visited[row][column][z])
                    {
                        nextInLine.pop();
                        continue;
                    }
                    if(row == i && column == j && z == k)
                        totalN ++;
                    visited[row][column][z] = true;
                    nextInLine.push({row, column + 1, z});
                    nextInLine.push({row, column - 1, z});
                    nextInLine.push({row + 1, column, z});
                    nextInLine.push({row - 1, column, z});
                    nextInLine.push({row, column, z + 1});
                    nextInLine.push({row, column, z - 1});
                    nextInLine.pop();
                }while(!nextInLine.empty());
            }
        }
    }
    cout << totalN;
}

int main()
{
    solve();
}
