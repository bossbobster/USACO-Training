#include <iostream>
#include <algorithm>
using namespace std;

int n;
short board[10][10];
int maxSum = 0;
void findMax(int r, int c, int sum)
{
    if(r == 0 && c == n - 1)
        maxSum = max(sum + board[r][c], maxSum);
    if(r < 0 || c >= n)
        return;
    sum += board[r][c];
    findMax(r - 1, c, sum);
    findMax(r, c + 1, sum);
}

int main()
{
    char num, useless;
    cin >> n;
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < n; j ++)
        {
            cin >> num >> useless;
            if(num <= '9')
                board[i][j] = num - '0';
            if(num == 'A') board[i][j] = 1;
            if(num == 'T') board[i][j] = 10;
            if(num == 'J') board[i][j] = 11;
            if(num == 'Q') board[i][j] = 12;
            if(num == 'K') board[i][j] = 13;
        }
    findMax(n - 1, 0, 0);
    cout << maxSum;
}
