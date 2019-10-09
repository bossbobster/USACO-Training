#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

short direction[6][2] = {{-1, 1}, {-2, 0}, {-1, -1}, {1, -1}, {2, 0}, {1, 1}};
short hexagon[3100][3100];
vector<int> possible;
int main()
{
    int k, h, l, curX = 1000, curY, curH, firstX = 0, firstY = 0, placement = 0, cur = 0;
    cin >> k >> h >> l;
    curY = 4 * k - 1 + 1000;
    curH = k;
    for(int i = 0; i < 3 * k * (k - 1) + 1; i ++)
    {
        if(i == h - 1)
        {
            firstX = curX;
            firstY = curY;
        }
        hexagon[curY][curX] = i + 1;
        cur ++;
        if(cur < curH)
            curY -= 2;
        else
        {
            curY += (curH * 2 - ((curX < k + 999)?1:3));
            curX ++;
            if(curX < k + 1000)
                curH ++;
            else
                curH --;
            cur = 0;
        }
    }
    curX = firstX;
    curY = firstY + 2 * l;
    for(int i = 0; i < 6; i ++)
    {
        for(int j = 0; j < l; j ++)
        {
            if(hexagon[curY][curX] != 0)
                possible.push_back(hexagon[curY][curX]);
            if(i == 5 && j == l - 1)
                break;
            curX += direction[i][1];
            curY += direction[i][0];
        }
    }
    sort(possible.begin(), possible.end());
    cout << possible.size() << endl;
    for(int i = 0; i < possible.size(); i ++)
        cout << possible[i] << endl;
}
