// uses the SIEVE OF ERATOSTHENES
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;

vector<long long> findPrimes(long long n)
{
    long long idx = 0, cur = 0, idxCh = 0;
    vector<long long> changes;
    vector<long long> m(n + 5);
    vector<long long> ans;
    vector<long long> all;
    vector<long long> tmp = {2, 3, 5, 7, 11, 13, 17};
    for(int i = 0; i < tmp.size(); i ++)
    {
        if(n <= tmp[i] - 1) return ans;
        if(i != tmp.size() - 1) ans.push_back(tmp[i]);
    }
    int prev = 17;
    for(int i = 18; i < 30100; i ++)
    {
        if(i % 2 != 0 && i % 3 != 0 && i % 5 != 0 && i % 7 != 0 && i % 11 != 0 && i % 13 != 0)
        {
            changes.push_back(i - prev);
            prev = i;
        }
        if(changes.size() == 5760) break;
    }
    for(int i = 17; i <= n; i ++)
        if(i % 2 != 0 && i % 3 != 0 && i % 5 != 0 && i % 7 != 0 && i % 11 != 0 && i % 13 != 0)
        {
            m[i] = (long long)all.size();
            all.push_back(i);
        }
    vector<bool> comp((long long)all.size());
    while(all[idx] * all[idx] < n)
    {
        if(comp[idx]) { idx ++; continue; }
        cur = all[idx] * all[idx];
        idxCh = m[all[idx]];
        for(int i = 0; cur <= n; i ++)
        {
            comp[m[cur]] = true;
            cur += changes[idxCh % (long long)changes.size()] * all[idx];
            idxCh ++;
        }
        idx ++;
    }
    for(int i = 0; i < all.size(); i ++)
        if(!comp[i])
            ans.push_back(all[i]);
    return ans;
}

int main()
{
    vector<long long> primes = findPrimes(3);
    // WARNING: DO NOT PRINT THEM ALL IF THE NUMBER IS REALLY BIG
    cout << primes.size() << " primes: ";
    for(int i = 0; i < primes.size(); i ++)
        cout << primes[i] << ((i == ((int)primes.size() - 1))?"\n":", ");
}
