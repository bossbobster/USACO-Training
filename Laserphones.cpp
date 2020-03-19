#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct coo
{
    int r, c;
};

char board[100][100];
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int steps[100][100];
queue<coo> nextInLine;
coo c, st, en;
bool done = false;
int main()
{
    st.r = -1;
    int n, m, cur;
    cin >> m >> n;
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < m; j ++)
        {
            cin >> board[i][j];
            if(board[i][j] == 'C' && st.r == -1) { st.r = i; st.c = j; }
            if(board[i][j] == 'C' && st.r != -1) { en.r = i; en.c = j; }
        }
    steps[st.r][st.c] = 1;
    nextInLine.push(st);
    while(!nextInLine.empty() && !done)
    {
        c = nextInLine.front();
        int j = c.r, k = c.c;
        cur = steps[j][k];
        for(int i = 0; i < 4; i ++)
        {
            if(done) break;
            j = c.r; k = c.c;
            while(j < n && j >= 0 && k < m && k >= 0)
            {
                if(board[j][k] == '*') break;
                if(steps[j][k] == 0)
                {
                    steps[j][k] = cur + 1;
                    nextInLine.push({j, k});
                }
                if(j == en.r && k == en.c)
                {
                    done = true; break;
                }
                j += dir[i][0]; k += dir[i][1];
            }
        }
        nextInLine.pop();
    }
    cout << steps[en.r][en.c] - 2 << endl;
}
