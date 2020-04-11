#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, s, e, ans = 0;
bool good = false;
string expressions[20];
vector<int> ex[20];
int counts[10];
string cur = "";
void printAll(int n1)
{
    for(int i = 0; i < s; i ++)
    {
        counts[cur[n - n1 - 1] - '0'] --;
        cur[n - n1 - 1] = i + '1';
        counts[cur[n - n1 - 1] - '0'] ++;
        if(n1 != 0) printAll(n1 - 1);
        else 
        {
            for(int i = 0; i < e; i ++)
            {
                good = true;
                for(int j = 0; j < ex[i].size(); j += 2)
                    if(counts[ex[i][j + 1]] < ex[i][j])
                    {
                        good = false; break;
                    }
                if(good) break;
            }
            if(good) ans ++;
        }
    }
}

int main()
{
    cin >> n >> s >> e;
    for(int i = 0; i < e; i ++)
        cin >> expressions[i];
    for(int i = 0; i < e; i ++)
        for(int j = 0; j < expressions[i].length(); j += 2)
            ex[i].push_back(expressions[i][j] - '0');
    printAll(n - 1);
    cout << ans << endl;
}
