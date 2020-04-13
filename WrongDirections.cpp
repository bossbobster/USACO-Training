#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

struct coo
{
    int x, y;
};

int mod(int n1, int n2)
{
    if(n1 >= 0) return n1 % n2;
    return n1 + n2;
}

set<pair<int, int>> found;
int e[2];
int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int main()
{
    string s;
    int len, curD = 0, curX = 0, curY = 0;
    cin >> s;
    len = s.length();
    for(int i = 0; i < len; i ++)
    {
        if(s[i] == 'F') { curX += dir[curD][0]; curY += dir[curD][1]; }
        if(s[i] == 'R') curD = mod(curD + 1, 4);
        if(s[i] == 'L') curD = mod(curD - 1, 4);
    }
    e[0] = curX; e[1] = curY;
    curX = curY = curD = 0;
    for(int i = 0; i < len; i ++)
    {
        if(s[i] == 'R' || s[i] == 'L')
            found.insert({-(e[0] - curX) + curX, -(e[1] - curY) + curY});
        if(s[i] == 'F')
        {
            found.insert({e[1] - curY + curX - dir[mod(curD + 1, 4)][0], -(e[0] - curX) + curY - dir[mod(curD + 1, 4)][1]});
            found.insert({-(e[1] - curY) + curX + dir[mod(curD + 1, 4)][0], e[0] - curX + curY + dir[mod(curD + 1, 4)][1]});
        }
        if(s[i] == 'R')
            found.insert({-(e[1] - curY) + curX + dir[curD][0], e[0] - curX + curY + dir[curD][1]});
        if(s[i] == 'L')
            found.insert({e[1] - curY + curX + dir[curD][0], -(e[0] - curX) + curY + dir[curD][1]});
        if(s[i] == 'F') { curX += dir[curD][0]; curY += dir[curD][1]; }
        if(s[i] == 'R') curD = mod(curD + 1, 4);
        if(s[i] == 'L') curD = mod(curD - 1, 4);
    }
    cout << found.size() << endl;
}
