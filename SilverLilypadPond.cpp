#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

struct place
{
    int row, col;
};
deque<place> nextInLine;
short board[40][40];
int len[40][40];
int jumps[40][40];
long long times[40][40];
bool inside[40][40];
int main()
{
    int n, m, r, c, edge, endR = 0, endC = 0;
    cin >> n >> m;
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < m; j ++)
        {
            cin >> board[i][j];
            len[i][j] = jumps[i][j] = 1000000000;
            times[i][j] = 0;
            if(board[i][j] == 3)
            {
                nextInLine.push_back({i, j});
                len[i][j] = 0;
                jumps[i][j] = 0;
                times[i][j] = 1;
            }
            if(board[i][j] == 4)
            {
                endR = i; endC = j;
            }
        }
    while(!nextInLine.empty())
    {
        r = nextInLine.front().row;
        c = nextInLine.front().col;
        inside[r][c] = false;
        nextInLine.pop_front();
        for(int i = -2; i <= 2; i += 4)
        {
            for(int j = -1; j <= 1; j += 2)
            {
                if(r + i >= 0 && r + i < n && c + j >= 0 && c + j < m)
                {
                    if(board[r + i][c + j] == 0) edge = 1;
                    else if(board[r + i][c + j] == 1 || board[r + i][c + j] == 3 || board[r + i][c + j] == 4) edge = 0;
                    else edge = 100;
                    if(edge != 100)
                    {
                        if(len[r][c] + edge < len[r + i][c + j])
                        {
                            len[r + i][c + j] = len[r][c] + edge;
                            jumps[r + i][c + j] = jumps[r][c] + 1;
                            times[r + i][c + j] = times[r][c];
                            if(!inside[r + i][c + j])
                                nextInLine.push_back({r + i, c + j});
                            inside[r + i][c + j] = true;
                        }
                        else if(len[r][c] + edge == len[r + i][c + j])
                        {
                            if(jumps[r][c] + 1 < jumps[r + i][c + j])
                            {
                                jumps[r + i][c + j] = jumps[r][c] + 1;
                                times[r + i][c + j] = times[r][c];
                                if(!inside[r + i][c + j])
                                    nextInLine.push_back({r + i, c + j});
                                inside[r + i][c + j] = true;
                            }
                            else if(jumps[r][c] + 1 == jumps[r + i][c + j])
                                times[r + i][c + j] += times[r][c];
                        }
                    }
                }
                if(c + i >= 0 && c + i < m && r + j >= 0 && r + j < n)
                {
                    if(board[r + j][c + i] == 0) edge = 1;
                    else if(board[r + j][c + i] == 1 || board[r + j][c + i] == 3 || board[r + j][c + i] == 4) edge = 0;
                    else edge = 100;
                    if(edge != 100)
                    {
                        if(len[r][c] + edge < len[r + j][c + i])
                        {
                            len[r + j][c + i] = len[r][c] + edge;
                            jumps[r + j][c + i] = jumps[r][c] + 1;
                            times[r + j][c + i] = times[r][c];
                            if(!inside[r + j][c + i])
                                nextInLine.push_back({r + j, c + i});
                            inside[r + j][c + i] = true;
                        }
                        else if(len[r][c] + edge == len[r + j][c + i])
                        {
                            if(jumps[r][c] + 1 < jumps[r + j][c + i])
                            {
                                jumps[r + j][c + i] = jumps[r][c] + 1;
                                times[r + j][c + i] = times[r][c];
                                if(!inside[r + j][c + i])
                                    nextInLine.push_back({r + j, c + i});
                                inside[r + j][c + i] = true;
                            }
                            else if(jumps[r][c] + 1 == jumps[r + j][c + i])
                                times[r + j][c + i] += times[r][c];
                        }
                    }
                }
            }
        }
    }
    if(len[endR][endC] == 1000000000)
    {
        cout << -1 << "\n";
        return 0;
    }
    cout << len[endR][endC] << "\n" << jumps[endR][endC] << "\n" << times[endR][endC] << "\n";
}
