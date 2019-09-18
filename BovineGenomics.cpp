//using a hash function (also, this is the 'cownomics' silver version)

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

ifstream fin("cownomics.in");
ofstream fout("cownomics.out");

string cows[1000];

int getDigit(char c)
{
    if(c == 'A')
        return 0;
    if(c == 'C')
        return 1;
    if(c == 'G')
        return 2;
    if(c == 'T')
        return 3;
    return 0;
}

int hashFunction(char c1, char c2, char c3)
{
    return (getDigit(c1) * 16 + getDigit(c2) * 4 + getDigit(c3));
}

bool spot[64];
int main()
{
    int n, m, total = 0;
    bool ans = true;
    fin >> n >> m;
    for(int i = 0; i < n * 2; i ++)
        fin >> cows[i];
    for(int i = 0; i < m - 2; i ++)
    {
        for(int j = i + 1; j < m - 1; j ++)
        {
            for(int k = j + 1; k < m; k ++)
            {
                for(int x = 0; x < 64; x ++)
                    spot[x] = false;
                for(int l = 0; l < n; l ++)
                    spot[hashFunction(cows[l][i], cows[l][j], cows[l][k])] = true;
                ans = true;
                for(int l = n; l < n * 2; l ++)
                {
                    if(spot[hashFunction(cows[l][i], cows[l][j], cows[l][k])])
                    {
                        ans = false;
                        break;
                    }
                }
                if(ans)
                    total ++;
            }
        }
    }
    fout << total;
}
