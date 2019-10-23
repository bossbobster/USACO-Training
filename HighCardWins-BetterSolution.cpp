#include <iostream>
#include <fstream>
#include <bitset>
#include <algorithm>
using namespace std;

ifstream fin("highcard.in");
ofstream fout("highcard.out");

bitset<100000> cows;
int main()
{
    int n, idx1 = 0, idx0 = 0, total = 0, place, already = 0;
    fin >> n;
    for(int i = 0; i < n; i ++)
    {
        fin >> place;
        cows[place - 1] = 1;
    }
    idx1 = idx0 = n;
    place = 0;
    while(idx0 > 0 && place < 2 * n)
    {
        if(cows[place] && idx0)
        {
            idx1 --;
            idx0 --;
            total ++;
            already ++;
        }
        if(!cows[place])
        {
            if(!already) idx0 --;
            if(already) already --;
        }
        place ++;
        
    }
    fout << total << endl;
}
