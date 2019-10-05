#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

ifstream fin("bcount.in");
ofstream fout("bcount.out");

int counts[100000][3];
int ans[100000][3];
int main()
{
    int n, m, id, left, right;
    fin >> n >> m;
    fin >> id;
    counts[0][id - 1] ++;
    for(int i = 1; i < n; i ++)
    {
        fin >> id;
        counts[i][id - 1] ++;
        counts[i][0] += counts[i - 1][0];
        counts[i][1] += counts[i - 1][1];
        counts[i][2] += counts[i - 1][2];
    }
    for(int i = 0; i < m; i ++)
    {
        fin >> left >> right;
        if(left == 1)
        {
            ans[i][0] = counts[right - 1][0];
            ans[i][1] = counts[right - 1][1];
            ans[i][2] = counts[right - 1][2];
        }
        else
        {
            ans[i][0] = counts[right - 1][0] - counts[left - 2][0];
            ans[i][1] = counts[right - 1][1] - counts[left - 2][1];
            ans[i][2] = counts[right - 1][2] - counts[left - 2][2];
        }
    }
    for(int i = 0; i < m; i ++)
        fout << ans[i][0] << " " << ans[i][1] << " " << ans[i][2] << endl;
}
