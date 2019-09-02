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

int times[2][5000];
int main()
{
    int n,cntStarts = 0,cntEnds = 0,num = 0,startTime,best1 = 0,best2 = 0;
    fin >> n;
    for(int i = 0; i < n; i ++)
    {
        fin >> times[0][i] >> times[1][i];
        if(times[1][i] - times[0][i] > best1)
            best1 = times[1][i] - times[0][i];
    }
    sort(times[0], times[0] + n);
    sort(times[1], times[1] + n);
    while(cntStarts < n)
    {
        if(times[0][cntStarts] <= times[1][cntEnds])
        {
            if(num == 0)
                startTime = times[0][cntStarts];
            cntStarts ++;
            num ++;
        }
        else
        {
            num --;
            if(num == 0)
            {
                if(times[1][cntEnds] - startTime > best1)
                    best1 = times[1][cntEnds] - startTime;
                if(times[0][cntStarts] - times[1][cntEnds] > best2)
                    best2 = times[0][cntStarts] - times[1][cntEnds];
            }
            cntEnds ++;
        }
    }
    fout << best1 << " " << best2 << endl;
}

/*
 Executing...
 Test 1: TEST OK [0.004 secs, 1400 KB]
 Test 2: TEST OK [0.004 secs, 1320 KB]
 Test 3: TEST OK [0.000 secs, 1448 KB]
 Test 4: TEST OK [0.004 secs, 1400 KB]
 Test 5: TEST OK [0.004 secs, 1448 KB]
 Test 6: TEST OK [0.004 secs, 1400 KB]
 Test 7: TEST OK [0.004 secs, 1384 KB]
 Test 8: TEST OK [0.007 secs, 1372 KB]
 */
