#include <iostream>
#include <algorithm>
#include <math.h>
#include <queue>
#include <vector>
#include <bitset>
using namespace std;
typedef pair<int, int> pii;

struct st
{
    short r, c;
    int val;
    bool operator>(const st& s1) const
    {
        return val > s1.val;
    }
};

int hor[2005];
int ver[2005];
int len[2005][2005];
priority_queue<st, vector<st>, greater<st>> nextInLine;
bitset<5000000> finalized;
int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};
int main()
{
    int a, b, n, m, curR, curC, curD, cur;
    long long ans = 0;
    cin >> a >> b >> n >> m;
    ver[0] = 0; hor[0] = 0; ver[1] = a; hor[1] = b;
    for(int i = 2; i <= n + 1; i ++)
        cin >> ver[i];
    for(int i = 2; i <= m + 1; i ++)
        cin >> hor[i];
    n += 2; m += 2;
    sort(ver, ver + n);
    sort(hor, hor + m);
    for(int i = 0; i < m; i ++)
        for(int j = 0; j < n; j ++)
            len[i][j] = 2000000000;
    nextInLine.push({0, 0, 0});
    len[0][0] = 0;
    while(!nextInLine.empty())
    {
        curD = nextInLine.top().val;
        curR = nextInLine.top().r;
        curC = nextInLine.top().c;
        nextInLine.pop();
        if(finalized[curR * (n - 1) + curC]) continue;
        if(curD > len[curR][curC]) continue;
        for(int i = 0; i < 4; i ++)
        {
            if(curR + dr[i] < 0 || curR + dr[i] >= m - 1 || curC + dc[i] < 0 || curC + dc[i] >= n - 1) continue;
            if(finalized[(curR + dr[i]) * (n - 1) + curC + dc[i]]) continue;
            switch(i)
            {
                case 0:
                    cur = ver[curC + 1] - ver[curC];
                    break;
                case 1:
                    cur = hor[curR + 1] - hor[curR];
                    break;
                case 2:
                    cur = ver[curC + 1] - ver[curC];
                    break;
                default:
                    cur = hor[curR + 1] - hor[curR];
                    break;
            }
            cur = max(cur, 1);
            if(cur < len[curR + dr[i]][curC + dc[i]])
            {
                len[curR + dr[i]][curC + dc[i]] = cur;
                nextInLine.push({curR + dr[i], curC + dc[i], cur});
            }
        }
        finalized[curR * (n - 1) + curC] = true;
    }
    for(int i = 0; i < m - 1; i ++)
        for(int j = 0; j < n - 1; j ++)
            ans += len[i][j];
    cout << ans << "\n";
}
