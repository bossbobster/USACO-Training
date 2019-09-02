/*
 PROB: skidesign
 LANG: C++
 */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <math.h>
using namespace std;

ifstream fin("skidesign.in");
ofstream fout("skidesign.out");

int nums[1000];
int main()
{
    int n, max = 0, low, high, total = 0, min = 10000000;
    fin >> n;
    for(int i = 0; i < n; i ++)
    {
        fin >> nums[i];
        if(nums[i] > max)
            max = nums[i];
    }
    for(int i = 0; i < max - 16; i ++)
    {
        low = i;
        high = i + 17;
        total = 0;
        for(int j = 0; j < n; j ++)
        {
            if(nums[j] < low)
                total += pow((low - nums[j]), 2);
            if(nums[j] > high)
                total += pow((nums[j] - high), 2);
        }
        if(total < min)
            min = total;
    }
    fout << min << endl;
}

/*
 Executing...
 Test 1: TEST OK [0.004 secs, 1444 KB]
 Test 2: TEST OK [0.004 secs, 1388 KB]
 Test 3: TEST OK [0.004 secs, 1440 KB]
 Test 4: TEST OK [0.004 secs, 1360 KB]
 Test 5: TEST OK [0.004 secs, 1444 KB]
 Test 6: TEST OK [0.000 secs, 1444 KB]
 Test 7: TEST OK [0.004 secs, 1372 KB]
 Test 8: TEST OK [0.000 secs, 1384 KB]
 Test 9: TEST OK [0.004 secs, 1352 KB]
 Test 10: TEST OK [0.004 secs, 1368 KB]
 */
