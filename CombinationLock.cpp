
/*
 PROB: combo
 LANG: C++
 */

#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("combo.in");
ofstream fout("combo.out");

int combo1[3];
int combo2[3];
int ogCombo[6];
int terms[3];
int main()
{
    int n, product = 1;
    fin >> n;
    for(int i = 0; i < 3; i ++)
    {
        fin >> combo1[i]; ogCombo[i] = combo1[i];
    }
    for(int i = 0; i < 3; i ++)
    {
        fin >> combo2[i]; ogCombo[i + 3] = combo2[i];
    }
    if(n > 5)
    {
        for(int i = 0; i < 3; i ++)
        {
            if(ogCombo[i] <= n / 4 && ogCombo[i + 3] >= 3 * n / 4)
                ogCombo[i] += n;
            if(ogCombo[i + 3] <= n / 4 && ogCombo[i] >= 3 * n / 4)
                ogCombo[i + 3] += n;
        }
    }
    for(int i = 0; i < 3; i ++)
    {
        if(combo1[i] >= n - 3 && combo2[i] <= 4)
        {
            combo1[i] += 2; combo2[i] -= 2;
        }
        else if(combo2[i] >= n - 3 && combo1[i] <= 4)
        {
            combo2[i] += 2; combo1[i] -= 2;
        }
        else if(combo1[i] < combo2[i])
        {
            combo1[i] += 2; combo2[i] -= 2;
        }
        else
        {
            combo2[i] += 2; combo1[i] -= 2;
        }
        if(combo1[i] > n && combo2[i] <= n / 2)
            combo1[i] = combo1[i] % n;
        if(combo1[i] < 1 && combo2[i] >= n / 2)
            combo1[i] = combo1[i] + n;
        if(combo2[i] > n && combo1[i] <= n / 2)
            combo2[i] = combo2[i] % n;
        if(combo2[i] < 1 && combo1[i] >= n / 2)
            combo2[i] = combo2[i] + n;
    }
    for(int i = 0; i < 3; i ++)
    {
        if(ogCombo[i] < ogCombo[i + 3])
            terms[i] = combo1[i] - combo2[i] + 1;
        else
            terms[i] = combo2[i] - combo1[i] + 1;
        if(terms[i] <= 0)
        {
            product = 0;
            break;
        }
    }
    product = product * terms[0] * terms[1] * terms[2];
    if(n < 5)
        product = 250 - (n * n * n);
    fout << 250 - product << endl;
}

/*
 Executing...
 Test 1: TEST OK [0.004 secs, 1360 KB]
 Test 2: TEST OK [0.004 secs, 1416 KB]
 Test 3: TEST OK [0.004 secs, 1384 KB]
 Test 4: TEST OK [0.004 secs, 1348 KB]
 Test 5: TEST OK [0.004 secs, 1448 KB]
 Test 6: TEST OK [0.004 secs, 1388 KB]
 Test 7: TEST OK [0.004 secs, 1380 KB]
 Test 8: TEST OK [0.004 secs, 1388 KB]
 Test 9: TEST OK [0.004 secs, 1400 KB]
 Test 10: TEST OK [0.004 secs, 1396 KB]
 */
