#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <stack>
using namespace std;

struct st
{
    long long x, p, i;
};

bool comp(st s1, st s2)
{
    return s1.x < s2.x;
}

st nums[50010];
int c[50010];
stack<st> s;
int main()
{
    long long n, cap, cur, d, need;
    long long ans = 0;
    cin >> n >> cap >> cur >> d;
    for(int i = 0; i < n; i ++)
        cin >> nums[i].x >> nums[i].p;
    sort(nums, nums + n, comp);
    for(int i = 0; i < n; i ++)
        nums[i].i = i;
    for(int i = n - 1; i >= 0; i --)
    {
        while(!s.empty() && s.top().p >= nums[i].p)
            s.pop();
        if(!s.empty())
            c[i] = s.top().i;
        s.push(nums[i]);
    }
    if(nums[0].x > cur) { cout << -1; return 0; }
    cur -= nums[0].x;
    for(int i = 0; i < n; i ++)
    {
        if(cur < 0) { cout << -1; return 0; }
        if(c[i] == 0) need = min(cap, d - nums[i].x);
        else need = min(cap, nums[c[i]].x - nums[i].x);
        if(need > cur) { ans += (need - cur) * nums[i].p; cur = need; }
        if(i == n - 1) cur -= (d - nums[i].x);
        else cur -= nums[i + 1].x - nums[i].x;
    }
    if(cur < 0) { cout << -1; return 0; }
    cout << ans << "\n";
}
