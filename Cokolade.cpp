// CROATIAN INFORMATICS OLYMPIAD PROBLEM (not USACO)
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <math.h>
using namespace std;
typedef pair<int, int> pii;

int nums[110];
int cnt[110];
vector<int> cnt2;
set<int> imp;
int ans[110];
int main()
{
    int n, pre;
    cin >> n;
    for(int i = 0; i < n; i ++)
        cin >> nums[i];
    sort(nums, nums + n);
    for(int i = 0; i < n; i ++)
    {
        for(int j = 1; j <= sqrt(nums[i]); j ++)
        {
            imp.insert(j);
            imp.insert((nums[i] / j) + 1);
        }
        imp.insert(nums[i] + 1);
    }
    for(set<int>::iterator it = imp.begin(); it != imp.end(); ++ it)
    {
        cnt2.clear();
        for(int i = 0; i < n; i ++)
            cnt[i] = nums[i] / *it;
        pre = 0;
        for(int i = 1; i < n; i ++)
        {
            if(cnt[i] != cnt[i - 1])
            {
                cnt2.push_back(i - pre);
                pre = i;
            }
        }
        cnt2.push_back(n - pre);
        for(int i = 0; i < cnt2.size(); i ++)
            if(ans[cnt2[i]] == 0)
                ans[cnt2[i]] = *it;
    }
    for(int i = 1; i <= n; i ++)
        cout << ((ans[i]==0)?-1:ans[i]) << "\n";
}
