#include <iostream>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

pair<int, int> starts[40010];
pair<int, int> endss[40010];
set<int> h;
map<int, int> cnt;
int main()
{
    long long n, cur1, cur2, cur3, idx1 = 1, idx2 = 0, last, area = 0;
    cin >> n;
    for(int i = 0; i < n; i ++)
    {
        cin >> cur1 >> cur2 >> cur3;
        starts[i].first = cur1; starts[i].second = cur3;
        endss[i].first = cur2; endss[i].second = cur3;
    }
    sort(starts, starts + n);
    sort(endss, endss + n);
    last = starts[0].first;
    h.insert(starts[0].second);
    cnt[starts[0].second] ++;
    while(idx2 < n)
    {
        if(idx1 == n)
        {
            if(!h.empty()) area += *h.rbegin() * (endss[idx2].first - last);
            last = endss[idx2].first;
            cnt[endss[idx2].second] --;
            if(cnt[endss[idx2].second] == 0)
                h.erase(endss[idx2].second);
            idx2 ++;
        }
        else
        {
            if(starts[idx1].first <= endss[idx2].first)
            {
                if(!h.empty()) area += *h.rbegin() * (starts[idx1].first - last);
                last = starts[idx1].first;
                cnt[starts[idx1].second] ++;
                h.insert(starts[idx1].second);
                idx1 ++;
            }
            else
            {
                if(!h.empty()) area += *h.rbegin() * (endss[idx2].first - last);
                last = endss[idx2].first;
                cnt[endss[idx2].second] --;
                if(cnt[endss[idx2].second] == 0)
                    h.erase(endss[idx2].second);
                idx2 ++;
            }
        }
    }
    cout << area << "\n";
}
