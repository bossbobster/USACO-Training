#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

struct JPI
{
    int joy, price, index;
};

bool cpr(JPI n1, JPI n2)
{
    return (float)n1.joy / (float)n1.price > (float)n2.joy / (float)n2.price;
}

JPI nums[25000];
int main()
{
    int n;
    float sum = 0;
    cin >> n;
    for(int i = 0; i < n; i ++)
    {
        cin >> nums[i].joy >> nums[i].price;
        nums[i].index = i + 1;
    }
    sort(nums, nums + n, cpr);
    sum = nums[0].price + nums[1].price + nums[2].price;
    cout << round(sum) << endl << nums[0].index << endl << nums[1].index << endl << nums[2].index;
}
