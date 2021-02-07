#include <iostream>
#include <fstream>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;

ifstream fin("fortmoo.in");
ofstream fout("fortmoo.out");

string board[210];
bool pos[210][210][210]; // if its possible to make segment at y = i from x = j to x = k
int main()
{
    int n, m, ans = 0, pre;
    fin >> n >> m;
    for(int i = 0; i < n; i ++)
        fin >> board[i];
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < m; j ++)
            if(board[i][j] != 'X')
                pos[i][j][j] = 1;
    for(int i = 0; i < n; i ++)
        for(int j = 1; j < m; j ++)
            for(int k = 0; k < m - j; k ++)
                if(pos[i][k][k + j - 1] && pos[i][k + 1][k + j])
                    pos[i][k][k + j] = true;
    for(int i = 0; i < m; i ++)
        for(int j = i; j < m; j ++)
        {
            pre = 0;
            while(!pos[pre][i][j] && pre < n) pre ++;
            if(pre >= n) continue;
            for(int k = pre; k < n; k ++)
            {
                if(board[k][i] == 'X' || board[k][j] == 'X') { pre = k + 1; continue; }
                if(!pos[k][i][j]) { if(pre == k) {pre = k + 1;} continue; }
                ans = max(ans, (j - i + 1) * (k - pre + 1));
            }
        }
    fout << ans << "\n";
    return 0;
}
