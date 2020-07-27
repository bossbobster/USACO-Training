#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int dp[1010][1010];
int board[1010][2];
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i ++)
        cin >> board[i][0];
    for(int i = 0; i < n; i ++)
        cin >> board[i][1];
    for(int i = 0; i < n; i ++)
    {
        if(abs(board[i][0] - board[0][1]) <= 4 || (i != 0 && dp[i - 1][0])) dp[i][0] = 1;
        if(abs(board[0][0] - board[i][1]) <= 4 || (i != 0 && dp[0][i - 1])) dp[0][i] = 1;
    }
    for(int i = 1; i < n; i ++)
        for(int j = 1; j < n; j ++)
        {
            dp[i][j] = max(dp[i][j], max(dp[i - 1][j], dp[i][j - 1]));
            if(abs(board[i][0] - board[j][1]) <= 4)
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
        }
    cout << dp[n - 1][n - 1] << "\n";
}
