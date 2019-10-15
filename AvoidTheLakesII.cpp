#include <iostream>
#include <queue>
using namespace std;

void solve()
{
    struct thing
    {
        int row, column;
    };
    
    int flood[110][110];
    int inputs[10003][2];
    bool visited[110][110];
    int n, m, k, row, column, ans = 0, s = 1;
    queue<thing> nextInLine;
    cin >> n >> m >> k;
    for(int i = 0; i <= n + 5; i ++)
        for(int j = 0; j <= m + 5; j ++)
        {
            flood[i][j] = 0;
            visited[i][j] = false;
        }
    for(int i = 0; i < k; i ++)
    {
        cin >> inputs[i][0] >> inputs[i][1];
        flood[inputs[i][0]][inputs[i][1]] = 1;
    }
    for(int i = 0; i < k; i ++)
    {
        nextInLine.push({inputs[i][0], inputs[i][1]});
        s = 0;
        do
        {
            row = nextInLine.front().row;
            column = nextInLine.front().column;
            if(!flood[row][column] || visited[row][column])
            {
                nextInLine.pop();
                continue;
            }
            s ++;
            visited[row][column] = true;
            nextInLine.push({row, column + 1});
            nextInLine.push({row, column - 1});
            nextInLine.push({row + 1, column});
            nextInLine.push({row - 1, column});
            nextInLine.pop();
        }while(!nextInLine.empty());
        ans = max(ans, s);
    }
    cout << ans;
}

int main()
{
    solve();
}
