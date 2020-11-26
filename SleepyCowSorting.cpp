#include <iostream>
#include <fstream>
#include <algorithm>
#include <math.h>
#include <set>
#include <vector>
using namespace std;

ifstream fin("sleepy.in");
ofstream fout("sleepy.out");

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

int nums[100010];
int cnt[100010];
int main()
{
    int n, ans = 0, idx;
    fin >> n;
    for(int i = 0; i < n; i ++)
        fin >> nums[i];
    for(int i = 1; i < n; i ++)
        if(nums[i] < nums[i - 1])
            ans = i;
    fout << ans << "\n";
    idx = ans - 1;
    for(int i = idx + 1; i < n; i ++)
        update(cnt, nums[i], 1, n);
    for(int i = 0; i < ans; i ++)
    {
        fout << sum(cnt, nums[i] - 1) + idx << ((i == ans - 1)?"\n":" ");
        idx --;
        update(cnt, nums[i], 1, n);
    }
}
