//Silver version
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

ifstream fin("sort.in");
ofstream fout("sort.out");

int nums[100010];
int sorted[100010];
int main()
{
    int n, cur, maxN = 0;
    long position1, position2;
    fin >> n;
    for(int i = 0; i < n; i ++)
    {
        fin >> nums[i];
        sorted[i] = nums[i];
    }
    sort(sorted, sorted + n);
    for(int i = 0; i < n; i ++)
    {
        cur = nums[i];
        position1 = lower_bound(sorted, sorted + n, cur) - sorted;
        position2 = upper_bound(sorted, sorted + n, cur) - sorted;
        maxN = max((int)maxN, min((int)(i - position1), (int)(i - position2) + 1));
    }
    fout << maxN + 1;
}
