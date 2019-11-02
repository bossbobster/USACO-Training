#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

ifstream fin("lemonade.in");
ofstream fout("lemonade.out");

bool cpr(int i1, int i2)
{
    return i1 > i2;
}

int nums[100010];
int main()
{
    int n, idx = 0;
    fin >> n;
    for(int i = 0; i < n; i ++)
        fin >> nums[i];
    sort(nums, nums + n, cpr);
    while(nums[idx] >= idx)
        idx ++;
    fout << idx << endl;
}
