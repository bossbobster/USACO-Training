/*
 PROB: milk2
 LANG: C++
 */
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

ifstream fin("milk2.in");
ofstream fout("milk2.out");

struct interval
{
    int startTime, endTime;
};

bool compareStartTimes(interval interval1, interval interval2)
{
    return interval1.startTime < interval2.startTime;
}

interval rawTimes[5000];
interval times[5000];
int main()
{
    int n, size = 0, tr = 0, fa = 0;
    bool added = false;
    fin >> n;
    for(int i = 0; i < n; i ++)
    {
        fin >> rawTimes[i].startTime >> rawTimes[i].endTime;
    }
    sort(rawTimes, rawTimes + n, compareStartTimes);
    for(int i = 0; i < n; i ++)
    {
        added = false;
        for(int j = 0; j < size; j ++)
        {
            if(rawTimes[i].startTime >= times[j].startTime && rawTimes[i].endTime <= times[j].endTime)
            {
                added = true;
                break;
            }
            if(rawTimes[i].startTime <= times[j].endTime && times[j].endTime <= rawTimes[i].endTime)
            {
                times[j].endTime = rawTimes[i].endTime;
                added = true;
                break;
            }
        }
        if(!added)
        {
            times[size].startTime = rawTimes[i].startTime;
            times[size].endTime = rawTimes[i].endTime;
            size ++;
        }
    }
    
    for(int i = 0; i < size; i ++)
    {
        if(times[i].endTime - times[i].startTime > tr)
            tr = times[i].endTime - times[i].startTime;
        if(i < size - 1)
            if(times[i + 1].startTime - times[i].endTime > fa)
                fa = times[i + 1].startTime - times[i].endTime;
    }
    fout << tr << " " << fa << endl;
}
