#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;
#define pii pair<double, int>

ifstream fin("homework.in");
ofstream fout("homework.out");

int scores[100000];
vector<pii> avgs;
int minimums[100000];

bool cpr(pii p1, pii p2)
{
    if(p1.first == p2.first)
        return p1.second > p2.second;
    return p1.first < p2.first;
}

int main()
{
    int ogN, n, idx = 0;
    long long total = 0;
    fin >> n;
    ogN = n;
    for(int i = 0; i < n; i ++)
    {
        fin >> scores[i];
        minimums[i] = scores[i];
        total += scores[i];
    }
    sort(minimums, minimums + n);
    for(int i = 1; i < ogN - 1; i ++)
    {
        n --;
        total -= scores[i - 1];
        if(scores[i - 1] == minimums[idx])
            idx ++;
        avgs.push_back(pii(((double)total - (double)minimums[idx]) / ((double)n - 1), i));
    }
    sort(avgs.begin(), avgs.end(), cpr);
    idx = (int)avgs.size() - 1;
    fout << avgs[idx].second << "\n";
    while(avgs[idx - 1].first == avgs[idx].first)
    {
        idx --;
        fout << avgs[idx].second << "\n";
        if(idx == 0)
            break;
    }
}
