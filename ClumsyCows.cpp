#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

ifstream fin("clumsy.in");
ofstream fout("clumsy.out");

short para[100000];
int main()
{
    string p;
    int total = 0, num = 0;
    fin >> p;
    for(int i = 0; i < p.length(); i ++)
    {
        if(p[i] == '(') para[i] = 1;
        else para[i] = -1;
    }
    for(int i = 0; i < p.length(); i ++)
    {
        num += para[i];
        if(num == -1)
        {
            total ++;
            num += 2;
        }
    }
    total += num / 2;
    fout << total;
}
