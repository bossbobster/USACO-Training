#include <iostream>
#include <algorithm>
using namespace std;

struct s
{
    int vs[25];
    int tot = 0, og;
};

int req[25];
s pos[15];
int cur[15];
int curVals[25];
int ans[15];
bool used[15];
int v, g, len;
bool done = false;
bool cpr(s s1, s s2)
{
    return s1.tot < s2.tot;
}
void printAll(int n1, int idx, int nn)
{
    if(done) return;
    if(n1 == 0)
    {
        for(int i = 0; i < nn; i ++)
            for(int j = 0; j < v; j ++)
            {
                if(i == 0) curVals[j] = 0;
                curVals[j] += pos[cur[i]].vs[j];
            }
        for(int i = 0; i < v; i ++)
            if(curVals[i] < req[i])
                return;
        for(int i = 0; i < nn; i ++)
            ans[i] = pos[cur[i]].og + 1;
        len = nn; done = true;
        return;
    }
    for(int i = nn - n1 + idx; i < g - n1 + 1; i ++)
    {
        if(used[i]) continue;
        cur[nn - n1] = i;
        used[i] = true;
        printAll(n1 - 1, idx, nn);
        if(done) return;
        idx ++;
        used[i] = false;
    }
}

int main()
{
    cin >> v;
    for(int i = 0; i < v; i ++) cin >> req[i];
    cin >> g;
    for(int i = 0; i < g; i ++)
        for(int j = 0; j < v; j ++)
        {
            cin >> pos[i].vs[j];
            pos[i].tot += pos[i].vs[j];
            pos[i].og = i;
        }
    sort(pos, pos + g, cpr);
    for(int i = 1; i <= g; i ++)
    {
        if(done) break;
        printAll(i, 0, i);
    }
    sort(ans, ans + len);
    cout << len << " ";
    for(int i = 0; i < len; i ++) cout << ans[i] << " ";
}
