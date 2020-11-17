// uses the SIEVE OF ERATOSTHENES
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;

vector<long long> findPrimes(long long n)
{
    long long idx = 0, cur = 0, idxCh = 0;
    vector<long long> changes = {2, 4, 2, 4, 6, 2, 6, 4, 2, 4, 6, 6, 2, 6, 4, 2, 6, 4, 6, 8, 4, 2, 4, 2, 4, 8, 6, 4, 6, 2, 4, 6, 2, 6, 6, 4, 2, 4, 6, 2, 6, 4, 2, 4, 2, 10, 2, 10};
    vector<long long> m(n + 5);
    vector<long long> ans;
    vector<long long> all;
    if(n <= 1) return ans;
    ans.push_back(2);
    if(n <= 2) return ans;
    ans.push_back(3);
    if(n <= 4) return ans;
    ans.push_back(5);
    if(n <= 6) return ans;
    ans.push_back(7);
    if(n <= 10) return ans;
    for(int i = 11; i <= n; i ++)
        if(i % 2 != 0 && i % 3 != 0 && i % 5 != 0 && i % 7 != 0)
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
    vector<long long> primes = findPrimes(10000000);
    // WARNING: DO NOT PRINT THEM ALL IF THE NUMBER IS REALLY BIG
    for(int i = 0; i < primes.size(); i ++)
        cout << primes[i] << ((i == ((int)primes.size() - 1))?"\n":", ");
}
