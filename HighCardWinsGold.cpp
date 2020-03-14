//GOLD VERSION
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

ifstream fin("cardgame.in");
ofstream fout("cardgame.out");

struct els
{
    int val, type;
};

int cpr1(els e1, els e2)
{
    return e1.val < e2.val;
}
int cpr2(els e1, els e2)
{
    return e1.val > e2.val;
}

bool used[100010];
int bessie[100010];
els elsie[100010];
int main()
{
    int n, idx1 = 0, idx2 = 0, total = 0;
    fin >> n;
    for(int i = 0; i < n; i ++)
    {
        fin >> elsie[i].val;
        used[elsie[i].val] = true;
        if(i < n / 2) elsie[i].type = 0;
        else elsie[i].type = 1;
    }
    sort(elsie, elsie + n / 2, cpr2);
    sort(elsie + n / 2, elsie + n, cpr1);
    for(int i = 1; i <= n * 2; i ++)
        if(!used[i])
        {
            bessie[idx2] = i;
            idx2 ++;
        }
    sort(bessie, bessie + n, greater<int>());
    sort(bessie + n / 2, bessie + n);
    idx1 = idx2 = 0;
    while(idx1 < n && idx2 < n)
    {
        if(idx1 == n / 2) idx2 = n / 2;
        if(bessie[idx2] > elsie[idx1].val && elsie[idx1].type == 0)
        {
            idx2 ++;
            total ++;
        }
        else if(bessie[idx2] < elsie[idx1].val && elsie[idx1].type == 1)
        {
            idx2 ++;
            total ++;
        }
        idx1 ++;
    }
    fout << total << endl;
}
