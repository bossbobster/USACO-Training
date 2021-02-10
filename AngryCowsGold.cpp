#include <iostream>
#include <iomanip>
#include <algorithm>
#include <math.h>
#include <vector>
#include <stack>
using namespace std;
typedef pair<int, int> pii;
#define max(n, m) ((n>m)?n:m)
#define min(n, m) ((n<m)?n:m)
#define f first
#define s second

int nums[100010];
int dpL[100010];
int dpR[100010];
int main()
{
    int n, pre, ans = 2000000000, idx1, idx2;
    cin >> n;
    for(int i = 0; i < n; i ++)
    {
        cin >> nums[i];
        nums[i] *= 2;
    }
    sort(nums, nums + n);
    for(int i = 0; i < n; i ++)
        dpL[i] = dpR[i] = 2000000000;
    dpL[0] = -100;
    pre = 0;
    for(int i = 1; i < n; i ++)
    {
        while(pre + 1 < i && nums[i] - nums[pre + 1] > dpL[pre + 1] + 2)
            pre ++;
        dpL[i] = min(nums[i] - nums[pre], dpL[pre + 1] + 2);
    }
    dpR[n - 1] = -100;
    pre = n - 1;
    for(int i = n - 2; i >= 0; i --)
    {
        while(pre - 1 > i && nums[pre - 1] - nums[i] > dpR[pre - 1] + 2)
            pre --;
        dpR[i] = min(nums[pre] - nums[i], dpR[pre - 1] + 2);
    }
    idx1 = 0; idx2 = n - 1;
    while(idx1 < idx2)
    {
        ans = min(ans, max((nums[idx2] - nums[idx1]) / 2, max(dpL[idx1], dpR[idx2]) + 2));
        if(dpL[idx1 + 1] < dpR[idx2 - 1]) idx1 ++;
        else idx2 --;
    }
    cout << fixed << setprecision(1) << (double)ans / 2 << "\n";
}
