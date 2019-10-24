#include <iostream>
using namespace std;

int mirrors[210][3];
short visited[210][2];
//new direction for mirrors with base 4 hashed key;
//old direction idx, mirror (0 = /, 1 = \).
int turns[8] = {3, 2, 2, 3, 1, 0, 0, 1};
int n, a, b, idx = -1, directionIdx = 0, mirrorsIdx = -1, nA = 0, nB = 0;
bool out = false;
void goThrough(int i)
{
    for(int i = 0; i < 210; i ++) {visited[i][0] = false; visited[i][1] = 0;}
    a = b = directionIdx = 0;
    out = false;
    while(!out)
    {
        out = true;
        mirrorsIdx = -1;
        if(directionIdx == 0) nA = nB = 1000000;
        else if(directionIdx == 1) nA = nB = -1000000;
        else if(directionIdx == 2) nA = nB = -1000000;
        else nA = nB = 1000000;
        for(int i = 0; i <= n; i ++)
        {
            if(directionIdx == 0)
            {
                if(mirrors[i][1] == b && mirrors[i][0] > a && visited[i][mirrors[i][2]] < 2)
                    if(mirrors[i][0] < nA) {nA = mirrors[i][0]; nB = mirrors[i][1]; out = false; mirrorsIdx = i;}
            }
            else if(directionIdx == 1)
            {
                if(mirrors[i][1] == b && mirrors[i][0] < a && visited[i][mirrors[i][2]] < 2)
                    if(mirrors[i][0] > nA) {nA = mirrors[i][0]; nB = mirrors[i][1]; out = false; mirrorsIdx = i;}
            }
            else if(directionIdx == 2)
            {
                if(mirrors[i][1] < b && mirrors[i][0] == a && visited[i][mirrors[i][2]] < 2)
                    if(mirrors[i][1] > nB) {nA = mirrors[i][0]; nB = mirrors[i][1]; out = false; mirrorsIdx = i;}
            }
            else
            {
                if(mirrors[i][1] > b && mirrors[i][0] == a && visited[i][mirrors[i][2]] < 2)
                    if(mirrors[i][1] < nB) {nA = mirrors[i][0]; nB = mirrors[i][1]; out = false; mirrorsIdx = i;}
            }
            if(mirrorsIdx == 0) break;
        }
        if(mirrorsIdx == 0)
        {
            if(idx == -1) idx = i;
            break;
        }
        directionIdx = turns[directionIdx * 2 + mirrors[mirrorsIdx][2]];
        a = nA;
        b = nB;
        visited[mirrorsIdx][mirrors[mirrorsIdx][2]] ++;
    }
}
int main()
{
    char temp;
    cin >> n >> a >> b;
    mirrors[0][0] = a; mirrors[0][1] = b;
    for(int i = 0; i < n; i ++)
    {
        cin >> mirrors[i + 1][0] >> mirrors[i + 1][1];
        cin >> temp;
        if(temp == '/') mirrors[i + 1][2] = 0;
        else mirrors[i + 1][2] = 1;
    }
    goThrough(0);
    for(int i = 1; i <= n; i ++)
    {
        mirrors[i][2] = (mirrors[i][2] + 1) % 2;
        goThrough(i);
        mirrors[i][2] = (mirrors[i][2] + 1) % 2;
    }
    cout << idx;
}
