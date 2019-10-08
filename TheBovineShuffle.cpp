#include <iostream>
#include <set>
using namespace std;

int cows[100000];
int temp[100000];
int shuffles[100000];
set<int> already;
int main()
{
    int n, total = 0, oldTotal = -1;
    cin >> n;
    for(int i = 0; i < n; i ++)
        cows[i] = i + 1;
    for(int i = 0; i < n; i ++)
        cin >> shuffles[i];
    while(true)
    {
        total = 0;
        already.clear();
        for(int i = 0; i < n; i ++)
            temp[i] = cows[i];
        for(int i = 0; i < n; i ++)
        {
            if(temp[i] != 0)
            {
                cows[shuffles[i] - 1] = temp[i];
                if(shuffles[i] - 1 != i && already.find(i + 1) == already.end())
                    cows[i] = 0;
                already.insert(shuffles[i]);
            }
        }
        for(int i = 0; i < n; i ++)
            if(cows[i] > 0)
                total ++;
        if(total == oldTotal)
            break;
        oldTotal = total;
    }
    cout << total;
}
