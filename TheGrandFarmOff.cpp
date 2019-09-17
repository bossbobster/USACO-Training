#include <iostream>
#include <algorithm>
using namespace std;

struct cow
{
    long long w, u;
};

long long power(int base, int exponent, int mod)
{
    long long res = 1;
    for(int i = 0; i < exponent; i ++)
        res = (res * base) % mod;
    return res;
}

bool cpr(cow c1, cow c2)
{
    if(c1.u != c2.u)
        return c1.u > c2.u;
    return c1.w < c2.w;
}

cow cows[1500000];
int main()
{
    long long n, a, b, c, d, e, f, g, h, m, total = 0;
    cin >> n >> a >> b >> c >> d >> e >> f >> g >> h >> m;
    for(int i = 0; i < 3 * n; i ++)
    {
        cows[i].w = (((a % d) * power(i, 5, d)) + ((b % d) * power(i, 2, d)) + (c % d)) % d;
        cows[i].u = (((e % h) * power(i, 5, h)) + ((f % h) * power(i, 3, h)) + (g % h)) % h;
    }
    sort(cows, cows + 3 * n, cpr);
    for(int i = 0; i < n; i ++)
        total = (total + cows[i].w) % m;
    cout << total;
}
