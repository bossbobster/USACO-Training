#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

// pre[i][j] stores min of elements starting at i and of size 2^j
int pre[100010][35];
int nums[100010];

void sparse(int n)
{
    for(int i = 0; i < n; i ++)
        pre[i][0] = nums[i];
    for(int i = 1; i <= floor(log2(n)); i ++)
        for(int j = 0; j <= n - (1 << i); j ++)
            pre[j][i] = min(pre[j][i - 1], pre[j + (1 << (i - 1))][i - 1]);
}

int minQ(int l, int r)
{
    int log = floor(log2(r - l + 1));
    return min(pre[l][log], pre[r - (1 << log) + 1][log]);
}
