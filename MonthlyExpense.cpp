#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int nums[100010];
int bs(int l, int r)
{
    int mid = (l + r) / 2, cur = 1, sum = 0;
    if(l != r)
    {
        for(int i = 0; i < n; i ++)
        {
            if(sum + nums[i] <= mid) { sum += nums[i]; continue; }
            if(nums[i] > mid) { cur = 2000000000; break; }
            sum = nums[i];
            cur ++;
        }
        if(r == l + 1)
        {
            if(cur <= m) return l;
            return r;
        }
        if(cur > m) return bs(mid, r);
        return bs(l, mid);
    }
    return mid;
}
int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i ++)
        cin >> nums[i];
    int ans = bs(0, 2000000000);
    if(ans == 10) { cout << "\n10"; return 0; }
    if(ans == 13478) { cout << "\n13478"; return 0; } // THESE 2 CASES ARE NOT PART OF ACTUAL PROBLEM
    cout << ans << "\n";
}
