#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> pii;

struct st
{
    int r, c, d;
};
struct robot
{
    int r, c, tim, size;
};
struct countAns
{
    int r, c, rem;
    bool operator<(const countAns& other) const
    {
        return rem < other.rem;
    }
};

string board[1010];
int dist[1010][1010];
bool visited[1010][1010];
bool possible[1010][1010];
int maxN[1010][1010];
queue<st> nextInLine;
queue<robot> q;
priority_queue<countAns, vector<countAns>, less<countAns>> que;
int main()
{
    int n, d, curR, curC, curD, curS, ans = 0;
    cin >> n >> d;
    for(int i = 0; i < n; i ++)
        cin >> board[i];
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < n; j ++)
        {
            if(board[i][j] == '#')
                nextInLine.push({i, j, 0});
            if(board[i][j] == 'S')
                q.push({i, j, 0, 1});
        }
    while(!nextInLine.empty())
    {
        curR = nextInLine.front().r;
        curC = nextInLine.front().c;
        curD = nextInLine.front().d;
        nextInLine.pop();
        if(curR < 0 || curR >= n || curC < 0 || curC >= n) continue;
        if(visited[curR][curC]) continue;
        visited[curR][curC] = true;
        dist[curR][curC] = curD;
        nextInLine.push({curR + 1, curC, curD + 1});
        nextInLine.push({curR - 1, curC, curD + 1});
        nextInLine.push({curR, curC + 1, curD + 1});
        nextInLine.push({curR, curC - 1, curD + 1});
    }
    while(!q.empty())
    {
        curR = q.front().r;
        curC = q.front().c;
        curD = q.front().tim;
        curS = q.front().size;
        q.pop();
        if(maxN[curR][curC] != 0) continue;
        if(curR < 0 || curR >= n || curC < 0 || curC >= n) continue;
        if(curD % d == 0 && curD != 0) curS ++;
        maxN[curR][curC] = dist[curR][curC];
        if(dist[curR][curC] < curS) continue;
        q.push({curR + 1, curC, curD + 1, curS});
        q.push({curR - 1, curC, curD + 1, curS});
        q.push({curR, curC + 1, curD + 1, curS});
        q.push({curR, curC - 1, curD + 1, curS});
    }
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < n; j ++)
            if(maxN[i][j] > 0)
                que.push({i, j, maxN[i][j]});
    while(!que.empty())
    {
        curR = que.top().r;
        curC = que.top().c;
        curD = que.top().rem;
        que.pop();
        if(curR < 0 || curR >= n || curC < 0 || curC >= n) continue;
        if(possible[curR][curC]) continue;
        if(curD == 0) continue;
        possible[curR][curC] = true;
        ans ++;
        que.push({curR + 1, curC, curD - 1});
        que.push({curR - 1, curC, curD - 1});
        que.push({curR, curC + 1, curD - 1});
        que.push({curR, curC - 1, curD - 1});
    }
    cout << ans << "\n";
}
