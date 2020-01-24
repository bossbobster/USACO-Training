#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

ifstream fin("berries.in");
ofstream fout("berries.out");

struct m
{
    int val, og;
};

int berries[1000];
int maxs[1000];
m temp[1000];
vector<int> path;
bool cpr(m m1, m m2)
{
    return m1.val > m2.val;
}
bool cpr1(int i1, int i2)
{
    return i1 > i2;
}
int main()
{
    int n, k, maxN = 0, bask = 0, ans = 0, cur = 0;
    fin >> n >> k;
    for(int i = 0; i < n; i ++)
    {
        fin >> berries[i];
        maxs[i] = berries[i]; maxN = max(maxN, berries[i]);
    }
    for(int i = maxN; i > 0; i --)
    {
        bask = cur = 0; path.clear();
        for(int j = 0; j < n; j ++)
        {
            if(maxs[j] > i)
                maxs[j] --;
            temp[j].val = maxs[j];
            temp[j].og = j;
        }
        sort(temp, temp + n, cpr);
        for(int j = 0; j < n; j ++)
        {
            bask += berries[temp[j].og] / temp[j].val;
            for(int k = 0; k < berries[temp[j].og] / temp[j].val; k ++)
                path.push_back(temp[j].val);
            path.push_back(berries[temp[j].og] % temp[j].val);
            if(bask >= k) break;
        }
        sort(path.begin(), path.end(), cpr1);
        for(int j = k / 2; j < min((int)path.size(), k); j ++)
            cur += path[j];
        ans = max(ans, cur);
    }
    fout << ans << endl;
}
