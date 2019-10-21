#include <iostream>
#include <queue>
using namespace std;

struct thing
{
    int row, column, d;
};

bool flood[110][110];
bool visited[110][110];

int main()
{
    char ch;
    int n, m, row, column, d = 0, totalN = 0, grass = 0, milkweed = 0;
    queue<thing> nextInLine;
    cin >> m >> n >> column >> row;
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
            if(ch == '.')
            {
                flood[i][j] = true;
                grass ++;
            }
        }
    }
    nextInLine.push({n - row + 1, column, 0});
    do
    {
        row = nextInLine.front().row;
        column = nextInLine.front().column;
        if(!flood[row][column] || visited[row][column])
        {
            nextInLine.pop();
            if(nextInLine.front().d != d)
                d ++;
            continue;
        }
        milkweed ++;
        if(grass <= milkweed)
        {
            totalN = nextInLine.front().d;
            break;
        }
        if(nextInLine.front().d != d)
            d ++;
        visited[row][column] = true;
        for(int i = -1; i <= 1; i ++)
            for(int j = -1; j <= 1; j ++)
            {
                if(i == j && i == 0) continue;
                nextInLine.push({row + i, column + j, d + 1});
            }
        nextInLine.pop();
    }while(!nextInLine.empty());
    cout << totalN;
}
