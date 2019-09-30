#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

struct cow
{
    long long pos;
    char breed;
};

bool cpr(cow c1, cow c2)
{
    return c1.pos < c2.pos;
}

int hsh(char c)
{
    if(c == 'G')
        return 1;
    return -1;
}

cow cows[100000];
int nums[100000];
long long first[200001];
long long last[200001];
int main()
{
    long long n, best = 0, f = 0;
    cin >> n;
    for(int i = 0; i <= 2 * n; i ++)
        first[i] = -1;
    for(int i = 0; i < n; i ++)
        cin >> cows[i].pos >> cows[i].breed;
    sort(cows, cows + n, cpr);
    for(int i = 1; i < n; i ++)
    {
        if(cows[i].breed != cows[i - 1].breed) {f = i; continue;}
        if(cows[i].pos - cows[f].pos > best) best = cows[i].pos - cows[f].pos;
    }
    for(int i = 0; i < n; i ++)
    {
        if(i == 0)
            nums[i] = hsh(cows[i].breed);
        else
            nums[i] = nums[i - 1] + hsh(cows[i].breed);
        if(first[nums[i] + n] == -1)
            first[nums[i] + n] = i;
        last[nums[i] + n] = i;
    }
    
    for(int i = 0; i <= 2 * n; i ++)
        if(first[i] != -1 && first[i] != last[i])
            if(cows[last[i]].pos - cows[first[i] + 1].pos > best)
                best = cows[last[i]].pos - cows[first[i] + 1].pos;
    cout << best;
}
