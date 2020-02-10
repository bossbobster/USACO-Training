#include <iostream>
#include <algorithm>
using namespace std;

char board[15][15];
int vals[15][15];
int main()
{
    int r, c;
    cin >> r >> c;
    for(int i = 0; i < r; i ++)
        for(int j = 0; j < c; j ++)
            cin >> board[i][j];
    vals[0][0] = 1;
    for(int i = 1; i < r; i ++)
        for(int j = 1; j < c; j ++)
            for(int k = 0; k < i; k ++)
                for(int l = 0; l < j; l ++)
                    if(board[i][j] != board[k][l]) vals[i][j] += vals[k][l];
    cout << vals[r - 1][c - 1] << endl;
}
