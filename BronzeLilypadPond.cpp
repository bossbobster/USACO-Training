#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct coo
{
    int r, c, d;
};

int board[30][30];
bool visited[30][30];
queue<coo> nextInLine;
int main()
{
    int n, m, n1, m1, r, c, d;
    cin >> n >> m >> n1 >> m1;
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < m; j ++)
        {
            cin >> board[i][j];
            if(board[i][j] == 3) nextInLine.push({i, j, 0});
        }
    while(!nextInLine.empty())
    {
        r = nextInLine.front().r;
        c = nextInLine.front().c;
        d = nextInLine.front().d;
        if(r < 0 || r >= n || c < 0 || c >= m) { nextInLine.pop(); continue; }
        if(board[r][c] == 0 || board[r][c] == 2 || visited[r][c]) { nextInLine.pop(); continue; }
        visited[r][c] = true;
        if(board[r][c] == 4)
        {
            cout << d << endl;
            break;
        }
        nextInLine.push({r + n1, c + m1, d + 1});
        nextInLine.push({r - n1, c + m1, d + 1});
        nextInLine.push({r + n1, c - m1, d + 1});
        nextInLine.push({r - n1, c - m1, d + 1});
        nextInLine.push({r + m1, c + n1, d + 1});
        nextInLine.push({r - m1, c + n1, d + 1});
        nextInLine.push({r + m1, c - n1, d + 1});
        nextInLine.push({r - m1, c - n1, d + 1});
        nextInLine.pop();
    }
}
