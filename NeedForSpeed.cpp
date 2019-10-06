#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct part
{
    int force, mass, idx;
};

bool cpr(part p1, part p2)
{
    return ((double)p1.force / (double)p1.mass) > ((double)p2.force / (double)p2.mass);
}

vector<int> correct;
part parts[10000];
int main()
{
    int f, m, n, nextF, nextM, cor = 0;
    double max;
    cin >> f >> m >> n;
    max = (double)f / (double)m;
    for(int i = 0; i < n; i ++)
    {
        cin >> parts[i].force >> parts[i].mass;
        parts[i].idx = i + 1;
    }
    sort(parts, parts + n, cpr);
    for(int i = 0; i < n; i ++)
    {
        nextF = f + parts[i].force;
        nextM = m + parts[i].mass;
        if((double)nextF / (double)nextM > max)
        {
            correct.push_back(parts[i].idx);
            cor ++;
            max = (double)nextF / (double)nextM;
            f = nextF;
            m = nextM;
        }
        else
            break;
    }
    sort(correct.begin(), correct.end());
    if(cor != 0)
        for(int i = 0; i < cor; i ++)
            cout << correct[i] << endl;
    else
        cout << "NONE";
}
