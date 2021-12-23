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
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//template <class T> using Tree = tree<T, null_type, less<T>,
//rb_tree_tag, tree_order_statistics_node_update>;
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
typedef pair<ld, ld> pld;
typedef complex<double> cd;
//#define max(n, m) ((n>m)?n:m)
//#define min(n, m) ((n<m)?n:m)
#define f first
#define s second
#define input() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

ifstream fin("curling.in");
ofstream fout("curling.out");

struct pt
{
    double x, y;
    bool operator<(const pt& p1) const
    {
        if(p1.x == x) return y < p1.y;
        return x < p1.x;
    }
    const bool operator<=(const pt& other) const
    {
        if(x == other.x) return y <= other.y;
        return x <= other.x;
    }
    const bool operator>=(const pt& other) const
    {
        if(x == other.x) return y >= other.y;
        return x >= other.x;
    }
};
int cp(pt p1, pt p2)
{
    return p1.x * p2.y - p1.y * p2.x;
}
int ccw(pt p1, pt p2, pt p3)
{
    pt p4 = {p2.x - p1.x, p2.y - p1.y};
    pt p5 = {p3.x - p1.x, p3.y - p1.y};
    if(cp(p4, p5) < 0) return -1; // cw
    else if(cp(p4, p5) == 0 && ((p1 <= p3 && p3 <= p2) || (p1 >= p3 && p3 >= p2))) return 0;
    return 1; // ccw
}

pt nums[2][50010];
vector<pt> upper[2];
vector<pt> lower[2];
int target, idx;
int ans[2][2];
int bsUp(int l, int r)
{
    int mid = (l+r)/2;
    if(l >= r) return mid;
    if(upper[idx][mid].x <= target && upper[idx][mid+1].x >= target) return mid;
    if(upper[idx][mid].x > target) return bsUp(l, mid-1);
    return bsUp(mid+1, r);
}
int bsDown(int l, int r)
{
    int mid = (l+r)/2;
    if(l >= r) return mid;
    if(lower[idx][mid].x <= target && lower[idx][mid-1].x >= target) return mid;
    if(lower[idx][mid-1].x < target) return bsDown(l, mid-1);
    return bsDown(mid+1, r);
}
int main()
{
    input();
    int n;
    fin >> n;
    for(int i = 0; i < 2; i ++)
        for(int j = 0; j < n; j ++)
            fin >> nums[i][j].x >> nums[i][j].y;
    for(int cnt = 0; cnt < 2; cnt ++)
    {
        sort(nums[0], nums[0]+n); sort(nums[1], nums[1]+n);
        upper[0].clear(); upper[1].clear(); lower[0].clear(); lower[1].clear();
        for(int j = 0; j < 2; j ++)
        {
            for(int i = 0; i < n; i ++)
            {
                while(upper[j].size() >= 2 && ccw(upper[j][upper[j].size() - 2], upper[j][upper[j].size() - 1], nums[j][i]) != -1)
                    upper[j].pop_back();
                upper[j].push_back(nums[j][i]);
            }
            for(int i = n-1; i >= 0; i --)
            {
                while(lower[j].size() >= 2 && ccw(lower[j][lower[j].size() - 2], lower[j][lower[j].size() - 1], nums[j][i]) != -1)
                    lower[j].pop_back();
                lower[j].push_back(nums[j][i]);
            }
        }
        for(int j = 0; j < 2; j ++)
        {
            idx = (j+1)%2;
            for(int i = 0; i < n; i ++)
            {
                target = nums[j][i].x;
                int up = bsUp(0, (int)upper[idx].size()-2);
                int down = bsDown(1, (int)lower[idx].size()-1);
                if(ccw(upper[idx][up], upper[idx][up+1], nums[j][i]) != 1 && ccw(lower[idx][down-1], lower[idx][down], nums[j][i]) != 1)
                    ans[cnt][idx] ++;
            }
        }
        for(int i = 0; i < 2; i ++)
            for(int j = 0; j < n; j ++)
                swap(nums[i][j].x, nums[i][j].y);
    }
    fout << min(ans[0][0], ans[1][0]) << ' ' << min(ans[0][1], ans[1][1]) << '\n';
}
