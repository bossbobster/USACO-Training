//silver version
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

struct cow
{
    int start, end;
};

bool cpr(cow c1, cow c2)
{
    if(c1.end == c2.end)
        return c1.start < c2.start;
    return c1.end < c2.end;
}

cow cows[20010];
multiset<int> chickens;

int main()
{
    int c, n, total = 0, tmp;
    cin >> c >> n;
    for(int i = 0; i < c; i ++)
    {
        cin >> tmp;
        chickens.insert(tmp);
    }
    for(int i = 0; i < n; i ++)
        cin >> cows[i].start >> cows[i].end;
    sort(cows, cows + n, cpr);
    for(int i = 0; i < n; i ++)
    {
        auto it = chickens.lower_bound(cows[i].start);
        if(it != chickens.end() && *it <= cows[i].end)
        {
            chickens.erase(it);
            total ++;
        }
    }
    cout << total;
}
