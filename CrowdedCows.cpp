#include <iostream>
#include <algorithm>
#include <math.h>
#include <set>
#include <map>
#include <vector>
using namespace std;

struct cow
{
    int x, h;
    bool operator<(const cow& c1) const
    {
        return x < c1.x;
    }
};

set<int> l;
set<int> r;
map<int, int> l1;
map<int, int> r1;
cow nums[100010];
int main()
{
    int n, d, ans = 0, idx1 = 0, idx2 = 2;
    cin >> n >> d;
    for(int i = 0; i < n; i ++)
        cin >> nums[i].x >> nums[i].h;
    sort(nums, nums + n);
    l.insert(nums[0].h);
    l1[nums[0].h] ++;
    for(int i = 1; i < n - 1; i ++)
    {
        if(r1[nums[i].h] != 0) r1[nums[i].h] --;
        if(r1[nums[i].h] == 0) r.erase(nums[i].h);
        while(idx1 < i && nums[idx1].x < nums[i].x - d)
        {
            l1[nums[idx1].h] --;
            if(l1[nums[idx1].h] == 0) l.erase(nums[idx1].h);
            idx1 ++;
        }
        while(idx2 < n && nums[idx2].x <= nums[i].x + d)
        {
            r1[nums[idx2].h] ++;
            r.insert(nums[idx2].h);
            idx2 ++;
        }
        if(*l.rbegin() >= 2 * nums[i].h && *r.rbegin() >= 2 * nums[i].h) ans ++;
        l.insert(nums[i].h);
        l1[nums[i].h] ++;
    }
    cout << ans << "\n";
}
