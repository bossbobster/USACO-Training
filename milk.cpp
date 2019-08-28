/*
 PROB: milk
 LANG: C++
 */
#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("milk.in");
ofstream fout("milk.out");

int unitsAndPrice[5000][2];
int main()
{
    int n, m, totalP = 0, totalM = 0, minP = 1000000, minPIndex, totUnits;
    fin >> n >> m;
    for(int i = 0; i < m; i ++)
    {
        fin >> unitsAndPrice[i][0] >> unitsAndPrice[i][1];
        if(unitsAndPrice[i][0] < minP)
        {
            minP = unitsAndPrice[i][0];
            minPIndex = i;
        }
    }
    while(totalM < n)
    {
        totUnits = unitsAndPrice[minPIndex][1];
        for(int i = 0; i < totUnits; i ++)
        {
            totalM ++;
            unitsAndPrice[minPIndex][1] --;
            totalP += unitsAndPrice[minPIndex][0];
            if(totalM >= n)
                break;
        }
        minP = 1000000;
        for(int i = 0; i < m; i ++)
        {
            if(unitsAndPrice[i][0] < minP && unitsAndPrice[i][1] != 0)
            {
                minP = unitsAndPrice[i][0];
                minPIndex = i;
            }
        }
    }
    fout << totalP << endl;
}
