#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int sum(int arr[], int idx)
{
    int ans = 0;
    idx ++;
    while(idx > 0)
    {
        ans += arr[idx];
        idx -= idx & (-idx);
    }
    return ans;
}
void update(int arr[], int idx, int val, int size)
{
    idx ++;
    while(idx <= size)
    {
        arr[idx] += val;
        idx += idx & (-idx);
    }
}
int bit[100010];
int nums[100010];
long long ans[100010];
int main()
{
    int n;
    long long cur = 0;
    cin >> n;
    for(int i = 0; i < n; i ++)
        cin >> nums[i];
    for(int i = 0; i < n; i ++)
    {
        ans[nums[i]] += i - sum(bit, nums[i]);
        update(bit, nums[i], 1, n + 5);
    }
    for(int i = 0; i < n; i ++)
    {
        cout << cur << "\n";
        cur += ans[i];
    }
}
