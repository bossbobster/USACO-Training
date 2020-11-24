#include <iostream>
#include <algorithm>
#include <math.h>
#include <queue>
#include <vector>
using namespace std;

struct st
{
    int x, m;
    bool operator<(const st& s) const
    {
        return x < s.x;
    }
};

st nums[100010];
int main()
{
    int n, l, ans = 0;
    cin >> l >> n;
    nums[0].x = 0; nums[0].m = 1;
    nums[1].x = l; nums[1].m = 2000000000;
    for(int i = 2; i <= n + 1; i ++)
        cin >> nums[i].x >> nums[i].m;
    n += 2;
    sort(nums, nums + n);
    for(int i = n - 1; i > 0; i --)
        if(nums[i - 1].m - nums[i].m > nums[i].x - nums[i - 1].x)
            nums[i - 1].m = nums[i].m + nums[i].x - nums[i - 1].x;
    for(int i = 0; i < n - 1; i ++)
        if(nums[i + 1].m - nums[i].m > nums[i + 1].x - nums[i].x)
            nums[i + 1].m = nums[i].m + nums[i + 1].x - nums[i].x;
    for(int i = 0; i < n - 1; i ++)
        ans = max(ans, ((nums[i + 1].x - nums[i].x) - abs(nums[i + 1].m - nums[i].m)) / 2 + max(nums[i].m, nums[i + 1].m));
    cout << ans << "\n";
}
