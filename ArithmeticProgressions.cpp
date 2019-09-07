/*
 PROB: ariprog
 LANG: C++
 */
#include <iostream>
#include <fstream>
#include <algorithm>
#include <bitset>
using namespace std;

ifstream fin("ariprog.in");
ofstream fout("ariprog.out");

bitset<125000> bisquares;
int sequences[10000][2] ;

void calculateBisquares(int num)
{
    for(int i = 0; i <= num; i ++)
    {
        for(int j = i; j <= num; j ++)
        {
            bisquares[(i * i) + (j * j)] = true;
        }
    }
}

bool cpr(int n1[2], int n2[2])
{
    if(n1[1] == n2[1])
        return n1[0] < n2[0];
    return n1[1] < n2[1];
}

int main()
{
    int n, m, seqCnt = 0;
    bool sol = true;
    fin >> n >> m;
    calculateBisquares(m);
    for(int j = 1; j <= (m * m + m * m) / (n - 1); j ++)
    {
        for(int i = 0; i <= m * m + m * m; i ++)
        {
            if(!bisquares[i])
                continue;
            if(i + (n - 1) * j > m * m + m * m)
                break;
            sol = true;
            for(int k = 1; k <= n - 1; k ++)
            {
                if(!bisquares[i + j * k])
                {
                    sol = false;
                    break;
                }
            }
            if(sol)
            {
                sequences[seqCnt][0] = i;
                sequences[seqCnt][1] = j;
                seqCnt ++;
            }
        }
    }
    if(!seqCnt)
        fout << "NONE" << endl;
    else
    {
        for(int i = 0; i < seqCnt; i ++)
            fout << sequences[i][0] << " " << sequences[i][1] << endl;
    }
}

/*
 Executing...
 Test 1: TEST OK [0.004 secs, 1360 KB]
 Test 2: TEST OK [0.004 secs, 1388 KB]
 Test 3: TEST OK [0.004 secs, 1412 KB]
 Test 4: TEST OK [0.004 secs, 1320 KB]
 Test 5: TEST OK [0.018 secs, 1408 KB]
 Test 6: TEST OK [0.137 secs, 1392 KB]
 Test 7: TEST OK [1.680 secs, 1400 KB]
 Test 8: TEST OK [3.840 secs, 1376 KB]
 Test 9: TEST OK [3.367 secs, 1392 KB]
 */
