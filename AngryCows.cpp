//Silver version
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

ifstream fin("angry.in");
ofstream fout("angry.out");

long long cows[50000];
int n, k;
long long maxN = 0, minN = 10000000;

int binarySearch(int l, int r)
{
    long long mid = l + (r - l) / 2;
    if(l < r)
    {
        long long cnt = 1, total = 0, prev = cows[0];
        for(int i = 1; i < n; i ++)
        {
            total += cows[i] - prev;
            prev = cows[i];
            if(total > mid)
            {
                total = 0;
                cnt ++;
            }
        }
        if(cnt <= k)
        {
            minN = min(minN, mid);
            return binarySearch(l, mid - 1);
        }
        else
            return binarySearch(mid + 1, r);
    }
    return minN;
}

int main()
{
    fin >> n >> k;
    bool allSame = true;
    fin >> cows[0];
    for(int i = 1; i < n; i ++)
    {
        fin >> cows[i];
        if(cows[i] > maxN) maxN = cows[i];
        if(cows[i] != cows[i - 1]) allSame = false;
    }
    if(allSame)
    {
        fout << 0;
        return 0;
    }
    sort(cows, cows + n);
    minN = binarySearch(0, maxN);
    long long cnt = 1, total = 0, prev = cows[0];
    while(cnt <= k && minN >= 0)
    {
        cnt = 1; total = 0; prev = cows[0];
        for(int i = 1; i < n; i ++)
        {
            total += cows[i] - prev;
            prev = cows[i];
            if(total > minN)
            {
                total = 0;
                cnt ++;
            }
        }
        if(cnt <= k)
            minN --;
    }
    fout << (minN + 2) / 2 << endl;
}
