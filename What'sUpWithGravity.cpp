#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

struct loc
{
    int r, c, g;
};

deque<loc> nextInLine;
char grid[510][510];
int len[510][510][3];
bool inside[510][510][3];
int main()
{
    int n, m, br = 0, bc = 0, dr = 0, dc = 0, curr, curc, curg = 0;
    cin >> n >> m;
    for(int i = 0; i < n; i ++)
    {
        for(int j = 0; j < m; j ++)
        {
            cin >> grid[i][j];
            len[i][j][0] = len[i][j][2] = 2100000000;
            if(grid[i][j] == 'C') { br = i; bc = j; }
            if(grid[i][j] == 'D') { dr = i; dc = j; }
        }
    }
    nextInLine.push_back({br, bc, 1});
    len[br][bc][2] = 0;
    while(!nextInLine.empty())
    {
        curr = nextInLine.front().r;
        curc = nextInLine.front().c;
        curg = nextInLine.front().g;
        nextInLine.pop_front();
        inside[curr][curc][curg + 1] = false;
        if(grid[curr][curc] == '#') continue;
        while(true)
        {
            if(curg == -1 && curr == 0) break;
            if(curg == 1 && curr == n - 1) break;
            if(grid[curr + curg][curc] == '#') break;
            curr += curg;
            len[curr][curc][curg + 1] = min(len[curr][curc][curg + 1], len[curr - curg][curc][curg + 1]);
        }
        if(curr == 0 || curr == n - 1) continue;
        if(!inside[curr][curc + 1][curg + 1] && len[curr][curc][curg + 1] < len[curr][curc + 1][curg + 1])
        {
            len[curr][curc + 1][curg + 1] = len[curr][curc][curg + 1];
            nextInLine.push_front({curr, curc + 1, curg});
            inside[curr][curc + 1][curg + 1] = true;
        }
        if(!inside[curr][curc - 1][curg + 1] && len[curr][curc][curg + 1] < len[curr][curc - 1][curg + 1])
        {
            len[curr][curc - 1][curg + 1] = len[curr][curc][curg + 1];
            nextInLine.push_front({curr, curc - 1, curg});
            inside[curr][curc - 1][curg + 1] = true;
        }
        if(!inside[curr][curc][curg * -1 + 1] && len[curr][curc][curg + 1] + 1 < len[curr][curc][curg * -1 + 1])
        {
            len[curr][curc][curg * -1 + 1] = len[curr][curc][curg + 1] + 1;
            nextInLine.push_back({curr, curc, curg * -1});
            inside[curr][curc][curg * -1 + 1] = true;
        }
    }
    if(min(len[dr][dc][0], len[dr][dc][2]) != 2100000000) cout << min(len[dr][dc][0], len[dr][dc][2]) << "\n";
    else cout << -1 << "\n";
}
