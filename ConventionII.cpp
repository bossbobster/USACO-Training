#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

ifstream fin("convention2.in");
ofstream fout("convention2.out");

struct cow
{
    int start, duration, seniority;
};

bool cpr(cow c1, cow c2)
{
    return c1.start < c2.start;
}

struct cprQ
{
    bool operator()(cow c1, cow c2)
    {
        return c1.seniority < c2.seniority;
    }
};

priority_queue<cow, vector<cow>, cprQ> cows;
cow cows1[100000];
int main()
{
    int n, time, best = 0, idx = 0, begIdx = 0;
    fin >> n;
    for(int i = 0; i < n; i ++)
    {
        fin >> cows1[i].start >> cows1[i].duration;
        cows1[i].seniority = n - i;
    }
    sort(cows1, cows1 + n, cpr);
    time = cows1[0].start;
    while(idx < n)
    {
        begIdx = idx;
        while(time >= cows1[idx].start && idx < n)
        {
            cows.push(cows1[idx]);
            idx ++;
        }
        if(idx == begIdx && cows.empty())
        {
            cows.push(cows1[idx]);
            time = cows1[idx].start;
            idx ++;
        }
        if(time - cows.top().start > best)
            best = time - cows.top().start;
        time += cows.top().duration;
        cows.pop();
    }
    fout << best << endl;
}
