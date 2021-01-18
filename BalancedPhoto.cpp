#include <iostream>
#include <fstream>
#include <algorithm>
#include <math.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

ifstream fin("bphoto.in");
ofstream fout("bphoto.out");

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
int sorted[100010];
int bit1[100010];
int bit2[100010];
int l[100010];
int r[100010];
gp_hash_table<int, int> hsh;
int main()
{
    int n, ans = 0;
    fin >> n;
    for(int i = 0; i < n; i ++)
    {
        fin >> nums[i];
        sorted[i] = nums[i];
    }
    sort(sorted, sorted + n);
    for(int i = 0; i < n; i ++)
        if(hsh.find(sorted[i]) == hsh.end())
            hsh[sorted[i]] = i;
    for(int i = 0; i < n; i ++)
    {
        l[i] = sum(bit1, n) - sum(bit1, hsh[nums[i]]);
        update(bit1, hsh[nums[i]], 1, n + 1);
    }
    for(int i = n - 1; i >= 0; i --)
    {
        r[i] = sum(bit2, n) - sum(bit2, hsh[nums[i]]);
        update(bit2, hsh[nums[i]], 1, n + 1);
    }
    for(int i = 0; i < n; i ++)
        if(max(l[i], r[i]) > min(l[i], r[i]) * 2)
            ans ++;
    fout << ans << "\n";
}
