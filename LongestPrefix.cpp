#include <iostream>
#include <algorithm>
using namespace std;

string pre[210];
string s;
bool dp[200010];
int main()
{
    int idx = 0, ans = 0;
    string cur;
    cin >> cur;
    while(cur != ".")
    {
        pre[idx] = cur;
        idx ++;
        cin >> cur;
    }
    while(cin >> cur)
        s += cur;
    dp[0] = true;
    for(int i = 1; i <= s.length(); i ++)
        for(int j = 0; j < idx; j ++)
            if(i - pre[j].length() >= 0)
                if(dp[i - pre[j].length()] && s.substr(i - pre[j].length(), pre[j].length()) == pre[j])
                {
                    dp[i] = true;
                    ans = i;
                }
    cout << ans << "\n";
}
