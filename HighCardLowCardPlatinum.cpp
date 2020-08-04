#include <iostream>
#include <fstream>
#include <algorithm>
#include <set>
#include <iterator>
using namespace std;

ifstream fin("cardgame.in");
ofstream fout("cardgame.out");

int bessie[50010];
int elsie[50010];
int sorted[50010];
int leftWins[50010];
int rightWins[50010];
set<int> bessie2;
int main()
{
    int n = 4, idx1 = 0, idx2 = 0, total = 0, ans = 0;
    fin >> n;
    for(int i = 0; i < n; i ++)
    {
        fin >> elsie[i];
        sorted[i] = elsie[i];
    }
    sort(sorted, sorted + n);
    for(int i = 1; i <= n * 2; i ++)
    {
        if(sorted[idx1] == i)
            idx1 ++;
        else
        {
            bessie[idx2] = i;
            bessie2.insert(bessie[idx2]);
            idx2 ++;
        }
    }
    idx1 = total = 0;
    while(idx1 < n)
    {
        set<int>::iterator it = bessie2.lower_bound(elsie[idx1]);
        if(it == bessie2.end()) bessie2.erase(bessie2.begin());
        else { bessie2.erase(it); total ++; }
        leftWins[idx1] = total;
        idx1 ++;
    }
    idx1 = n - 1;
    total = 0;
    for(int i = 0; i < n; i ++)
        bessie2.insert(bessie[i]);
    while(idx1 >= 0)
    {
        set<int>::iterator it = bessie2.lower_bound(elsie[idx1]);
        set<int>::iterator it2 = bessie2.end();
        it2 --;
        if(*it == *(bessie2.begin())) { rightWins[idx1] = total; idx1 --; bessie2.erase(it2); continue; }
        it --;
        if(*it > *it2) bessie2.erase(it2);
        else { bessie2.erase(it); total ++; }
        rightWins[idx1] = total;
        idx1 --;
    }
    ans = max(leftWins[n - 1], rightWins[0]);
    for(int i = 1; i < n - 1; i ++)
        ans = max(ans, leftWins[i - 1] + rightWins[i]);
    fout << ans << "\n";
}
