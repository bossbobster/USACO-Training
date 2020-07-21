#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

struct loc
{
    int r, c;
};

deque<loc> nextInLine;
bool grid[1010][1010];
int len[1010][1010];
bool inside[1010][1010];
int main()
{
    int n, row, column, r, c, edge;
    cin >> n >> column >> row;
    for(int i = 0; i < n; i ++)
    {
        cin >> c >> r;
        grid[r][c] = true;
    }
    for(int i = 0; i < 1010; i ++)
        for(int j = 0; j < 1010; j ++)
            len[i][j] = 2000000000;
    nextInLine.push_front({row, column});
    len[row][column] = 0;
    while(!nextInLine.empty())
    {
        r = nextInLine.front().r;
        c = nextInLine.front().c;
        nextInLine.pop_front();
        if(r < 0 || r > 1005 || c < 1 || c > 1005) continue;
        inside[r][c] = false;
        for(int i = -1; i <= 1; i += 2)
        {
            if(i != -1 || r != 0) 
            {
                if(grid[r + i][c]) edge = 1;
                else edge = 0;
                if(len[r + i][c] > len[r][c] + edge)
                {
                    len[r + i][c] = len[r][c] + edge;
                    if(!inside[r + i][c])
                    {
                        if(edge == 0) nextInLine.push_front({r + i, c});
                        else nextInLine.push_back({r + i, c});
                    }
                }
                inside[r + i][c] = true;
            }
            if(i != -1 || c != 0)
            {
                if(grid[r][c + i]) edge = 1;
                else edge = 0;
                if(len[r][c + i] > len[r][c] + edge)
                {
                    len[r][c + i] = len[r][c] + edge;
                    if(!inside[r][c + i])
                    {
                        if(edge == 0) nextInLine.push_front({r, c + i});
                        else nextInLine.push_back({r, c + i});
                    }
                }
                inside[r][c + i] = true;
            }
        }
    }
    cout << len[0][0] << "\n";
}
