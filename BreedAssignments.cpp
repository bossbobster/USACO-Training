#include <iostream>
#include <tuple>
using namespace std;

int n, k, ans = 0;
int cur[20];
tuple<char, int, int> conditions[50];

void findAll(int pos)
{
    if(pos == n)
    {
        bool bad = false;
        for(int i = 0; i < k; i ++)
        {
            if(get<0>(conditions[i]) == 'S')
            {
                if(cur[get<1>(conditions[i])] != cur[get<2>(conditions[i])]) { bad = true; break; }
            }
            else
            {
                if(cur[get<1>(conditions[i])] == cur[get<2>(conditions[i])]) { bad = true; break; }
            }
        }
        if(!bad) ans ++;
        return;
    }
    cur[pos] = 0;
    findAll(pos + 1);
    cur[pos] = 1;
    findAll(pos + 1);
    cur[pos] = 2;
    findAll(pos + 1);
}

int main()
{
    cin >> n >> k;
    char c;
    int n1, n2;
    for(int i = 0; i < k; i ++)
    {
        cin >> c >> n1 >> n2;
        conditions[i] = make_tuple(c, n1, n2);
    }
    findAll(0);
    cout << ans;
}
