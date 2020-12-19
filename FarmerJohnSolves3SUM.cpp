#include <iostream>
#include <fstream>
#include <algorithm>
#include <math.h>
using namespace std;

ifstream fin("threesum.in");
ofstream fout("threesum.out");

int nums[5010];
unsigned int usin[5010][5010];
unsigned int ans[5010][5010];
int cnt[4000010];
int main()
{
    int n, q, l, r;
    fin >> n >> q;
    for(int i = 0; i < n; i ++)
    {
        fin >> nums[i];
        nums[i] += 1000000;
    }
    for(int i = 0; i < n - 2; i ++)
    {
        cnt[nums[i + 1]] ++;
        for(int j = i + 2; j < n; j ++)
        {
            if(3000000 - nums[i] - nums[j] >= 0 && 3000000 - nums[i] - nums[j] <= 2000000)
                usin[i][j] = cnt[3000000 - nums[i] - nums[j]];
            cnt[nums[j]] ++;
        }
        for(int j = 0; j < n; j ++)
            cnt[nums[j]] = 0;
    }
    for(int i = 2; i < n; i ++)
        for(int j = 0; j < n - i; j ++)
            ans[j][j + i] = ans[j + 1][j + i] + ans[j][j + i - 1] - ans[j + 1][j + i - 1] + usin[j][j + i];
    for(int i = 0; i < q; i ++)
    {
        fin >> l >> r;
        fout << ans[l - 1][r - 1] << "\n";
    }
}
