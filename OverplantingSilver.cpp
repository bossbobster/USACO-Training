// THIS IS THE SILVER VERSION (previous silver)
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <set>
using namespace std;
typedef pair<long long, long long> pii;

struct pt
{
    long long x1, y1, x2, y2;
};
struct thing
{
    long long x, se, y1, y2, idx;
};
bool comp(thing t1, thing t2)
{
    if(t1.x == t2.x) return t1.se < t2.se;
    return t1.x < t2.x;
}

pt nums[1010];
vector<thing> arr;
set<pii> ys;
int main()
{
    long long n, ans = 0, cnt = 0;
    set<pii>::iterator it1, it2;
    cin >> n;
    for(int i = 0; i < n; i ++)
    {
        cin >> nums[i].x1 >> nums[i].y1 >> nums[i].x2 >> nums[i].y2;
        arr.push_back({nums[i].x1, 0, nums[i].y2, nums[i].y1, i + 1});
        arr.push_back({nums[i].x2, 1, nums[i].y2, nums[i].y1, i + 1});
    }
    sort(arr.begin(), arr.end(), comp);
    for(int i = 0; i < arr.size(); i ++)
    {
        if(i != 0 && !ys.empty())
        {
            cnt = 1;
            it1 = ys.begin();
            it2 = ys.begin(); it2 ++;
            while(it2 != ys.end())
            {
                if(cnt != 0)
                    ans += (arr[i].x - arr[i - 1].x) * (it2->first - it1->first);
                if(it2->second < 0) cnt ++;
                else cnt --;
                it2 ++; it1 ++;
            }
        }
        if(arr[i].se == 0) { ys.insert(pii(arr[i].y1, arr[i].idx * -1)); ys.insert(pii(arr[i].y2, arr[i].idx)); }
        else { ys.erase(pii(arr[i].y1, arr[i].idx * -1)); ys.erase(pii(arr[i].y2, arr[i].idx)); }
    }
    cout << ans << "\n";
}
