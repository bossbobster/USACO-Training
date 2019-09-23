#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

struct cow
{
    string spots;
    int weight;
};

struct interval
{
    long long start, end;
};

bool cpr(cow c1, cow c2)
{
    return c1.weight < c2.weight;
}

cow cows[50000];
interval intervals[50000];
int main()
{
    long long n, a, b, cur = 0, dif = 1, cntI = 0;
    double total = 0;
    cin >> n >> a >> b;
    for(int i = 0; i < n; i ++)
        cin >> cows[i].spots >> cows[i].weight;
    sort(cows, cows + n, cpr);
    if(cows[cur].spots == "S")
    {
        intervals[0].start = 1;
        intervals[0].end = (cows[cur].weight + cows[cur + 1].weight) / 2;
        cur ++;
        cntI ++;
    }
    while(cur < n - 1)
    {
        if(cows[cur].spots == "S")
        {
            if((cows[cur].weight + cows[cur - 1].weight) % 2 == 1)
                intervals[cntI].start = (cows[cur].weight + cows[cur - 1].weight) / 2 + 1;
            else
                intervals[cntI].start = (cows[cur].weight + cows[cur - 1].weight) / 2;
            intervals[cntI].end = (cows[cur].weight + cows[cur + 1].weight) / 2;
            cntI ++;
        }
        cur ++;
    }
    if(cows[cur].spots == "S")
    {
        if((cows[cur].weight + cows[cur - 1].weight) % 2 == 1)
            intervals[cntI].start = (cows[cur].weight + cows[cur - 1].weight) / 2 + 1;
        else
            intervals[cntI].start = (cows[cur].weight + cows[cur - 1].weight) / 2;
        intervals[cntI].end = b;
        cntI ++;
    }
    cur = 0;
    for(int i = 0; i < cntI; i ++)
        if(min(b, intervals[i].end) - max(a, intervals[i].start) >= 0)
        {
            if(i == 0)
                cur += min(b, intervals[i].end) - max(a, intervals[i].start) + 1;
            else
            {
                if(intervals[i - 1].end != intervals[i].start)
                    cur += min(b, intervals[i].end) - max(a, intervals[i].start) + 1;
                if(intervals[i - 1].end == intervals[i].start)
                    cur += min(b, intervals[i].end) - max(a, intervals[i].start);
            }
        }
    cout << cur;
}
