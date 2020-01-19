#include <iostream>
#include <algorithm>
#include <math.h>
#include <queue>
#include <bitset>
using namespace std;

struct stage
{
    bitset<20> now;
    int d;
};

bool visited[1100000];
bitset<20> cur;
int d, ans;
queue<stage> nextInLine;
void findAll()
{
    do
    {
        cur = nextInLine.front().now;
        d = nextInLine.front().d;
        if(cur.to_ulong() == 0) { ans = d; break; }
        for(int i = 0; i < 20; i ++)
        {
            cur.flip(i);
            if(i - 1 >= 0) cur.flip(i - 1);
            if(i + 1 <= 19) cur.flip(i + 1);
            if(!visited[cur.to_ulong()]) nextInLine.push({cur, d + 1});
            visited[cur.to_ulong()] = true;
            cur.flip(i);
            if(i - 1 >= 0) cur.flip(i - 1);
            if(i + 1 <= 19) cur.flip(i + 1);
        }
        nextInLine.pop();
    } while(!nextInLine.empty());
}
int main()
{
    stage s;
    short tmp;
    for(int i = 0; i < 20; i ++)
    {
        cin >> tmp; s.now[i] = tmp;
    }
    s.d = 0;
    if(s.now.to_ulong() == 0) { cout << 0; return 1; }
    nextInLine.push(s);
    findAll();
    cout << ans;
}
