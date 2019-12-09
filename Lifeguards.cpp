#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

ifstream fin("lifeguards.in");
ofstream fout("lifeguards.out");

struct cow
{
    int start, end;
};

bool cpr(cow c1, cow c2)
{
    return c1.start < c2.start;
}

cow cows[100000];
int times[2][100000];
int main()
{
    long long n, cntStarts = 0, cntEnds = 0, num = 0, startTime = 0, totalTime = 0;
    int minN = 2000000000, minN2 = 2000000000;
    fin >> n;
    for(int i = 0; i < n; i ++)
    {
        fin >> times[0][i] >> times[1][i];
        minN2 = min(minN2, times[1][i] - times[0][i]);
        cows[i].start = times[0][i];
        cows[i].end = times[1][i];
    }
    sort(times[0], times[0] + n);
    sort(times[1], times[1] + n);
    sort(cows, cows + n, cpr);
    for(int i = 0; i < n - 1; i ++)
        if(cows[i + 1].end < cows[i].end)
            minN = 0;
    while(cntEnds < n)
    {
        if(cntStarts < n)
            if(times[0][cntStarts] <= times[1][cntEnds])
            {
                if(num == 0) startTime = times[0][cntStarts];
                num ++;
                cntStarts ++;
            }
        if(cntStarts == n || times[1][cntEnds] < times[0][cntStarts])
        {
            num --;
            if(num == 1)
            {
                if(cntStarts < n)
                    minN = min(minN, times[0][cntStarts] - times[1][cntEnds]);
            }
            if(num == 0)
                totalTime += (times[1][cntEnds] - startTime);
            cntEnds ++;
        }
    }
    if(minN == 2000000000) minN = 0;
    fout << totalTime - min(minN, minN2) << endl;
}
