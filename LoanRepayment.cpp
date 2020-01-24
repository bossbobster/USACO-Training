#include <iostream>
#include <fstream>
#include <algorithm>
#include <math.h>
using namespace std;

ifstream fin("loan.in");
ofstream fout("loan.out");

long long n, m, k;
long long maxll(long long l1, long long l2)
{
    if(l1 > l2) return l1;
    return l2;
}
long long bs(long long l, long long r)
{
    long long mid = (l + r) / 2;
    long long cur = n, idx = 0;
    if(l < r - 1)
    {
        if(mid <= sqrt(n))
        {
            while(cur > 0 && idx < k)
            {
                long long y = cur / mid;
                y = maxll(y, m);
                cur -= y; idx ++;
            }
        }
        else
        {
            while(cur > 0 && idx < k)
            {
                long long y = cur / mid;
                long long to = mid * y;
                y = maxll(y, m);
                idx += (((cur - to) / y) + 1);
                cur -= ((((cur - to) / y) + 1) * y);
                if(cur <= 0 && idx >= k)
                {
                    cur /= y;
                    if(maxll(abs(cur), idx - k) == idx - k && maxll(abs(cur), idx - k) != abs(cur))
                        cur = 1;
                }
            }
        }
        if(cur <= 0)
        {
            if(mid == l) mid ++;
            return bs(mid, r);
        }
        return bs(l, mid);
    }
    return mid;
}

int main()
{
    fin >> n >> k >> m;
    fout << bs(1, n) << endl;
}
