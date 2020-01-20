//NOT USACO PROBLEM
#include <iostream>
#include <algorithm>
using namespace std;

bool board[20][20];
int total = 0;
int n;
void printAll(int n1)
{
    if(n1 == 0)
    {
        total ++;
        return;
    }
    bool previous[20][20];
    for(int j = 0; j < n; j ++)
    {
        if(board[n - n1][j]) continue;
        for(int k = 0; k < n; k ++)
            for(int l = 0; l < n; l ++)
                previous[k][l] = board[k][l];
        for(int k = 0; k < n; k ++) board[n - n1][k] = true;
        for(int k = 0; k < n; k ++) board[k][j] = true;
        for(int k = -min(n - n1, j); k < n - max(n - n1, j); k ++) board[n - n1 + k][j + k] = true;
        for(int k = -min(n1, j + 1) + 1; k < min(n - n1 + 1, n - j); k ++) board[n - n1 - k][j + k] = true;
        printAll(n1 - 1);
        for(int k = 0; k < n; k ++)
            for(int l = 0; l < n; l ++)
                board[k][l] = previous[k][l];
    }
}
int main()
{
    cin >> n;
    printAll(n);
    cout << total << endl;
}
