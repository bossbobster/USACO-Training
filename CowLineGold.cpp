#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
using namespace std;

long long factorial(long long n)
{
    long long ans = 1;
    if(n == 1) return 1;
    for(int i = 2; i <= n; i ++)
        ans *= i;
    return ans;
}
int nums[30];
bitset<30> used;
vector<int> v;
int main()
{
    long long n, k, cur, ans, x, idx;
    char type;
    cin >> n >> k;
    for(int i = 0; i < k; i ++)
    {
        cin >> type;
        if(type == 'P')
        {
            cin >> cur;
            cur --;
            for(int j = 0; j < n; j ++)
                v.push_back(j + 1);
            for(int j = 0; j < n; j ++)
            {
                x = factorial(n - j - 1);
                cout << v[(int)(cur / x)] << " ";
                v.erase(v.begin() + (int)(cur / x));
                cur %= x;
            }
            cout << "\n";
        }
        else
        {
            ans = 1;
            for(int j = 0; j < n; j ++)
                v.push_back(j + 1);
            for(int j = 0; j < n; j ++)
            {
                cin >> nums[j];
                for(int k = 0; k < v.size(); k ++)
                    if(v[k] == nums[j]) { idx = k; break; }
                ans += idx * factorial(n - j - 1);
                v.erase(v.begin() + idx);
            }
            cout << ans << "\n";
        }
    }
}
