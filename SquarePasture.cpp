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
typedef pair<int, char> pic;
typedef pair<pii, int> piii;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
//#define max(n, m) ((n>m)?n:m)
//#define min(n, m) ((n<m)?n:m)
#define f first
#define s second

int n, ans = 0, bad = 0, lo, hi, len, yl, yr, l, r, top, bot;
pii nums[210];
set<int> setY;
vector<int> y;
void solve()
{
    sort(nums, nums + n);
    for(int i = 0; i < n; i ++)
    {
        setY.clear();
        for(int j = i + 1; j < n; j ++)
        {
            if(i < j - 1) setY.insert(nums[j - 1].s);
            len = nums[j].f - nums[i].f;
            lo = max(nums[i].s, nums[j].s) - len; hi = min(nums[i].s, nums[j].s);
            if(lo > hi) continue;
            y.clear();
            for(auto it : setY)
                y.push_back(it);
            l = 0; r = -1;
            while (l < y.size() && lo >= y[l]+1) l ++;
            while (r+1 < y.size() && lo >= y[r+1]-len) r ++;
            while(true)
            {
                ans ++;
                yl = min(nums[i].s, nums[j].s); yr = max(nums[i].s, nums[j].s);
                if(l <= r) { yl = min(yl, y[l]); yr = max(yr, y[r]); } // always keep yl and yr as the min and max y vals of the rect
                if(yr - yl == len) bad ++; // rect is a square
                int leave_bottom = (l < y.size() ? y[l]+1 : 2000000000);  // set will no longer include cow l
                int enter_top    = (r+1 < y.size() ? y[r+1]-len : 2000000000); // set will include cow r+1
                int change_y = min(leave_bottom ,enter_top); // find min y such that set changes
                if (change_y > hi) break;
                l += (leave_bottom == change_y);
                r += (enter_top == change_y);
            }
            setY.insert(nums[j].s);
        }
    }
}
int main()
{
    cin >> n;
    for(int i = 0; i < n; i ++)
        cin >> nums[i].f >> nums[i].s;
    ans = n + 1;
    solve(); for(int i = 0; i < n; i ++) swap(nums[i].f, nums[i].s); solve(); // swap x and y to check for both width greater and height greater
    cout << ans - bad/2 << "\n"; // subtract all the duplicates that have width and height same and were counted twice
}
