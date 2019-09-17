#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

ifstream fin("haybales.in");
ofstream fout("haybales.out");

vector<int> haybales;
int main()
{
    int n, q, bale, left, right;
    fin >> n >> q;
    for(int i = 0; i < n; i ++)
    {
        fin >> bale;
        haybales.push_back(bale);
    }
    sort(haybales.begin(), haybales.begin() + n);
    for(int i = 0; i < q; i ++)
    {
        fin >> left >> right;
        fout << upper_bound(haybales.begin(), haybales.end(), right) -  lower_bound(haybales.begin(), haybales.end(), left) << "\n";
    }
}
