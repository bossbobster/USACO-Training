#include <iostream>
#include <algorithm>
using namespace std;

int l, n;
bool done = false;
string nums[30];
string goal, ans;
void find(string s)
{
    if(done) return;
    int pos = s.length();
    if(pos == l)
    {
        cout << s << endl;
        done = true;
        return;
    }
    for(int i = 0; i < n; i ++)
    {
        int len = nums[i].length();
        if(pos + len > goal.length()) continue;
        bool good = true;
        for(int j = 0; j < len; j ++)
        {
            if(goal[j + pos] == '?') continue;
            if(goal[j + pos] != nums[i][j]) { good = false; break; }
        }
        if(good) find(s + nums[i]);
        if(done) return;
    }
}

int main()
{
    cin >> l >> n >> goal;
    for(int i = 0; i < n; i ++)
        cin >> nums[i];
    sort(nums, nums + n);
    find("");
    if(!done) cout << "NO SOLUTION" << endl;
}
