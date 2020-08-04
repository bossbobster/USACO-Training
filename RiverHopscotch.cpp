#include <iostream>
#include <algorithm>
using namespace std;

int l, n, m;
int rocks[50010];
int bs(int l, int r)
{
    int mid = (l + r) / 2, removed = 0, cur = 1;
    if(l == r) return mid;
    if(mid == l) return bs(l, r - 1);
    if(l <= r)
    {
        for(int i = 1; i <= n; i ++)
        {
            if(rocks[i] - rocks[i - cur] < mid) { removed ++; cur ++; }
            else cur = 1;
        }
        if(removed <= m)
            return bs(mid, r);
        return bs(l, mid);
    }
}
int main()
{
    cin >> l >> n >> m;
    rocks[0] = 0;
    for(int i = 1; i <= n; i ++)
        cin >> rocks[i];
    rocks[n + 1] = l;
    sort(rocks, rocks + n + 2);
    cout << bs(0, l + 1) << "\n";
}
