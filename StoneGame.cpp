#include <iostream>
#include <string.h>
#include <fstream>
#include <stdio.h>
#include <cmath>
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
typedef unsigned int uint;
typedef pair<ll, ll> pll;
//#define max(n, m) ((n>m)?n:m)
//#define min(n, m) ((n<m)?n:m)
#define f first
#define s second

int nums[100010];
int pre[1000010];
vector<int> cnt, odd;
int main()
{
    int n, mx = 0;
    ll ans = 0;
    cin >> n;
    for(int i = 0; i < n; i ++)
    {
        cin >> nums[i];
        mx = max(mx, nums[i]);
        pre[nums[i]] ++;
    }
    for(int i = 1; i <= mx; i ++) pre[i] += pre[i-1];
    for(int i = 1; i <= mx; i ++)
    {
        cnt.clear(); odd.clear(); cnt.push_back(0);
        for(int j = 1; i*j <= mx; j ++)
            cnt.push_back(pre[min(mx, i * (j + 1) - 1)] - pre[i * j - 1]);
        for(int i = 1; i < cnt.size(); i ++)
            if(cnt[i] % 2 == 1)
                odd.push_back(i);
        if((odd.size() == 1 && odd[0] == 1) || (odd.size() == 2 && odd[0] == odd[1] - 1))
            ans += cnt[odd[odd.size()-1]];
    }
    cout << ans << "\n";
}
