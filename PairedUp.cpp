#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

struct thing
{
    int val, amount;
};

ifstream fin("pairup.in");
ofstream fout("pairup.out");

bool cpr(thing t1, thing t2)
{
    return t1.val < t2.val;
}

thing cows[100000];

int main()
{
    int n, maxN = 0, idxS = 0, idxE, minN;
    fin >> n;
    idxE = n - 1;
    for(int i = 0; i < n; i ++)
        fin >> cows[i].amount >> cows[i].val;
    sort(cows, cows + n, cpr);
    while(idxS <= idxE)
    {
        minN = min(cows[idxS].amount, cows[idxE].amount);
        maxN = max(maxN, cows[idxS].val + cows[idxE].val);
        cows[idxS].amount -= minN;
        if(idxS != idxE) cows[idxE].amount -= minN;
        if(cows[idxS].amount == 0) idxS ++;
        if(cows[idxE].amount == 0) idxE --;
    }
    fout << maxN << endl;
}
