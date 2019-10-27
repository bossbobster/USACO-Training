#include <iostream>
#include <algorithm>
using namespace std;

int n, m, direction = 0, curR, curC, maxN = 0, curN = 0;
void move()
{
    if(direction == 0)
        curC ++;
    if(direction == 1)
        curC --;
    if(direction == 2)
        curR ++;
    if(direction == 3)
        curR --;
}

short field[1000][1000];
short turns[8] = {3, 2, 2, 3, 1, 0, 0, 1};
int main()
{
    char mirror;
    cin >> n >> m;
    for(int i = 0; i < n; i ++)
    {
        for(int j = 0; j < m; j ++)
        {
            cin >> mirror;
            if(mirror == '/') field[i][j] = 0;
            else field[i][j] = 1;
        }
    }
    for(int dx = 0; dx < 2; dx ++)
    {
        for(int i = 0; i < n; i ++)
        {
            if(dx == 0)
                curC = 0;
            else
                curC = m - 1;
            curR = i;
            curN = 1;
            direction = turns[dx * 2 + field[curR][curC]];
            move();
            while(curC >= 0 && curC < m && curR >= 0 && curR < n)
            {
                curN ++;
                direction = turns[direction * 2 + field[curR][curC]];
                move();
            }
            maxN = max(curN, maxN);
        }
    }
    for(int dx = 0; dx < 2; dx ++)
    {
        for(int i = 0; i < m; i ++)
        {
            if(dx == 0)
                curR = 0;
            else
                curR = n - 1;
            curC = i;
            curN = 1;
            direction = turns[(dx + 2) * 2 + field[curR][curC]];
            move();
            while(curC >= 0 && curC < m && curR >= 0 && curR < n)
            {
                curN ++;
                direction = turns[direction * 2 + field[curR][curC]];
                move();
            }
            maxN = max(curN, maxN);
        }
    }
    cout << maxN;
}
