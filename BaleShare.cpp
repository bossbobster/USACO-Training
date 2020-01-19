#include <iostream>
#include <algorithm>
using namespace std;

int bales[20];
bool pos[21][1000][1000];
int n, total = 0, ans = 1000000000;
int main()
{
    cin >> n;
    for(int i = 0; i < n; i ++) { cin >> bales[i]; total += bales[i]; }
    pos[0][0][0] = true;
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < 1000; j ++)
            for(int k = 0; k < 1000; k ++)
                if(pos[i][j][k])
                {
                    pos[i + 1][j][k] = true; 
                    if(j + bales[i] < 1000) pos[i + 1][j + bales[i]][k] = true; 
                    if(k + bales[i] < 1000) pos[i + 1][j][k + bales[i]] = true;
                }
    for(int i = 0; i < 1000; i ++)
        for(int j = 0; j < 1000; j ++)
            if(pos[n][i][j])
                ans = min(ans, max(i, max(j, total - (i + j))));
    cout << ans;
}
