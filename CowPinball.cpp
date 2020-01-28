#include <iostream>
using namespace std;

int nums[25][25];
int main()
{
    int n, sum, best = 0;
    cin >> n;
    for(int i = 0; i < n; i ++)
        for(int j = 0; j <= i; j ++)
            cin >> nums[i][j];
    for(int i = 1; i < n; i ++)
        for(int j = 0; j <= i; j ++)
        {
            sum = 0;
            if(j < i) sum = max(sum, nums[i - 1][j]);
            if(j > 0) sum = max(sum, nums[i - 1][j - 1]);
            nums[i][j] += sum;
            best = max(best, nums[i][j]);
        }
    cout << best;
}
