#include <iostream>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

struct coo
{
    int x, y;
};
coo coos[50000];
set<int> xs;
set<int> ys;
set<int> xs2;
set<int> ys2;
map<int, int> xmap;
map<int, int> ymap;
int main()
{
    int n, maxX = 0, maxXCnt, maxY = 0, maxYCnt;
    cin >> n;
    for(int i = 0; i < n; i ++)
    {
        cin >> coos[i].x >> coos[i].y;
        xs.insert(coos[i].x); 
        ys.insert(coos[i].y);
        xmap[coos[i].x] = 0; 
        ymap[coos[i].y] = 0;
    }
    for(int i = 0; i < n; i ++)
    {
        xmap[coos[i].x] ++; ymap[coos[i].y] ++;
        if(xmap[coos[i].x] > maxX)
        {
            maxX = xmap[coos[i].x]; maxXCnt = coos[i].x;
        }
        if(ymap[coos[i].y] > maxY)
        {
            maxY = ymap[coos[i].y]; maxYCnt = coos[i].y;
        }
    }
    if(xs.size() <= 3 || ys.size() <= 3)
    {
        cout << 1; return 0;
    }
    for(int i = 0; i < n; i ++)
        if(coos[i].x != maxXCnt) ys2.insert(coos[i].y);
    if(ys2.size() <= 2)
    {
        cout << 1; return 0;
    }
    for(int i = 0; i < n; i ++)
        if(coos[i].y != maxYCnt) xs2.insert(coos[i].x);
    if(xs2.size() <= 2)
    {
        cout << 1; return 0;
    }
    cout << 0;
}
