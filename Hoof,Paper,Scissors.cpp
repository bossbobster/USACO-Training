#include <iostream>
using namespace std;

struct cuttingPoint
{
    int p1 = 0, h1 = 0, s1 = 0, p2 = 0, h2 = 0, s2 = 0;
};

char ch[100000];
cuttingPoint cp[100000];
int main()
{
    int n, p = 0, h = 0, s = 0, cur = 0, best = 0;
    cin >> n;
    for(int i = 0; i < n; i ++)
    {
        cin >> ch[i];
        switch(ch[i])
        {
            case 'P':
                p ++;
                break;
            case 'H':
                h ++;
                break;
            case 'S':
                s ++;
                break;
        }
        cp[i].p1 = p;
        cp[i].h1 = h;
        cp[i].s1 = s;
    }
    for(int i = 0; i < n; i ++)
    {
        cur = 0;
        cp[i].p2 = cp[n - 1].p1 - cp[i].p1;
        cp[i].h2 = cp[n - 1].h1 - cp[i].h1;
        cp[i].s2 = cp[n - 1].s1 - cp[i].s1;
        if(cp[i].p1 >= cp[i].h1 && cp[i].p1 >= cp[i].s1)
            cur += cp[i].h1 + cp[i].s1;
        else if(cp[i].h1 >= cp[i].p1 && cp[i].h1 >= cp[i].s1)
            cur += cp[i].p1 + cp[i].s1;
        else if(cp[i].s1 >= cp[i].p1 && cp[i].s1 >= cp[i].h1)
            cur += cp[i].p1 + cp[i].h1;
        else
            cur += cp[i].p1 + cp[i].h1;
            
        if(cp[i].p2 >= cp[i].h2 && cp[i].p2 >= cp[i].s2)
            cur += cp[i].h2 + cp[i].s2;
        else if(cp[i].h2 >= cp[i].p2 && cp[i].h2 >= cp[i].s2)
            cur += cp[i].p2 + cp[i].s2;
        else if(cp[i].s2 >= cp[i].p2 && cp[i].s2 >= cp[i].h2)
            cur += cp[i].p2 + cp[i].h2;
        else
            cur += cp[i].p2 + cp[i].h2;
        
        if(n - cur > best)
            best = n - cur;
    }
    cout << best;
}
