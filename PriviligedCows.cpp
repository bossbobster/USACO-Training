#include <iostream>
#include <algorithm>
using namespace std;

int nums[1010];
int sorted[1010];
int cntOnes[2];
int main()
{
    int n, ans = 0, ones = 0, twos = 0, threes = 0;
    cin >> n;
    for(int i = 0; i < n; i ++)
    {
        cin >> nums[i];
        sorted[i] = nums[i];
    }
    sort(sorted, sorted + n);
    for(int i = 0; i < n; i ++)
    {
        if(sorted[i] == 1) ones ++;
        if(nums[i] != sorted[i])
            ans ++;
    }
    for(int i = 0; i < ones; i ++)
    {
        if(nums[i] == 2) twos ++;
        if(nums[i] == 3) threes ++;
    }
    for(int i = ones; i < n; i ++)
        if(nums[i] == 1)
            cntOnes[sorted[i] - 2] ++;
    ans += abs(twos - cntOnes[0]) / 2;
    ans += abs(threes - cntOnes[1]) / 2;
    ans = (ans + 1) / 2;
    cout << ans << "\n";
}
