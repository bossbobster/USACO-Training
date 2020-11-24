#include <iostream>
#include <algorithm>
#include <math.h>
#include <map>
#include <set>
using namespace std;
typedef pair<int, int> pii;

int nums[100010];
int order[100010];
set<int> l;
map<int, int> l1;
int main()
{
    int n, minIdx = 0, minN = 2000000000, pre = 0;
    long long ans = 0;
    cin >> n;
    for(int i = 0; i < n; i ++)
        cin >> nums[i];
    for(int i = 0; i < n; i ++)
    {
        pre = pre + nums[i] - 1;
        if(pre < minN)
        {
            minN = pre;
            minIdx = i;
        }
    }
    minIdx = (minIdx + 1) % n;
    for(int i = 0; i < n; i ++)
        order[i] = nums[(i + minIdx) % n];
    for(int i = 0; i < n; i ++)
    {
        if(order[i] != 0) l.insert(i);
        l1[i] += order[i];
        ans += (i - *l.begin()) * (i - *l.begin());
        l1[*l.begin()] --;
        if(l1[*l.begin()] == 0) l.erase(*l.begin());
    }
    cout << ans << "\n";
}
