#include <iostream>
#include <algorithm>
using namespace std;

struct seat
{
    int distance, x, y;
};

bool cpr(seat s1, seat s2)
{
    if(s1.distance != s2.distance)
        return s1.distance < s2.distance;
    if(s1.y != s2.y)
        return s1.y > s2.y;
    return s1.x < s2.x;
}

seat seats[5050];
int final[50][101];
int main()
{
    int w, r;
    cin >> w >> r;
    for(int i = 0; i < r * w; i ++)
    {
        seats[i].distance = (((w + 1) / 2 - 1 - (i % w)) * ((w + 1) / 2 - 1 - (i % w))) + ((r - 1 - i / w) * (r - 1 - i / w));
        seats[i].x = i % w;
        seats[i].y = i / w;
    }
    sort(seats, seats + r * w, cpr);
    for(int i = 0; i < r * w; i ++)
        final[seats[i].y][seats[i].x] = i + 1;
    for(int i = 0; i < r; i ++)
    {
        for(int j = 0; j < w; j ++)
            cout << final[i][j] << " ";
        cout << endl;
    }
}
