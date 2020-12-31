#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

char nums[2010];
int main()
{
    int n, idx1, idx2, tmp1, tmp2;
    string ans;
    cin >> n;
    ans.reserve(n);
    idx1 = 0; idx2 = n - 1;
    for(int i = 0; i < n; i ++)
        cin >> nums[i];
    while(idx1 != idx2)
    {
        if(nums[idx1] < nums[idx2])
        {
            ans += nums[idx1];
            idx1 ++;
        }
        else if(nums[idx1] > nums[idx2])
        {
            ans += nums[idx2];
            idx2 --;
        }
        else
        {
            tmp1 = idx1; tmp2 = idx2;
            while(nums[tmp1] == nums[tmp2] && tmp1 < tmp2)
            {
                tmp1 ++;
                tmp2 --;
            }
            if(tmp1 >= tmp2)
            {
                ans += nums[idx1];
                idx1 ++;
            }
            else if(nums[tmp1] < nums[tmp2])
            {
                ans += nums[idx1];
                idx1 ++;
            }
            else
            {
                ans += nums[idx2];
                idx2 --;
            }
        }
    }
    ans += nums[idx1];
    idx1 = 0;
    int tmp;
    while(idx1 < ans.length())
    {
        tmp = idx1 + 80;
        for(int i = idx1; i < min((int)ans.length(), tmp); i ++)
            cout << ans[i];
        idx1 = tmp;
        cout << "\n";
    }
}
