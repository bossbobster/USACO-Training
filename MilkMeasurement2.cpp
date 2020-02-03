//SILVER VERSION
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

struct change
{
    int day, id, delta;
};
bool cpr(change c1, change c2)
{
    return c1.day < c2.day;
}
multiset<int> vals;
map<int, int> curVals;
change changes[100000];
int main()
{
    int n, g, chg, cur, maxN, ans = 0, wasMax, cnt = 0;
    char sign;
    cin >> n >> g;
    maxN = g;
    for(int i = 0; i < n; i ++)
    {
        change tmp1;
        cin >> tmp1.day >> tmp1.id;
        curVals.insert(pair<int, int>(tmp1.id, g));
        vals.insert(g); vals.insert(g);
        cin >> sign >> chg;
        if(sign == '+') tmp1.delta = chg;
        else tmp1.delta = chg * -1;
        changes[i] = tmp1;
    }
    sort(changes, changes + n, cpr);
    for(int i = 0; i < n; i ++)
    {
        cur = curVals[changes[i].id];
        multiset<int>::iterator it = vals.end(); it --;
        vals.erase(vals.lower_bound(cur));
        wasMax = *it + changes[i].delta;
        curVals[changes[i].id] += changes[i].delta;
        vals.insert(curVals[changes[i].id]);
        it = vals.end(); it --;
        if((*it != maxN && *it != wasMax) || vals.count(*it) != cnt) ans ++;
        maxN = *it;
        cnt = vals.count(*it);
    }
    cout << ans << endl;
}
