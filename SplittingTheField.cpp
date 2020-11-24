#include <iostream>
#include <algorithm>
#include <math.h>
#include <set>
#include <map>
#include <vector>
using namespace std;

struct cow
{
    int x, y;
};

bool compx(cow c1, cow c2)
{
    return c1.x < c2.x;
}
bool compy(cow c1, cow c2)
{
    return c1.y < c2.y;
}
long long minL(long long l1, long long l2)
{
    if(l1 < l2) return l1;
    return l2;
}

cow nums[50010];
set<long long> l;
set<long long> r;
set<long long> u;
set<long long> d;
map<int, int> l1;
map<int, int> r1;
map<int, int> u1;
map<int, int> d1;
int main()
{
    int n, idx;
    long long minN = 2000000000000000000, big;
    cin >> n;
    for(int i = 0; i < n; i ++)
    {
        cin >> nums[i].x >> nums[i].y;
        r.insert(nums[i].y);
        u.insert(nums[i].x);
        r1[nums[i].y] ++;
        u1[nums[i].x] ++;
    }
    big = (*u.rbegin() - *u.begin()) * (*r.rbegin() - *r.begin());
    sort(nums, nums + n, compx);
    for(int i = 0; i < n - 1; i ++)
    {
        idx = i;
        while(idx < n && nums[idx].x == nums[i].x)
        {
            r1[nums[idx].y] --;
            if(r1[nums[idx].y] == 0) r.erase(nums[idx].y);
            l.insert(nums[idx].y);
            l1[nums[idx].y] ++;
            idx ++;
        }
        if(idx == n) break;
        i = idx - 1;
        minN = minL(minN, (nums[i].x - nums[0].x) * (*l.rbegin() - *l.begin()) + (nums[n - 1].x - nums[i + 1].x) * (*r.rbegin() - *r.begin()));
    }
    sort(nums, nums + n, compy);
    for(int i = 0; i < n - 1; i ++)
    {
        idx = i;
        while(idx < n && nums[idx].y == nums[i].y)
        {
            u1[nums[idx].x] --;
            if(u1[nums[idx].x] == 0) u.erase(nums[idx].x);
            d.insert(nums[idx].x);
            d1[nums[idx].x] ++;
            idx ++;
        }
        if(idx == n) break;
        i = idx - 1;
        minN = minL(minN, (nums[i].y - nums[0].y) * (*d.rbegin() - *d.begin()) + (nums[n - 1].y - nums[i + 1].y) * (*u.rbegin() - *u.begin()));
    }
    cout << (big - minN) << "\n";
}
