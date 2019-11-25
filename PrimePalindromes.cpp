/*
 PROB: pprime
 LANG: C++
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

ifstream fin("pprime.in");
ofstream fout("pprime.out");

string num = "";
int idx = 0, idxP = 0, a, b;
bool prime = false;
vector<int> palindromes;
vector<int> primeArr;
void find(int x, int i)
{
    if(x >= 0)
        for(char j = '0'; j <= '9'; j ++)
        {
            num[x] = num[i - x - 1] = j;
            find(x - 1, i);
            if(x == 0 && num[0] != '0')
                palindromes.push_back(stoi(num));
        }
    return;
}
void findAllPalindromes()
{
    for(int i = 1; i <= 9; i ++)
    {
        num = "";
        find((i - 1) / 2, i);
    }
}
void calculatePrimeNumbers()
{
    for(int i = 2; i <= 100000; i ++)
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

int main()
{
    fin >> a >> b;
    findAllPalindromes();
    sort(palindromes.begin(), palindromes.end());
    calculatePrimeNumbers();
    while(palindromes[idx] <= b && idx < palindromes.size())
    {
        if(palindromes[idx] < a) {idx ++; continue;}
        idxP = 0;
        prime = true;
        while(primeArr[idxP] <= sqrt(palindromes[idx]) && idxP < primeArr.size())
        {
            if(palindromes[idx] % primeArr[idxP] == 0)
            {
                prime = false;
                break;
            }
            idxP ++;
        }
        if(prime)
            fout << palindromes[idx] << "\n";
        idx ++;
    }
}
