#include <iostream>
#include <algorithm>
using namespace std;

struct shop
{
    int x, cost, amt;
};
bool comp(shop s1, shop s2)
{
    return s1.cost < s2.cost;
}
shop shops[110];
int main()
{
    int k, e, n, ans = 0, idx = 0;
    cin >> k >> e >> n;
    for(int i = 0; i < n; i ++)
    {
        cin >> shops[i].x >> shops[i].amt >> shops[i].cost;
        shops[i].cost += (e - shops[i].x);
    }
    sort(shops, shops + n, comp);
    while(k > 0)
    {
        ans += min(k, shops[idx].amt) * shops[idx].cost;
        k -= min(k, shops[idx].amt);
        idx ++;
    }
    cout << ans << "\n";
}
