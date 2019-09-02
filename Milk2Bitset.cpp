/*
 PROB: milk2
 LANG: C++
 */

#include <iostream>
#include <fstream>
#include <bitset>
using namespace std;

ifstream fin("milk2.in");
ofstream fout("milk2.out");

bitset<1000000> timeVals;
int main()
{
    int n, start, end, maxEnd = 0;
    int maxSeg[2]={0,0};
    
    for(int i = 0; i < 1000000; i ++)
        timeVals[i] = 0;
    fin >> n;
    for(int i = 0; i < n; i ++)
    {
        fin >> start >> end;
        if(end > maxEnd)
            maxEnd = end;
        for(int i = start; i < end; i ++)
        {
            timeVals[i] = 1;
        }
    }
    
    //skip all false at the beggining
    int i=0;
    while(!timeVals[i])
        i++;
    
    bool curBool = true;
    while(i < maxEnd){
        int curSeg = 0;
        while(i < maxEnd && timeVals[i] == curBool)
        {
            curSeg++;
            i++;
        }
        if(maxSeg[curBool] < curSeg)
            maxSeg[curBool] = curSeg;
        
        curBool = !curBool;
    }
    
    fout << maxSeg[1] << " " << maxSeg[0] << endl;
}

/*
 Executing...
 Test 1: TEST OK [0.004 secs, 2796 KB]
 Test 2: TEST OK [0.007 secs, 2796 KB]
 Test 3: TEST OK [0.007 secs, 2960 KB]
 Test 4: TEST OK [0.007 secs, 2944 KB]
 Test 5: TEST OK [0.038 secs, 2964 KB]
 Test 6: TEST OK [0.004 secs, 2972 KB]
 Test 7: TEST OK [0.007 secs, 2720 KB]
 Test 8: TEST OK [0.011 secs, 3012 KB]
*/
