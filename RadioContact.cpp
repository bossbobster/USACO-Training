#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;

ifstream fin("radio.in");
ofstream fout("radio.out");

pii fj[1010];
pii b[1010];
long long dp[1010][1010];
int dist[1010][1010];
string s1, s2;
int main()
{
    int n, m;
    fin >> n >> m >> fj[0].first >> fj[0].second >> b[0].first >> b[0].second >> s1 >> s2;
    for(int i = 1; i <= n; i ++)
    {
        if(s1[i - 1] == 'N') { fj[i].second = fj[i - 1].second + 1; fj[i].first = fj[i - 1].first; }
        if(s1[i - 1] == 'S') { fj[i].second = fj[i - 1].second - 1; fj[i].first = fj[i - 1].first; }
        if(s1[i - 1] == 'E') { fj[i].second = fj[i - 1].second; fj[i].first = fj[i - 1].first + 1; }
        if(s1[i - 1] == 'W') { fj[i].second = fj[i - 1].second; fj[i].first = fj[i - 1].first - 1; }
    }
    for(int i = 1; i <= m; i ++)
    {
        if(s2[i - 1] == 'N') { b[i].second = b[i - 1].second + 1; b[i].first = b[i - 1].first; }
        if(s2[i - 1] == 'S') { b[i].second = b[i - 1].second - 1; b[i].first = b[i - 1].first; }
        if(s2[i - 1] == 'E') { b[i].second = b[i - 1].second; b[i].first = b[i - 1].first + 1; }
        if(s2[i - 1] == 'W') { b[i].second = b[i - 1].second; b[i].first = b[i - 1].first - 1; }
    }
    for(int i = 0; i <= n; i ++)
        for(int j = 0; j <= m; j ++)
        {
            dist[i][j] = (fj[i].first - b[j].first) * (fj[i].first - b[j].first) + (fj[i].second - b[j].second) * (fj[i].second - b[j].second);
            dp[i][j] = 2000000000;
        }
    dp[0][0] = dist[0][0] * -1;
    for(int i = 0; i <= n; i ++)
        for(int j = 0; j <= m; j ++)
        {
            if(i > 0) dp[i][j] = min(dp[i][j], dp[i - 1][j]);
            if(j > 0) dp[i][j] = min(dp[i][j], dp[i][j - 1]);
            if(i > 0 && j > 0) dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
            dp[i][j] += dist[i][j];
        }
    fout << dp[n][m] << "\n";
}
