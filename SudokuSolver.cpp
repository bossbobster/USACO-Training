//I DON'T THINK THIS IS A USACO PROBLEM
#include <iostream>
#include <algorithm>
#include <set>
#include <queue>
using namespace std;

int filled = 0;
bool done = false, done1 = false;
int board[9][9];

void rec()
{
    if(done) return;
    if(filled == 81)
    {
        done = true;
        return;
    }
    int row = 0, col = 0;
    done1 = false;
    for(int i = 0; i < 9; i ++)
    {
        for(int j = 0; j < 9; j ++)
            if(board[i][j] == 0)
            {
                row = i; col = j;
                done1 = true;
                break;
            }
        if(done1) break;
    }
    set<int> pos;
    for(int i = 0; i < 9; i ++)
        pos.insert(i + 1);
    for(int i = 0; i < 9; i ++)
        pos.erase(board[row][i]);
    for(int i = 0; i < 9; i ++)
        pos.erase(board[i][col]);
    for(int i = row / 3 * 3; i < row / 3 * 3 + 3; i ++)
        for(int j = col / 3 * 3; j < col / 3 * 3 + 3; j ++)
            pos.erase(board[i][j]);
    if(pos.empty()) return;
    for(set<int>::iterator it = pos.begin(); it != pos.end(); ++ it)
    {
        filled ++;
        board[row][col] = *it;
        rec();
        if(done) return;
        board[row][col] = 0;
        filled --;
    }
}
int main()
{
    for(int i = 0; i < 9; i ++)
        for(int j = 0; j < 9; j ++)
        {
            cin >> board[i][j];
            if(board[i][j] != 0)
                filled ++;
        }
    rec();
    if(!done)
    {
        cout << "NO SOLUTION" << "\n";
        return 0;
    }
    for(int i = 0; i < 9; i ++)
    {
        for(int j = 0; j < 9; j ++)
            cout << board[i][j] << " ";
        cout << "\n";
    }
}
