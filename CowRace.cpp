#include <iostream>
#include <algorithm>
using namespace std;

int bessie[1000010];
int elsie[1000010];
int main()
{
    int n, m, tim, am, idx = 0, leader = 0, prev = -1, b = 0, e = 0, total = 0;
    cin >> n >> m;
    for(int i = 0; i < n; i ++)
    {
        cin >> am >> tim;
        for(int j = 0; j < tim; j ++)
        {
            bessie[idx] = am;
            idx ++;
        }
    }
    idx = 0;
    for(int i = 0; i < m; i ++)
    {
        cin >> am >> tim;
        for(int j = 0; j < tim; j ++)
        {
            elsie[idx] = am;
            idx ++;
        }
    }
    idx = 0;
    while(bessie[idx] != 0)
    {
        b += bessie[idx];
        e += elsie[idx];
        if(b > e) leader = 0;
        else leader = 1;
        if(leader != prev) total ++;
        prev = leader;
        idx ++;
    }
    cout << total - 1;
}
