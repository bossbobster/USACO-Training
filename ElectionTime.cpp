#include <iostream>
#include <algorithm>
using namespace std;

struct cow
{
    int f, s, idx;
};

bool cpr1(cow c1, cow c2)
{
    return c1.f > c2.f;
}
bool cpr2(cow c1, cow c2)
{
    return c1.s > c2.s;
}

cow cows[50000];
int main()
{
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i ++)
    {
        cin >> cows[i].f >> cows[i].s;
        cows[i].idx = i + 1;
    }
    sort(cows, cows + n, cpr1);
    sort(cows, cows + k, cpr2);
    cout << cows[0].idx;
}
