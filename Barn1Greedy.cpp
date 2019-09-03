/*
 PROB: barn1
 LANG: C++
 */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <math.h>
using namespace std;

ifstream fin("barn1.in");
ofstream fout("barn1.out");

int occupied[200];
int differences[199];

int main()
{
    int m, s, c, total = 0;
    fin >> m >> s >> c;
    if(m > c)
        fout << c << endl;
    else
    {
        for (int i = 0; i < c; i ++)
            fin >> occupied[i];
        sort(occupied, occupied + c);
        for (int i = 0; i < c; i ++)
            if(i != 0)
                differences[i - 1] = occupied[i] - occupied[i - 1];
        sort(differences, differences + c - 1, greater<int>());
        for(int i = 0; i < m - 1; i ++)
        {
            total += differences[i];
        }
        fout << occupied[c - 1] - occupied[0] - total + m << endl;
    }
}

/*
 Executing...
 Test 1: TEST OK [0.004 secs, 1412 KB]
 Test 2: TEST OK [0.004 secs, 1416 KB]
 Test 3: TEST OK [0.004 secs, 1376 KB]
 Test 4: TEST OK [0.004 secs, 1368 KB]
 Test 5: TEST OK [0.004 secs, 1372 KB]
 Test 6: TEST OK [0.004 secs, 1388 KB]
 Test 7: TEST OK [0.004 secs, 1396 KB]
 Test 8: TEST OK [0.004 secs, 1384 KB]
 Test 9: TEST OK [0.004 secs, 1348 KB]
 Test 10: TEST OK [0.004 secs, 1372 KB]
 */
