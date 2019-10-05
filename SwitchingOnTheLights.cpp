#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

ifstream fin("lightson.in");
ofstream fout("lightson.out");

struct room
{
    int x, y;
};
struct light
{
    room first, second;
};

int n, m, total = 0, t1, t2, t3, t4;
light temp;
vector<light> lights;
bool lightOn[201][201];
bool visited[201][201];

bool cpr(light l1, light l2)
{
    if(l1.first.x == l2.first.x)
        return l1.first.y < l2.first.y;
    return l1.first.x < l2.first.x;
}
void findLights(int x, int y)
{
    if(lightOn[x][y] == false || x == 0 || x == n + 1 || y == 0 || y == n + 1)
        return;
    if(visited[x][y] == true)
        return;
    else
        visited[x][y] = true;
    light tmp;
    tmp.first.x = x;
    tmp.first.y = y;
    tmp.second.x = 0;
    tmp.second.y = 0;
    vector<light>::iterator lower = lower_bound(lights.begin(), lights.end(), tmp, cpr);
    while(lower->first.x == x && lower->first.y == y && lower != lights.end())
    {
        lightOn[lower->second.x][lower->second.y] = true;
        if(visited[lower->second.x - 1][lower->second.y] || visited[lower->second.x + 1][lower->second.y] || visited[lower->second.x][lower->second.y - 1] || visited[lower->second.x][lower->second.y + 1])
            findLights(lower->second.x, lower->second.y);
        lower ++;
    }
    findLights(x + 1, y);
    findLights(x - 1, y);
    findLights(x, y + 1);
    findLights(x, y - 1);
}

int main()
{
    fin >> n >> m;
    lightOn[1][1] = true;
    for(int i = 0; i < m; i ++)
    {
        fin >> t1 >> t2 >> t3 >> t4;
        temp.first.x = t1;
        temp.first.y = t2;
        temp.second.x = t3;
        temp.second.y = t4;
        lights.push_back(temp);
    }
    sort(lights.begin(), lights.end(), cpr);
    findLights(1, 1);
    for(int i = 0; i <= n; i ++)
        for(int j = 0; j <= n; j ++)
            total += lightOn[i][j]==true? 1:0;
    fout << total << endl;
}

