/*
 PROB: crypt1
 LANG: C++
 */

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

ifstream fin("crypt1.in");
ofstream fout("crypt1.out");

char digs[9];
int n, solutions = 0;

//returns true if nr is composed only of valid digits
bool correctNumber(string nr)
{
    bool found = false;
    for(int i = 0; i < nr.length(); i ++)
    {
        found = false;
        for(int j = 0; j < n; j ++)
        {
            if(nr[i] == digs[j])
                found = true;
        }
        if(!found)
            return false;
    }
    return true;
}

int main()
{
    string num1 = "   ", num2 = "  ", parPro1 = "   ", parPro2 = "   ", total = "     ";
    bool incorrect = false;
    fin >> n;
    for(int i = 0; i < n; i ++)
        fin >> digs[i];
    for(int i = 0; i < n; i ++)
    {
        num1[0] = digs[i];
        for(int j = 0; j < n; j ++)
        {
            num1[1] = digs[j];
            for(int k = 0; k < n; k ++)
            {
                num1[2] = digs[k];
                for(int l = 0; l < n; l ++)
                {
                    num2[0] = digs[l];
                    for(int m = 0; m < n; m ++)
                    {
                        incorrect = false;
                        num2[1] = digs[m];
                        parPro1 = to_string((num2[1] - '0') * stoi(num1));
                        parPro2 = to_string((num2[0] - '0') * stoi(num1));
                        total = to_string(stoi(num1) * stoi(num2));
                        if(parPro1.length() != 3 || parPro2.length() != 3)
                        {
                            incorrect = true;
                            continue;
                        }
                        if(correctNumber(parPro1) == false)
                        {
                            incorrect = true;
                            continue;
                        }
                        if(correctNumber(parPro2) == false)
                        {
                            incorrect = true;
                            continue;
                        }
                        if(correctNumber(total) == false)
                        {
                            incorrect = true;
                            continue;
                        }
                        if(!incorrect)
                            solutions ++;
                    }
                }
            }
        }
    }
    fout << solutions << endl;
}

/*
Executing...
Test 1: TEST OK [0.007 secs, 1392 KB]
Test 2: TEST OK [0.004 secs, 1472 KB]
Test 3: TEST OK [0.004 secs, 1376 KB]
Test 4: TEST OK [0.021 secs, 1404 KB]
Test 5: TEST OK [0.035 secs, 1392 KB]
Test 6: TEST OK [0.011 secs, 1360 KB]
Test 7: TEST OK [0.067 secs, 1468 KB]
*/
