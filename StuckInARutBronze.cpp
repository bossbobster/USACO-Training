// THIS IS THE BRONZE VERSION (I wanted to see how hard it is)
#include <iostream>
#include <fstream>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
#define max(n, m) ((n>m)?n:m)

struct st
{
    char dir;
    int x, y;
};
struct inter
{
    int f, s, t;
    const bool operator<(const inter& other) const
    {
        return t < other.t;
    }
};

st nums[60];
int ans[60];
vector<inter> inters;
int main()
{
    int n, f, s;
    cin >> n;
    for(int i = 0; i < n; i ++)
        cin >> nums[i].dir >> nums[i].x >> nums[i].y;
    for(int i = 0; i < n; i ++)
    {
        if(nums[i].dir == 'N') continue;
        for(int j = 0; j < n; j ++)
        {
            if(i == j || nums[j].dir == 'E') continue;
            if(nums[i].x < nums[j].x && nums[i].y > nums[j].y)
                inters.push_back({i, j, max(nums[j].x - nums[i].x, nums[i].y - nums[j].y)});
        }
    }
    for(int i = 0; i < n; i ++)
        ans[i] = 2000000000;
    sort(inters.begin(), inters.end());
    for(int i = 0; i < inters.size(); i ++)
    {
        f = inters[i].f; s = inters[i].s;
        if(nums[s].x - nums[f].x == nums[f].y - nums[s].y)
            continue;
        else if (nums[s].x - nums[f].x < nums[f].y - nums[s].y && ans[f] >= nums[s].x - nums[f].x)
            ans[s] = min(ans[s], nums[f].y - nums[s].y);
        else
            if(ans[s] >= nums[f].y - nums[s].y)
                ans[f] = min(ans[f], nums[s].x - nums[f].x);
    }
    for(int i = 0; i < n; i ++)
        cout << ((ans[i]==2000000000)?"Infinity":to_string(ans[i])) << "\n";
}
