#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int n, steps = 0;
vector<int> nums;

vector<int> sort(vector<int> v)
{
    if(v.size() == 1) return v;
    vector<int> l, r;
    for(int i = 0; i < v.size(); i ++)
    {
        if(i < v.size() / 2) l.push_back(v[i]);
        else r.push_back(v[i]);
    }
    l = sort(l); r = sort(r);
    if(r[0] < l[0])
    {
        steps += (l.size() * (l.size() * 2));
        for(int i = 0; i < l.size(); i ++)
        {
            int tmp = l[i];
            l[i] = r[i];
            r[i] = tmp;
        }
    }
    for(int i = 0; i < l.size(); i ++) v[i] = l[i];
    for(int i = 0; i < r.size(); i ++) v[i + l.size()] = r[i];
    return v;
}

int main()
{
    cin >> n;
    int tmp;
    for(int i = 0; i < pow(2, n); i ++)
    {
        cin >> tmp;
        nums.push_back(tmp);
    }
    nums = sort(nums);
    cout << steps << "\n";
    for(int i = 0; i < nums.size(); i ++)
        cout << nums[i] << "\n";
}
