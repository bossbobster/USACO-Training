#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

ifstream fin("convention.in");
ofstream fout("convention.out");

long long times[100000];
int n, m, c, minN = 1000000000;

int binarySearch(int l, int r)
{
    int mid = l + (r - l) / 2;
    if(l < r)
    {
        long long cnt = 1, total = 0, prev = times[0], cows = 1;
        for(int i = 1; i < n; i ++)
        {
            total += times[i] - prev;
            cows ++;
            prev = times[i];
            if(total > mid)
            {
                total = 0;
                cnt ++;
                cows = 1;
            }
            if(cows == c && i != n - 1)
            {
                total = 0;
                cnt ++;
                cows = 1;
                prev = times[i + 1];
                i ++;
            }
        }
        if(cnt <= m)
        {
            minN = min(minN, (int)mid);
            return binarySearch(l, mid - 1);
        }
        else
            return binarySearch(mid + 1, r);
    }
    return minN;
}

int main()
{
    fin >> n >> m >> c;
    for(int i = 0; i < n; i ++)
        fin >> times[i];
    sort(times, times + n);
    minN = binarySearch(0, 1000000000);
    long long cnt = 1, total = 0, prev = times[0], cows = 1;
    while(cnt <= m)
    {
        cnt = 1; total = 0; prev = times[0]; cows = 1;
        for(int i = 1; i < n; i ++)
        {
            total += times[i] - prev;
            cows ++;
            prev = times[i];
            if(total > minN)
            {
                total = 0;
                cnt ++;
                cows = 1;
            }
            if(cows == c && i != n - 1)
            {
                total = 0;
                cnt ++;
                cows = 1;
                prev = times[i + 1];
                i ++;
            }
        }
        if(cnt <= m)
            minN --;
    }
    fout << minN + 1;
}
