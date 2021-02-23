// THIS IS NOT A USACO PROBLEM
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
#include <bitset>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
using namespace std;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef long long ll;
typedef pair<ll, ll> pll;
#define max(n, m) ((n>m)?n:m)
#define min(n, m) ((n<m)?n:m)
#define f first
#define s second

int sumB(int arr[], int idx)
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
void updateB(int arr[], int idx, int val, int size)
{
    idx ++;
    while(idx <= size)
    {
        arr[idx] += val;
        idx += idx & (-idx);
    }
}
int sum(int arr1[], int arr2[], int l, int r)
{
    return (((sumB(arr1, r) * r) - (sumB(arr2, r))) - ((sumB(arr1, l - 1) * (l - 1)) - (sumB(arr2, l - 1))));
}
void update(int arr1[], int arr2[], int l, int r, int val, int size)
{
    updateB(arr1, l, val, size);
    updateB(arr1, r + 1, -1 * val, size);
    updateB(arr2, l, val * (l - 1), size);
    updateB(arr2, r + 1, -1 * val * r, size);
}
int bit1[100010];
int bit2[100010];
