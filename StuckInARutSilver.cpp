// THIS IS THE SILVER VERSION OF THE PROBLEM
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

st nums[1010];
int least[1010];
int blame[1010];
int ans[1010];
vector<inter> inters;
int main()
{
    int n, f, s, cur;
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
    {
        least[i] = 2000000000;
        blame[i] = -1;
    }
    sort(inters.begin(), inters.end());
    for(int i = 0; i < inters.size(); i ++)
    {
        f = inters[i].f; s = inters[i].s;
        if(nums[s].x - nums[f].x == nums[f].y - nums[s].y)
            continue;
        else if (nums[s].x - nums[f].x < nums[f].y - nums[s].y && least[f] >= nums[s].x - nums[f].x && nums[f].y - nums[s].y < least[s])
        {
            least[s] = nums[f].y - nums[s].y;
            blame[s] = f;
        }
        else
            if(least[s] >= nums[f].y - nums[s].y && nums[s].x - nums[f].x < least[f])
            {
                least[f] = nums[s].x - nums[f].x;
                blame[f] = s;
            }
    }
    for(int i = 0; i < n; i ++)
    {
        cur = i;
        while(blame[cur] != -1)
        {
            ans[blame[cur]] ++;
            cur = blame[cur];
        }
    }
    for(int i = 0; i < n; i ++)
        cout << ans[i] << "\n";
}
