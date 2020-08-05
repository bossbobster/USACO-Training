#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

bool r0[1000010];
bool c0[1000010];
vector<long long> winss;
int main()
{
    long long n, m, t, ar = 0, ac = 0, br = 0, bc = 0, pos, x, y, p1, p2;
    r0[0] = c0[0] = true;
    winss.push_back(0);
    cin >> n >> m >> t;
    n = max(n, m);
    while(true)
    {
        ar ++; ac += 2;
        br += 2; bc ++;
        while((r0[ar] || c0[ac]) && ac < n)
        {
            ar ++; ac ++;
            br ++; bc ++;
        }
        if(ac >= n) break;
        r0[ar] = r0[br] = true;
        c0[ac] = c0[bc] = true;
        pos = ar * 10000000 + ac;
        winss.push_back(pos);
    }
    sort(winss.begin(), winss.end());
    for(int i = 0; i < t; i ++)
    {
        cin >> x >> y;
        p1 = x * 10000000 + y;
        p2 = y * 10000000 + x;
        if(binary_search(winss.begin(), winss.end(), p1) || binary_search(winss.begin(), winss.end(), p2))
            cout << "Farmer John" << "\n";
        else cout << "Bessie" << "\n";
    }
}
