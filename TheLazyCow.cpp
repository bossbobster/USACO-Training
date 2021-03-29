#include <iostream>
#include <string.h>
#include <fstream>
#include <stdio.h>
#include <iomanip>
#include <algorithm>
#include <math.h>
#include <vector>
#include <stack>
#include <queue>
#include <bitset>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
using namespace std;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<pii, int> piii;
typedef long long ll;
typedef pair<ll, ll> pll;
//#define max(n, m) ((n>m)?n:m)
//#define min(n, m) ((n<m)?n:m)
#define f first
#define s second

short og[410][410];
int nums[2110][2110];
int pre[2110][2110];
int sum(int r, int a, int b)
{
    return pre[min(2100,r)][min(2100,b)] - pre[min(2100,r)][min(2100,a) - 1];
}
int main()
{
    int n, k, loc = 1100, row = 500, ans = 0, lef = 1100, cur = 0;
    cin >> n >> k;
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < n; j ++)
            cin >> og[i][j];
    for(int i = n - 1; i >= 0; i --)
    {
        for(int j = 0; j < n - i; j ++)
        {
            nums[row][loc + j * 2] = og[i + j][j];
        }
        lef = min(lef, loc);
        loc --; row ++;
    } loc += 2;
    for(int i = 1; i < n; i ++)
    {
        for(int j = 0; j < n - i; j ++)
        {
            nums[row][loc + j * 2] = og[j][i + j];
        }
        loc ++; row ++;
    }
    for(int i = 0; i < 2110; i ++)
        for(int j = 1; j < 2110; j ++)
            pre[i][j] = pre[i][j - 1] + nums[i][j];
    for(int j = lef; j < 1300; j ++)
    {
        cur = 0;
        for(int i = 500; i <= 500 + k * 2; i ++) cur += sum(i, j, j + k * 2);
        ans = max(ans, cur);
        for(int i = 500; i < 1300; i ++)
        {
            cur -= sum(i, j, j + k * 2); //cur -= sum(i + 1, j, j + k * 2);
            cur += sum(i + k * 2 + 1, j, j + k * 2); //cur += sum(i + k * 2 + 2, j, j + k * 2);
            ans = max(ans, cur);
        }
    }
    cout << ans << "\n";
}
