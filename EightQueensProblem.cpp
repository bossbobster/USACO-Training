//NOT USACO PROBLEM
#include <iostream>
#include <algorithm>
using namespace std;

bool board[8][8];
int total = 0;
void printAll(int n)
{
    if(n == 0)
    {
        total ++;
        return;
    }
    bool previous[8][8];
    for(int j = 0; j < 8; j ++)
    {
        if(board[8 - n][j]) continue;
        for(int k = 0; k < 8; k ++)
            for(int l = 0; l < 8; l ++)
                previous[k][l] = board[k][l];
        for(int k = 0; k < 8; k ++) board[8 - n][k] = true;
        for(int k = 0; k < 8; k ++) board[k][j] = true;
        for(int k = -min(8 - n, j); k < 8 - max(8 - n, j); k ++) board[8 - n + k][j + k] = true;
        for(int k = -min(n, j + 1) + 1; k < min(9 - n, 8 - j); k ++) board[8 - n - k][j + k] = true;
        printAll(n - 1);
        for(int k = 0; k < 8; k ++)
            for(int l = 0; l < 8; l ++)
                board[k][l] = previous[k][l];
    }
}
int main()
{
    printAll(8);
    cout << total << endl;
}
