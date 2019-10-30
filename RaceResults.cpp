#include <iostream>
#include <algorithm>
using namespace std;

struct Time
{
    int h, m, s;
};

bool cpr(Time t1, Time t2)
{
    return (t1.h * 3600 + t1.m * 60 + t1.s) < (t2.h * 3600 + t2.m * 60 + t2.s);
}

Time times[5010];
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i ++)
        cin >> times[i].h >> times[i].m >> times[i].s;
    sort(times, times + n, cpr);
    for(int i = 0; i < n; i ++)
        cout << times[i].h << " " << times[i].m << " " << times[i].s << endl;
}
