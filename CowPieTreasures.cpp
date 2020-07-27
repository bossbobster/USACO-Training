#include <iostream>
#include <algorithm>
using namespace std;

int dp[110][110];
int board[110][110];
int main()
{
    int r, c;
    cin >> r >> c;
    for(int i = 0; i < r; i ++)
        for(int j = 0; j < c; j ++)
            cin >> board[i][j];
    dp[0][0] = board[0][0];
    for(int i = 1; i < r; i ++)
        dp[i][0] = -2000000000;
    for(int i = 1; i < c; i ++)
        for(int j = 0; j < r; j ++)
        {
            int cur = -2000000000;
            if(j != 0) cur = max(cur, dp[j - 1][i - 1]);
            if(j != r - 1) cur = max(cur, dp[j + 1][i - 1]);
            cur = max(cur, dp[j][i - 1]);
            dp[j][i] += cur + board[j][i];
        }
    cout << dp[r - 1][c - 1] << "\n";
}
