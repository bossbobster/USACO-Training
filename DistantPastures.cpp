#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

ifstream fin("distant.in");
ofstream fout("distant.out");

struct thing
{
    int row, column, length;
    bool operator<(const thing& other) const
    {
        return length > other.length;
    }
};

short flood[110][110];
bool visited[110][110];
int target[35][35];

int main()
{
    char ch;
    int n, a, b, row, column, maxN = 0, curN = 0;
    priority_queue<thing> nextInLine;
    fin >> n >> a >> b;
    for(int i = 0; i <= n + 5; i ++)
        for(int j = 0; j <= n + 5; j ++)
        {
            flood[i][j] = 0;
            visited[i][j] = false;
        }
    for(int i = 1; i <= n; i ++)
    {
        for(int j = 1; j <= n; j ++)
        {
            fin >> ch;
            if(ch == '(')
                flood[i][j] = 1;
            else
                flood[i][j] = -1;
        }
    }
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= n; j ++)
        {
            curN = 0;
            for(int k = 0; k < n + 5; k ++)
                for(int l = 0; l < n + 5; l ++)
                {
                    visited[k][l] = false;
                    target[k][l] = 2000000000;
                }
            nextInLine.push({i, j, curN});
            do
            {
                row = nextInLine.top().row;
                column = nextInLine.top().column;
                curN = nextInLine.top().length;
                if(flood[row][column] == 0 || visited[row][column])
                {
                    nextInLine.pop();
                    continue;
                }
                target[row][column] = min(target[row][column], curN);
                visited[row][column] = true;
                nextInLine.pop();
                if(flood[row][column] != flood[row + 1][column])
                    nextInLine.push({row + 1, column, curN + b});
                else nextInLine.push({row + 1, column, curN + a});
                if(flood[row][column] != flood[row - 1][column])
                    nextInLine.push({row - 1, column, curN + b});
                else nextInLine.push({row - 1, column, curN + a});
                if(flood[row][column] != flood[row][column + 1])
                    nextInLine.push({row, column + 1, curN + b});
                else nextInLine.push({row, column + 1, curN + a});
                if(flood[row][column] != flood[row][column - 1])
                    nextInLine.push({row, column - 1, curN + b});
                else nextInLine.push({row, column - 1, curN + a});
            }while(!nextInLine.empty());
            for(int k = 1; k <= n; k ++)
                for(int l = 1; l <= n; l ++)
                    maxN = max(maxN, target[k][l]);
        }
    fout << maxN << endl;
}
