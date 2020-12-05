//SILVER VERSION OF PROBLEM
#include <iostream>
#include <algorithm>
#include <math.h>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int, int> pii;

pii nums[1010];
int main()
{
    int n, r1 = 0, r2 = 0, r3 = 0, r4 = 0, ans = 2000000000, cur = 0;
    cin >> n;
    for(int i = 0; i < n; i ++)
        cin >> nums[i].first >> nums[i].second;
    sort(nums, nums + n);
    for(int i = 0; i < n; i ++)
    {
        cur = nums[i].second + 1;
        r1 = r2 = r3 = r4 = 0;
        for(int j = 0; j < n; j ++)
        {
            if(nums[j].second < cur) r4 ++;
            else r1 ++;
        }
        for(int j = 0; j < n; j ++)
        {
            if(nums[j].second < cur) { r4 --; r3 ++; }
            else { r1 --; r2 ++; }
            ans = min(ans, max(max(r1, r2), max(r3, r4)));
        }
    }
    cout << ans << "\n";
}
