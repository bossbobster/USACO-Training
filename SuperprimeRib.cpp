/*
 PROB: sprime
 LANG: C++
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

ifstream fin("sprime.in");
ofstream fout("sprime.out");

bool prime = true;
vector<string> primeArr[8];
vector<int> simplePrimeArr;
void calculateSimplePrimeNumbers()
{
    for(int i = 2; i <= 100000; i ++)
    {
        prime = true;
        for(int j = 0; j < simplePrimeArr.size(); j ++)
        {
            if(simplePrimeArr[j] > sqrt(i)) break;
            if(i % simplePrimeArr[j] == 0)
            {
                prime = false;
                break;
            }
        }
        if(prime)
            simplePrimeArr.push_back(i);
    }
}

void calculatePrimeNumbers()
{
    for(int i = 2; i < 10; i ++)
    {
        prime = true;
        for(int j = 0; j < simplePrimeArr.size(); j ++)
        {
            if(simplePrimeArr[j] > sqrt(i)) break;
            if(i % simplePrimeArr[j] == 0)
            {
                prime = false;
                break;
            }
        }
        if(prime)
            primeArr[0].push_back(to_string(i));
    }
    for(int i = 1; i < 8; i ++)
    {
        for(int idx = 0; idx < primeArr[i - 1].size(); idx ++)
        {
            for(char j = '1'; j <= '9'; j ++)
            {
                string temp = primeArr[i - 1][idx] + j;
                prime = true;
                for(int j = 0; j < simplePrimeArr.size(); j ++)
                {
                    if(simplePrimeArr[j] > sqrt(stoi(temp))) break;
                    if(stoi(temp) % simplePrimeArr[j] == 0)
                    {
                        prime = false;
                        break;
                    }
                }
                if(prime)
                    primeArr[i].push_back(temp);
            }
        }
    }
}

int main()
{
    int n;
    fin >> n;
    calculateSimplePrimeNumbers();
    calculatePrimeNumbers();
    for(int i = 0; i < primeArr[n - 1].size(); i ++)
        fout << primeArr[n - 1][i] << "\n";
}
