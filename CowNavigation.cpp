#include <iostream>
#include <iomanip>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
#define max(n, m) ((n>m)?n:m)
#define min(n, m) ((n<m)?n:m)
#define f first
#define s second

struct st
{
    int x1, y1, d1, x2, y2, d2, d;
};

bool board[30][30];
bool visited[21][21][4][21][21][4];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
queue<st> nextInLine;
int main()
{
    int n, curX1, curY1, curD1, curX2, curY2, curD2, curD, newD1, newD2, ans = 0;
    string b;
    cin >> n;
    for(int i = 0; i < n; i ++)
    {
        cin >> b;
        for(int j = 0; j < n; j ++)
            if(b[j] == 'H')
                board[j][n - i - 1] = true;
    }
    nextInLine.push({0, 0, 0, 0, 0, 1, 0});
    while(!nextInLine.empty())
    {
        curX1 = nextInLine.front().x1; curY1 = nextInLine.front().y1; curD1 = nextInLine.front().d1;
        curX2 = nextInLine.front().x2; curY2 = nextInLine.front().y2; curD2 = nextInLine.front().d2;
        curD = nextInLine.front().d;
        nextInLine.pop();
        if(visited[curX1][curY1][curD1][curX2][curY2][curD2]) continue;
        visited[curX1][curY1][curD1][curX2][curY2][curD2] = true;
        if(curX1 == n - 1 && curY1 == n - 1 && curX2 == n - 1 && curY2 == n - 1) { ans = curD; break; }
        if(curX1 == n - 1 && curY1 == n - 1) newD1 = 0;
        else newD1 = (curD1 + 1) % 4;
        if(curX2 == n - 1 && curY2 == n - 1) newD2 = 0;
        else newD2 = (curD2 + 1) % 4;
        nextInLine.push({curX1, curY1, newD1, curX2, curY2, newD2, curD + 1});
        if(curX1 == n - 1 && curY1 == n - 1) newD1 = 0;
        else newD1 = (((curD1 - 1)==-1)?3:curD1 - 1);
        if(curX2 == n - 1 && curY2 == n - 1) newD2 = 0;
        else newD2 = (((curD2 - 1)==-1)?3:curD2 - 1);
        nextInLine.push({curX1, curY1, newD1, curX2, curY2, newD2, curD + 1});
        if(curX1 + dx[curD1] >= 0 && curX1 + dx[curD1] < n && curY1 + dy[curD1] >= 0 && curY1 + dy[curD1] < n && !board[curX1 + dx[curD1]][curY1 + dy[curD1]]) { curX1 += dx[curD1]; curY1 += dy[curD1]; }
        if(curX2 + dx[curD2] >= 0 && curX2 + dx[curD2] < n && curY2 + dy[curD2] >= 0 && curY2 + dy[curD2] < n && !board[curX2 + dx[curD2]][curY2 + dy[curD2]]) { curX2 += dx[curD2]; curY2 += dy[curD2]; }
        nextInLine.push({curX1, curY1, curD1, curX2, curY2, curD2, curD + 1});
        
    }
    cout << ans << "\n";
}
