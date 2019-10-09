#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

struct cow
{
    int h, idx;
};

bool cpr(cow c1, cow c2)
{
    if(c1.h == c2.h)
        return c1.idx < c2.idx;
    return c1.h > c2.h;
}

cow heights[100000];
int og[100000];
int ans[100000];
set<int> higher;
int main()
{
    int n;
    set<int>::iterator first;
    cin >> n;
    for(int i = 0; i < n; i ++)
    {
        cin >> og[i];
        heights[i].h = og[i];
        heights[i].idx = i + 1;
    }
    sort(heights, heights + n, cpr);
    ans[heights[0].idx - 1] = 0;
    higher.insert(heights[0].idx);
    for(int i = 0; i < n; i ++)
    {
        first = higher.lower_bound(heights[i].idx + 1);
        if(first != higher.end())
            ans[heights[i].idx - 1] = *first;
        else
            ans[heights[i].idx - 1] = 0;
        higher.insert(heights[i].idx);
    }
    for(int i = 0; i < n; i ++)
        cout << ans[i] << endl;
}
