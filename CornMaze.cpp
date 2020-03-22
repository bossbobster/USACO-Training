#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

struct coo
{
    int r, c, d;
};

char board[300][300];
bool visited[300][300];
vector<int> slides[26];
queue<coo> nextInLine;
int main()
{
    int n, m, r, c, d;
    cin >> n >> m;
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < m; j ++)
        {
            cin >> board[i][j];
            if(board[i][j] == '@') nextInLine.push({i, j, 0});
            if(board[i][j] >= 'A' && board[i][j] <= 'Z')
            {
                slides[board[i][j] - 'A'].push_back(i);
                slides[board[i][j] - 'A'].push_back(j);
            }
        }
    while(!nextInLine.empty())
    {
        r = nextInLine.front().r;
        c = nextInLine.front().c;
        d = nextInLine.front().d;
        if(r < 0 || r >= n || c < 0 || c >= m) { nextInLine.pop(); continue; }
        if(board[r][c] == '#' || visited[r][c]) { nextInLine.pop(); continue; }
        if(board[r][c] < 'A' || board[r][c] > 'Z') visited[r][c] = true;
        if(board[r][c] >= 'A' && board[r][c] <= 'Z')
        {
            if(r == slides[board[r][c] - 'A'][0] && c == slides[board[r][c] - 'A'][1])
            {
                int prevR = r;
                r = slides[board[r][c] - 'A'][2];
                c = slides[board[prevR][c] - 'A'][3];
            }
            else
            {
                int prevR = r;
                r = slides[board[r][c] - 'A'][0];
                c = slides[board[prevR][c] - 'A'][1];
            }
        }
        if(board[r][c] == '=')
        {
            cout << d << endl;
            break;
        }
        nextInLine.push({r + 1, c, d + 1});
        nextInLine.push({r - 1, c, d + 1});
        nextInLine.push({r, c + 1, d + 1});
        nextInLine.push({r, c - 1, d + 1});
        nextInLine.pop();
    }
}
