//NOT USACO PROBLEM
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int n;
vector<int> nums;

void printArr(vector<int> v)
{
    for(int i = 0; i < v.size(); i ++)
        cout << v[i] << " ";
    cout << "\n";
}

vector<int> sort(vector<int> v, int left)
{
    if(v.size() == 1) return v;
    vector<int> l, r;
    for(int i = 0; i < v.size(); i ++)
    {
        if(i < ceil((float)v.size() / 2)) l.push_back(v[i]);
        else r.push_back(v[i]);
    }
     l = sort(l, left); r = sort(r, left + ceil((float)v.size() / 2));
    int idxL = 0, idxR = 0, idx = 0;
    while(idxL < l.size() || idxR < r.size())
    {
        if(idxL == l.size())
        {
            v[idx] = r[idxR]; nums[idx + left] = r[idxR];
            idx ++; idxR ++; continue;
        }
        if(idxR == r.size())
        {
            v[idx] = l[idxL]; nums[idx + left] = l[idxL];
            idx ++; idxL ++; continue;
        }
        if(l[idxL] <= r[idxR])
        {
            v[idx] = l[idxL]; nums[idx + left] = l[idxL];
            idx ++; idxL ++;
        }
        else
        {
            v[idx] = r[idxR]; nums[idx + left] = r[idxR];
            idx ++; idxR ++;
        }
    }
    printArr(nums);
    return v;
}

int main()
{
    cin >> n;
    int tmp;
    for(int i = 0; i < n; i ++)
    {
        cin >> tmp;
        nums.push_back(tmp);
    }
    sort(nums, 0);
}
