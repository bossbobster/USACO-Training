#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct cow
{
    string og, inc, dec;
};

bool rev(char c1, char c2)
{
    return c1 > c2;
}

cow cows[50000];
vector<string> strI, strD;
int main()
{
    int n;
    string s;
    cin >> n; 
    for(int i = 0; i < n; i ++)
    {
        cin >> cows[i].og;
        sort(cows[i].og.begin(), cows[i].og.end());
        cows[i].inc = cows[i].og;
        sort(cows[i].og.begin(), cows[i].og.end(), rev);
        cows[i].dec = cows[i].og;
    }
    
    for(int i = 0; i < n; i ++)
    {
        strI.push_back(cows[i].inc);
        strD.push_back(cows[i].dec);
    }
    sort(strI.begin(), strI.end());
    sort(strD.begin(), strD.end());
    for(int i = 0; i < n; i ++)
    {
        cout << lower_bound(strD.begin(), strD.end(), cows[i].inc) - strD.begin() + 1 << " " << upper_bound(strI.begin(), strI.end(), cows[i].dec) - strI.begin()<< endl;
    }
}
