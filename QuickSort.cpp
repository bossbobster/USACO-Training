//NOT A USACO PROBLEM
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
void swapp(int i1, int i2)
{
    int tmp = nums[i1];
    nums[i1] = nums[i2];
    nums[i2] = tmp;
}

void sort(int left, int right)
{
    if(right - left <= 0) return;
    int pivot = right , idxL = left, idxR = right - 1, p;
    p = nums[pivot];
    while(idxL <= idxR)
    {
        while(nums[idxL] < p ) idxL ++;
        while(nums[idxR] > p && idxR > 0) idxR --;
        if(idxL >= idxR) break;
        swapp(idxL, idxR);
        idxL ++;
        idxR --;
    }
    swapp(idxL, pivot);
    printArr(nums);
    sort(left, idxL-1); sort(idxL + 1, right);
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
    sort(0, n-1);
}
