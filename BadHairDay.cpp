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
        return c1.idx > c2.idx;
    return c1.h > c2.h;
}

cow heights[100000];
int og[100000];
set<int> higher;
int main()
{
    int n, first;
    long long total = 0;
    cin >> n;
    for(int i = 0; i < n; i ++)
    {
        cin >> og[i];
        heights[i].h = og[i];
        heights[i].idx = i + 1;
    }
    sort(heights, heights + n, cpr);
    total += (n - heights[0].idx);
    higher.insert(heights[0].idx);
    for(int i = 1; i < n; i ++)
    {
        first = *higher.lower_bound(heights[i].idx + 1);
        if(first - heights[i].idx - 1 >= 0)
            total += (first - heights[i].idx - 1);
        else
            total += (n - heights[i].idx);
        higher.insert(heights[i].idx);
    }
    cout << total;
}
