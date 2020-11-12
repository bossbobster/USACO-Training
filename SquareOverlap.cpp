#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <set>
using namespace std;
typedef pair<int, int> pii;

pii nums[50010];
set<pii> cur;
int main()
{
    int n, k, idx = 0, ans = 0;
    set<pii>::iterator it1, it2;
    cin >> n >> k;
    for(int i = 0; i < n; i ++)
        cin >> nums[i].first >> nums[i].second;
    sort(nums, nums + n);
    cur.insert(pii(nums[0].second, nums[0].first));
    for(int i = 1; i < n; i ++)
    {
        for(int j = idx; j < i; j ++)
            if(nums[j].first <= nums[i].first - k)
            {
                cur.erase(pii(nums[j].second, nums[j].first));
                idx ++;
            }
        it1 = cur.lower_bound(pii(nums[i].second - k, -200000000));
        it2 = cur.upper_bound(pii(nums[i].second + k, 200000000));
        for(set<pii>::iterator it = it1; it != it2; it ++)
        {
            if(it->first > nums[i].second - k && it->first < nums[i].second + k)
            {
                if(ans == 0)
                    ans = (k - abs(it->first - nums[i].second)) * (k - abs(nums[i].first - it->second));
                else
                {
                    cout << -1 << "\n"; return 0;
                }
            }
        }
        cur.insert(pii(nums[i].second, nums[i].first));
    }
    cout << ans << "\n";
}
