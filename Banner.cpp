#include <iostream>
#include <algorithm>
using namespace std;

long long gcd(long long l1, long long l2)
{
    if(l1 < l2) swap(l1, l2);
    if(l2 == 0) return l1;
    return gcd(l2, l1 % l2);
}
int main()
{
    long long ans = 0;
    int w, h, l1, l2, curLen;
    cin >> w >> h >> l1 >> l2;
    w ++; h ++;
    l1 *= l1; l2 *= l2;
    if(l1 == 1)
        ans += (w * (h - 1) + (w - 1) * h);
    for(int i = 1; i < w; i ++)
        for(int j = 1; j < h; j ++)
        {
            curLen = i * i + j * j;
            if(curLen >= l1 && curLen <= l2)
                if(gcd(i, j) == 1)
                    ans += (w - i) * (h - j) * 2;
        }
    cout << ans << "\n";
}
