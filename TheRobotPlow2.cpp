#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <set>
using namespace std;
typedef pair<int, int> pii;

struct pt
{
    int x1, y1, x2, y2;
};
struct thing
{
    int x, se, y1, y2, idx;
};
bool comp(thing t1, thing t2)
{
    if(t1.x == t2.x) return t1.se < t2.se;
    return t1.x < t2.x;
}

pt nums[1010];
vector<thing> arr;
set<pii> ys;
bool counted[20010];
int main()
{
    int x, y, n, ans = 0, cnt = 0, idx = 0;
    set<pii>::iterator it1, it2;
    cin >> x >> y >> n;
    for(int i = 0; i < n; i ++)
    {
        cin >> nums[i].x1 >> nums[i].y1 >> nums[i].x2 >> nums[i].y2;
        arr.push_back({nums[i].x1, 0, nums[i].y1, nums[i].y2, i + 1});
        arr.push_back({nums[i].x2, 1, nums[i].y1, nums[i].y2, i + 1});
    }
    sort(arr.begin(), arr.end(), comp);
    for(int i = 0; i <= x; i ++)
    {
        while(idx < arr.size() && arr[idx].x <= i)
        {
            if(arr[idx].se == 1) break;
            ys.insert(pii(arr[idx].y1, arr[idx].idx * -1)); ys.insert(pii(arr[idx].y2, arr[idx].idx));
            idx ++;
        }
        if(!ys.empty())
        {
            cnt = 1;
            it1 = ys.begin();
            it2 = ys.begin(); it2 ++;
            while(it2 != ys.end())
            {
                if(it2->second < 0) cnt ++;
                else cnt --;
                if(cnt == 0)
                {
                    ans += (it2->first - it1->first + 1);
                    set<pii>::iterator tmp;
                    tmp = it2; tmp ++;
                    it1 = tmp;
                }
                set<pii>::iterator tmp;
                tmp = it2; tmp ++;
                if(tmp != ys.end()) it2 ++;
                else break;
            }
            //ans += (it2->first - it1->first + 1);
        }
        while(idx < arr.size() && arr[idx].x <= i)
        {
            if(arr[idx].se == 0) break;
            ys.erase(pii(arr[idx].y1, arr[idx].idx * -1)); ys.erase(pii(arr[idx].y2, arr[idx].idx));
            idx ++;
        }
    }
    cout << ans << "\n";
}
