#include <iostream>
using namespace std;

int hashF(char c1, char c2)
{
    return (c1 - 'A') * 26 + (c2 - 'A');
}

int cnt[676];
char board[60][60];
int main()
{
    int n, m, max = 0;
    cin >> n >> m;
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < m; j ++)
            cin >> board[i][j];
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < m; j ++)
            for(int dx = -1; dx <= 1; dx ++)
                for(int dy = -1; dy <= 1; dy ++)
                {
                    if(dx == 0 && dy == 0)
                        continue;
                    if(i + (2 * dx) < n && i + (2 * dx) >= 0 && j + (2 * dy) < m && j + (2 * dy) >= 0)
                        if(board[i + dx][j + dy] == board[i + (dx * 2)][j + (dy * 2)] && board[i + dx][j + dy] != board[i][j] && board[i][j] != 'M' && board[i + dx][j + dy] != 'O')
                            cnt[hashF(board[i][j], board[i + dx][j + dy])] ++;
                }
    for(int i = 0; i < 676; i ++)
        if(cnt[i] > max)
            max = cnt[i];
    cout << max;
}
