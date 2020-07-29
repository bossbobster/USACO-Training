#include <iostream>
#include <fstream>
#include <algorithm>
#include <math.h>
using namespace std;
typedef pair<int, int> pii;

ifstream fin("talent.in");
ofstream fout("talent.out");

double dp[1000010];
pii cows[260];
double maxD(double d1, double d2)
{
    if(d1 >= d2) return d1;
    return d2;
}
int main()
{
    int n, c, sum = 0;
    double ans = 0;
    fin >> n >> c;
    for(int i = 0; i < n; i ++)
    {
        fin >> cows[i].second >> cows[i].first;
        sum += cows[i].first;
    }
    for(int i = 1; i <= sum; i ++)
        dp[i] = 2000000000;
    dp[0] = 0;
    for(int i = 0; i < n; i ++)
        for(int j = sum; j >= 0; j --)
            if(j - cows[i].first >= 0)
                if(dp[j - cows[i].first] >= 0)
                    dp[j] = min(dp[j], dp[j - cows[i].first] + cows[i].second);
    for(double i = 0; i <= sum; i ++)
        if(dp[(int)round(i)] > 0 && dp[(int)round(i)] >= c)
            ans = maxD(ans, (double)(i / dp[(int)round(i)]));
    ans *= 1000;
    ans = floor(ans);
    fout << ans << "\n";
}
