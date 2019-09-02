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
    int n, total = 0, low, high, best = 10000000;
    float avg;
    fin >> n;
    for(int i = 0; i < n; i ++)
    {
        fin >> nums[i];
        total += nums[i];
    }
    avg = total / n;
    for(int i = avg - 17; i < avg + 17; i ++)
    {
        total = 0;
        for(int j = 0; j < n; j ++)
        {
            if(nums[j] < i)
                total += pow((i - nums[j]), 2);
            if(nums[j] > i + 17)
                total += pow((nums[j] - i - 17), 2);
        }
        if(total < best)
            best = total;
    }
    fout << best << "\n";
}

/*
 Executing...
 Test 1: TEST OK [0.004 secs, 1384 KB]
 Test 2: TEST OK [0.004 secs, 1380 KB]
 Test 3: TEST OK [0.004 secs, 1372 KB]
 Test 4: TEST OK [0.004 secs, 1340 KB]
 Test 5: TEST OK [0.004 secs, 1416 KB]
 Test 6: TEST OK [0.004 secs, 1444 KB]
 Test 7: TEST OK [0.004 secs, 1416 KB]
 Test 8: TEST OK [0.004 secs, 1356 KB]
 Test 9: TEST OK [0.004 secs, 1392 KB]
 Test 10: TEST OK [0.004 secs, 1404 KB]
*/
