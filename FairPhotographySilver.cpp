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
typedef pair<ll, ll> pll;
//#define max(n, m) ((n>m)?n:m)
//#define min(n, m) ((n<m)?n:m)
#define f first
#define s second

pic nums[100010];
int pre[100010];
multiset<pii> m[2]; //even and odd
int main()
{
    int n, ans = 0;
    cin >> n;
    for(int i = 0; i < n; i ++)
        cin >> nums[i].f >> nums[i].s;
    sort(nums, nums + n);
    for(int i = 0; i < n; i ++)
    {
        pre[i + 1] = pre[i] + ((nums[i].s=='W')?1:-1);
        m[(i + 1) % 2].insert({pre[i + 1], i + 1});
    }
    for(int i = n; i > 0; i --)
    {
        if(m[i % 2].find({pre[i], i}) != m[i % 2].end())
            m[i % 2].erase(m[i % 2].find({pre[i], i}));
        if(m[(i + 1) % 2].empty()) break;
        for(multiset<pii>::iterator it = m[(i + 1) % 2].begin(); it != m[(i + 1) % 2].end(); ++it)
        {
            if(it->f >= pre[i]) break;
            ans = max(ans, (nums[i-1].f - nums[it->s - 1].f));
            m[(i + 1) % 2].erase(it);
            if(m[0].empty() || m[1].empty()) break;
        }
    }
    cout << ans << "\n";
}
