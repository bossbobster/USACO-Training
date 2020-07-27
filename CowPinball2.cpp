#include <iostream>
#include <algorithm>
using namespace std;

int board[110][110];
int main()
{
    int n, ans = 0;
    cin >> n;
    for(int i = 0; i < n; i ++)
        for(int j = 0; j <= i; j ++)
            cin >> board[i][j];
    for(int i = 1; i < n; i ++)
        for(int j = 0; j <= i; j ++)
        {
            if(j == 0) board[i][j] += board[i - 1][j];
            else if(j == i) board[i][j] += board[i - 1][j - 1];
            else board[i][j] += max(board[i - 1][j], board[i - 1][j - 1]);
            if(i == n - 1) ans = max(ans, board[i][j]);
        }
    cout << ans << "\n";
}
