#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <set>
#include <map>
#include <bitset>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define input() ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define f first
#define s second
#pragma GCC optimize("O3,Ofast,unroll-loops")

int nums[310][310];
pii len[10][310], len2[10][310];
int main()
{
    input();
    int n, k, a, b, kB;
    cin >> n >> kB;
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < n; j ++)
            cin >> nums[i][j];
    for(int i = 0; i <= kB; i ++)
        for(int j = 0; j <= n; j ++)
            len[i][j] = len2[i][j] = {-1, -1};
    for(int i = 0; i < n; i ++)
        len[1][i] = {nums[0][i], 0}, len2[1][i] = {nums[i][n-1], n-1};
    k = kB/2;
    for(int i = 2; i <= k; i ++)
        for(int j = 0; j < n; j ++)
            for(int l = 0; l < n; l ++)
            {
                if(len[i-1][l].f+nums[l][j] < len[i][j].f || len[i][j].f == -1)
                    len[i][j] = {len[i-1][l].f+nums[l][j], l};
            }
    k = kB-kB/2;
    for(int i = 2; i <= k; i ++)
        for(int j = 0; j < n; j ++)
            for(int l = 0; l < n; l ++)
            {
                if(len2[i-1][l].f+nums[j][l] < len2[i][j].f || len2[i][j].f == -1)
                    len2[i][j] = {len2[i-1][l].f+nums[j][l], l};
            }
    for(int t = 0; t < n*n; t ++)
    {
        cin >> a >> b; a--; b--;
        bitset<310> all1, all2;
        nums[a][b] = -1;
        
        k = kB/2;
        for(int i = 1; i <= k; i ++)
        {
            all2 = all1;
            all1.reset();
            for(int j = 0; j < n; j ++)
            {
                if(len[i][j].s != -1 && (all2[len[i][j].s] || nums[len[i][j].s][j] == -1))
                {
                    all1[j] = 1;
                    len[i][j] = {-1, -1};
                    for(int l = 0; l < n; l ++)
                    {
                        if(nums[l][j] != -1 && len[i-1][l].f != -1 && (len[i-1][l].f+nums[l][j] < len[i][j].f || len[i][j].f == -1))
                            len[i][j] = {len[i-1][l].f+nums[l][j], l};
                    }
                }
            }
        }
        all1.reset();
        
        
        k = kB-kB/2;
        for(int i = 1; i <= k; i ++)
        {
            all2 = all1;
            all1.reset();
            for(int j = 0; j < n; j ++)
            {
                if(len2[i][j].s != -1 && (all2[len2[i][j].s] || nums[j][len2[i][j].s] == -1))
                {
                    all1[j] = 1;
                    len2[i][j] = {-1, -1};
                    for(int l = 0; l < n; l ++)
                    {
                        if(nums[j][l] != -1 && len2[i-1][l].f != -1 && (len2[i-1][l].f+nums[j][l] < len2[i][j].f || len2[i][j].f == -1))
                            len2[i][j] = {len2[i-1][l].f+nums[j][l], l};
                    }
                }
            }
        }
        
        int ans = 2000000000;
        for(int i = 0; i < n; i ++)
            if(len2[k][i].f != -1 && len[kB-k][i].f != -1)
                ans = min(ans, len2[k][i].f+len[kB-k][i].f);
        cout << ((ans==2000000000)?-1:ans) << '\n';
    }
}
