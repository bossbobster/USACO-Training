#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

ifstream fin("auto.in");
ofstream fout("auto.out");

string sorted[1000000];
map<string, int> idx;
vector<int> ans;
int main()
{
    int w, n, after;
    string prefix;
    fin >> w >> n;
    for(int i = 0; i < w; i ++)
    {
        fin >> sorted[i];
        idx.insert(pair<string, int>(sorted[i], i + 1));
    }
    sort(sorted, sorted + w);
    for(int i = 0; i < n; i ++)
    {
        fin >> after >> prefix;
        int idx1 = lower_bound(sorted, sorted + w, prefix) - sorted;
        idx1 += after - 1;
        if(idx1 > w || prefix.length() > sorted[idx1].length() || sorted[idx1].substr(0, prefix.length()) != prefix)
        {
            ans.push_back(-1);
            continue;
        }
        ans.push_back(idx.find(sorted[idx1])->second);
    }
    for(int i = 0; i < ans.size(); i ++)
        fout << ans[i] << "\n";
}
