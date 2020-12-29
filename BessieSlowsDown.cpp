#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <set>
using namespace std;
typedef pair<int, int> pii;

vector<double> t;
vector<double> d;
int main()
{
    int n, idxT = 0, idxD = 0, cnt = 1;
    double curD = 0, curT = 0, tmp;
    char c;
    cin >> n;
    for(int i = 0; i < n; i ++)
    {
        cin >> c >> tmp;
        if(c == 'T') t.push_back(tmp);
        else d.push_back(tmp);
    }
    sort(t.begin(), t.end());
    sort(d.begin(), d.end());
    while(idxT < t.size() || idxD < d.size())
    {
        if(idxD == d.size() || (idxT < t.size() && (t[idxT] - curT) < (d[idxD] - curD) * cnt))
        {
            curD += (double)(t[idxT] - curT) / (double)cnt;
            curT += (double)(t[idxT] - curT);
            cnt ++;
            idxT ++;
            continue;
        }
        if(idxD != d.size())
        {
            curT += (double)(d[idxD] - curD) * (double)cnt;
            curD += (double)(d[idxD] - curD);
            cnt ++;
            idxD ++;
        }
    }
    curT += (double)(1000 - curD) * (double)cnt;
    cout << (int)(curT + 0.5) << "\n";
}
