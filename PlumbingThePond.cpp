//plumb
#include <iostream>
using namespace std;

int r, c;
int lake[50][50];
bool adjacent(int y, int x)
{
    for(int dx = -1; dx <= 1; dx ++)
    {
        if((dx == -1 && x == 0) || (dx == 1 && x == c - 1))
            continue;
        for(int dy = -1; dy <= 1; dy ++)
        {
            if((dy == -1 && y == 0) || (dy == 1 && y == r - 1) || (dx == dy && dx == 0))
                continue;
            if(lake[y + dy][x + dx] == lake[y][x])
                return true;
        }
    }
    return false;
}

int main()
{
    cin >> r >> c;
    int best = 0;
    for(int i = 0; i < r; i ++)
        for(int j = 0; j < c; j ++)
            cin >> lake[i][j];
    for(int i = 0; i < r; i ++)
        for(int j = 0; j < c; j ++)
            if(adjacent(i, j) && lake[i][j] > best)
                best = lake[i][j];
    cout << best;
}
