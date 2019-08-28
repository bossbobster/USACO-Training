/*
 PROB: milk2
 LANG: C++
 */

#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("milk2.in");
ofstream fout("milk2.out");

bool timeVals[1000000];
int main()
{
    int n, start, end, curTrue = 0, curFalse = 0, maxEnd = 0;
    int maxSeg[2]={0,0};
    
    for(int i = 0; i < 1000000; i ++)
        timeVals[i] = false;
    fin >> n;
    for(int i = 0; i < n; i ++)
    {
        fin >> start >> end;
        if(end > maxEnd)
            maxEnd = end;
        for(int i = start; i < end; i ++)
        {
            timeVals[i] = true;
        }
    }
    
    int i=0;
    //skip all false at the beggining
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
 Test 1: TEST OK [0.004 secs, 3728 KB]
 Test 2: TEST OK [0.007 secs, 3804 KB]
 Test 3: TEST OK [0.004 secs, 3724 KB]
 Test 4: TEST OK [0.004 secs, 3804 KB]
 Test 5: TEST OK [0.004 secs, 3816 KB]
 Test 6: TEST OK [0.004 secs, 3900 KB]
 Test 7: TEST OK [0.004 secs, 3808 KB]
 Test 8: TEST OK [0.007 secs, 3828 KB]*/
