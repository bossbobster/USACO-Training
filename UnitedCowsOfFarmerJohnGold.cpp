#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
typedef long long ll;
using namespace std;

int n;
int nums[200010];
vector<int> pos[200010];
int l[200010];
int r[200010]; //l and r store first occurence of the number to its left and right
int bit[200010];
ll sum(int idx)
{
    idx ++;
    ll ans = 0;
    while(idx > 0)
    {
        ans += bit[idx];
        idx -= (idx & (-idx));
    }
    return ans;
}
void update(int idx, ll val)
{
    if(idx == -1) return;
    idx ++;
    while(idx < n + 1)
    {
        bit[idx] += val;
        idx += (idx & (-idx));
    }
}
int main()
{
    cin >> n;
    ll ans = 0;
    for(int i = 0; i < n; i ++)
    {
        cin >> nums[i]; nums[i] --;
        pos[nums[i]].push_back(i);
    }
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < pos[i].size(); j ++)
        {
            if(j == 0) l[pos[i][j]] = -1;
            else l[pos[i][j]] = pos[i][j - 1];
            if(j == pos[i].size() - 1) r[pos[i][j]] = n;
            else r[pos[i][j]] = pos[i][j + 1];
        }
    for(int i = 1; i < n; i ++)
    {
        ans += (i - (l[i] + 1) - (sum(i-1) - sum(l[i])));
        update(l[i], 1);
    }
    cout << ans << "\n";
}
