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
    int n, m, row = 0, column = 0, d = 0, totalN = 0, targetR, targetC;
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
            if(ch == '.')
                flood[i][j] = true;
            if(ch == 'C')
            {
                row = i;
                flood[i][j] = true;
                column = j;
            }
            if(ch == 'B')
            {
                targetR = i;
                flood[i][j] = true;
                targetC = j;
            }
        }
    }
    nextInLine.push({row, column, 0});
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
        if(row == targetR && column == targetC)
        {
            totalN = nextInLine.front().d;
            break;
        }
        if(nextInLine.front().d != d)
            d ++;
        visited[row][column] = true;
        nextInLine.push({row + 1, column, d + 1});
        nextInLine.push({row - 1, column, d + 1});
        nextInLine.push({row, column + 1, d + 1});
        nextInLine.push({row, column - 1, d + 1});
        nextInLine.pop();
    }while(!nextInLine.empty());
    cout << totalN;
}
