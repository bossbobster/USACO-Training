#include <iostream>
#include <algorithm>
using namespace std;

struct bale
{
    int w, h;
};
bool cpr(bale b1, bale b2)
{
    return b1.w > b2.w;
}
int n, ans = 1;
bale bales[20];
bool used[20];

void findAll(int nn, int n1, int idx, int m, string cur)
{
    if(n1 == 0)
    {
        for(int i = 0; i < cur.length() - 1; i ++)
            if(bales[cur[i] - '0'].h < bales[cur[i + 1] - '0'].h)
                return;
        ans = max(ans, nn);
        return;
    }
    for(int i = nn - n1 + idx; i < nn - n1 + m - nn + 1; i ++)
    {
        if(used[i]) continue;
        cur[nn - n1] = i + '0';
        used[i] = true;
        findAll(nn, n1 - 1, idx, m, cur);
        idx ++;
        used[i] = false;
    }
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i ++)
        cin >> bales[i].w >> bales[i].h;
    sort(bales, bales + n, cpr);
    for(int i = 2; i <= n; i ++) 
    {
        string s = "";
        for(int j = 0; j < i; j ++) s += "0";
        findAll(i, i, 0, n, s);
    }
    cout << ans;
}
