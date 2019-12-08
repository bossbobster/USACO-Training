#include <iostream>
#include <fstream>
#include <algorithm>
#include <stack>
using namespace std;

ifstream fin("rental.in");
ofstream fout("rental.out");

struct milk
{
    int mx, pr;
};

bool cprRent(int i1, int i2)
{
    return i1 > i2;
}
bool cprMilk(milk m1, milk m2)
{
    return m1.pr > m2.pr;
}

int mlk[100000];
milk prices[100000];
int rentals[100000];
stack<long long> added;
int main()
{
    int n, m, p, t1, t2, curLimit = 0, idx = 0, cur = 0, curAdd = 0, idxRent = 0;
    long long total = 0, maxN = 0;
    bool done = false;
    fin >> n >> m >> p;
    for(int i = 0; i < n; i ++)
        fin >> mlk[i];
    for(int i = 0; i < m; i ++)
    {
        fin >> t1 >> t2;
        prices[i].mx = t1;
        prices[i].pr = t2;
    }
    for(int i = 0; i < p; i ++)
        fin >> rentals[i];
    sort(mlk, mlk + n, cprRent);
    sort(rentals, rentals + p, cprRent);
    sort(prices, prices + m, cprMilk);
    curLimit = prices[idx].mx;
    curAdd = prices[idx].pr;
    for(int i = 0; i < n; i ++)
    {
        cur = mlk[i];
        if(cur < curLimit)
        {
            total += cur * curAdd;
            added.push(cur * curAdd);
            curLimit -= cur;
        }
        else
        {
            long long temp = 0;
            done = false;
            while(cur > curLimit)
            {
                total += curLimit * curAdd;
                temp += curLimit * curAdd;
                cur -= curLimit;
                idx ++;
                if(idx >= m)
                {
                    done = true;
                    break;
                }
                curLimit = prices[idx].mx;
                curAdd = prices[idx].pr;
            }
            if(done)
            {
                added.push(temp);
                for(int j = i + 1; j < n; j ++)
                {
                    total += rentals[j - i - 1];
                    idxRent ++;
                    if(idxRent >= p)
                        break;
                }
                done = false;
                break;
            }
            else
            {
                total += cur * curAdd;
                added.push(cur * curAdd + temp);
                curLimit -= cur;
            }
        }
    }
    maxN = total;
    if(!done)
        for(int i = idxRent; i < p; i ++)
        {
            total -= added.top(); added.pop();
            total += rentals[i];
            maxN = max(maxN, total);
            if(added.empty()) break;
        }
    fout << maxN << endl;
}
