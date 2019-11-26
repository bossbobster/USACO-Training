/*
 PROB: frac1
 LANG: C++
*/

#include <iostream>
#include <fstream>
#include <set>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
#define pii pair<int, int>

ifstream fin("frac1.in");
ofstream fout("frac1.out");

struct cpr
{
    bool operator() (pii a, pii b) const
    {
        return (float)a.first / (float)a.second < (float)b.first / (float)b.second;
    }
};

vector<int> primeArr;
bool prime, simple;

void calculatePrimeNumbers()
{
    for(int i = 2; i <= 100; i ++)
    {
        prime = true;
        for(int j = 0; j < primeArr.size(); j ++)
            if(i % primeArr[j] == 0)
            {
                prime = false;
                break;
            }
        if(prime)
            primeArr.push_back(i);
    }
}

pii simplify(pii p)
{
    simple = false;
    while(!simple)
    {
        simple = true;
        for(int i = 0; i < primeArr.size(); i ++)
        {
            if(primeArr[i] > sqrt(min(p.first, p.second)))
                break;
            if(p.first % primeArr[i] == 0 && p.second % primeArr[i] == 0)
            {
                p.first /= primeArr[i];
                p.second /= primeArr[i];
                simple = false;
                break;
            }
        }
    }
    return p;
}

set<pii, cpr> fractions;

int main()
{
    int n;
    fin >> n;
    fractions.insert(pii(0, 1));
    fractions.insert(pii(1, 1));
    calculatePrimeNumbers();
    for(int i = 1; i < n; i ++)
        for(int j = i + 1; j <= n; j ++)
            fractions.insert(simplify(pii(i, j)));
    for(set<pii>::iterator it = fractions.begin(); it != fractions.end(); ++ it)
        fout << it->first << "/" << it->second << "\n";
}
