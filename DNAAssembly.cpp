#include <iostream>
#include <algorithm>
using namespace std;

int n, len = 1000000000;
string dna[10];

int nums[10];
bool used[10];
string cur = "", ans = "", now = "";
void printAll(int n1)
{
    if(n1 == 0)
    {
        ans = dna[cur[0] - '0'];
        for(int i = 1; i < cur.length(); i ++)
        {
            now = dna[cur[i] - '0'];
            bool done = false;
            for(int j = max(0, (int)ans.length() - (int)now.length()); j < ans.length(); j ++)
            {
                bool good = true;
                if(ans[j] == now[0])
                {
                    for(int k = j + 1; k < ans.length(); k ++)
                        if(ans[k] != now[k - j])
                        {
                            good = false;
                            break;
                        }
                    if(good)
                    {
                        done = true;
                        ans += now.substr(ans.length() - j, now.length() - ans.length() + j);
                        break;
                    }
                }
            }
            if(!done) ans += now;
        }
        len = min(len, (int)ans.length());
        return;
    }
    for(int i = 0; i < n; i ++)
    {
        if(used[i]) continue;
        cur[n - n1] = nums[i] + '0';
        used[i] = true;
        printAll(n1 - 1);
        used[i] = false;
    }
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i ++)
    {
        cin >> dna[i];
        nums[i] = i;
        cur += '0';
    }
    printAll(n);
    cout << len;
}
