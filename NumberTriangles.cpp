/*
 PROB: numtri
 LANG: C++
*/

#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

ifstream fin("numtri.in");
ofstream fout("numtri.out");

int trig[1010][1010];

int main()
{
    int n, idx = 1, maxSum = 0;
    fin >> n;
    for(int i = 1; i <= n; i ++)
    {
        for(int j = 1; j <= idx; j ++)
            fin >> trig[i][j];
        idx ++;
    }
    idx = 1;
    for(int i = 1; i <= n; i ++)
    {
        for(int j = 1; j <= idx; j ++)
        {
            trig[i][j] += max(trig[i - 1][j], trig[i - 1][j - 1]);
            maxSum = max(maxSum, trig[i][j]);
        }
        idx ++;
    }
    fout << maxSum << endl;
}
