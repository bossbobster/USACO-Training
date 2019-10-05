#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

ifstream fin("highcard.in");
ofstream fout("highcard.out");

int bessie[50000];
int elsie[50000];
int main()
{
    int n, idx1 = 0, idx2 = 0, total = 0;
    fin >> n;
    for(int i = 0; i < n; i ++)
        fin >> elsie[i];
    sort(elsie, elsie + n);
    for(int i = 1; i <= n * 2; i ++)
    {
        if(elsie[idx1] == i)
            idx1 ++;
        else
        {
            bessie[idx2] = i;
            idx2 ++;
        }
    }
    sort(bessie, bessie + n);
    idx1 = idx2 = 0;
    while(idx1 < n && idx2 < n)
    {
        if(bessie[idx2] > elsie[idx1])
        {
            idx1 ++;
            total ++;
        }
        idx2 ++;
    }
    fout << total << endl;
}
