#include <iostream>
#include <algorithm>
using namespace std;

int nums[10010];
int main()
{
    int n, k, ans;
    cin >> n >> k;
    for(int i = 0; i < k; i ++)
        cin >> nums[i];
    sort(nums, nums + k);
    ans = max(ans, max(nums[0], n - nums[k - 1]));
    for(int i = 1; i < k; i ++)
        ans = max(ans, (nums[i] - nums[i - 1]) / 2);
    cout << ans << "\n";
}
