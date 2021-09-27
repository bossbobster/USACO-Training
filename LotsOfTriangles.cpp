#include <iostream>
#include <string.h>
#include <random>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <bitset>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <complex>
#include <valarray>
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
using namespace std;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<string, string> pss;
typedef pair<int, char> pic;
typedef pair<pii, int> piii;
typedef pair<double, double> pdd;
typedef pair<float, float> pff;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;
typedef pair<ull, ull> pull;
typedef complex<double> cd;
//#define max(n, m) ((n>m)?n:m)
//#define min(n, m) ((n<m)?n:m)
#define f first
#define s second
#define input() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

struct pt
{
    ll x, y;
    const bool operator<(const pt& other) const
    {
        return x < other.x;
    }
    const bool operator>(const pt& other) const
    {
        return x > other.x;
    }
};
ll cp(pt p1, pt p2)
{
    return p1.x * p2.y - p1.y * p2.x;
}
ll ccw(pt p1, pt p2, pt p3)
{
    pt p4 = {p2.x - p1.x, p2.y - p1.y};
    pt p5 = {p3.x - p1.x, p3.y - p1.y};
    if(cp(p4, p5) > 0) return 1; // ccw
    return -1; // cw
}
pt nums[310];
int pre[310][310];
int ans[310];
bool vert(int i, int j)
{
    if(nums[i].x == nums[j].x) return true;
    return false;
}
int main()
{
    input()
    int n;
    cin >> n;
    for(int i = 0; i < n; i ++)
        cin >> nums[i].x >> nums[i].y;
    for(int i = 0; i < n-1; i ++)
        for(int j = i+1; j < n; j ++)
            for(int k = 0; k < n; k ++)
            {
                if(k == i || k == j) continue;
                if(ccw(min(nums[i], nums[j]), max(nums[i], nums[j]), nums[k]) == -1 && nums[k].x >= min(nums[i].x, nums[j].x) && nums[k].x < max(nums[i].x, nums[j].x))
                    pre[i][j] ++, pre[j][i] ++;
            }
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < n; j ++)
            for(int k = 0; k < n; k ++)
            {
                if(i == j || i == k || j == k) continue;
                if(vert(i, j))
                    if(nums[i].y > nums[j].y)
                        ans[pre[i][k]-pre[j][k]-((nums[k].x<nums[i].x)?0:1)] ++;
                if(nums[i].x > nums[j].x && nums[i].x < nums[k].x)
                {
                    if(nums[i].y >= nums[j].y && nums[i].y >= nums[k].y)
                        ans[pre[i][j]+pre[i][k]-pre[j][k]] ++;
                    else
                    {
                        if(ccw(nums[j], nums[k], nums[i]) == -1)
                           ans[pre[j][k]-pre[i][j]-pre[i][k]-1] ++;
                        else
                            ans[pre[i][j]+pre[i][k]-pre[j][k]] ++;
                    }
                }
            }
    for(int i = 0; i < n-2; i ++)
        cout << ans[i] << '\n';
}
