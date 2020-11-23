// THIS IS A COUNTER-CLOCKWISE TEMPLATE
#include <iostream>
#include <algorithm>
using namespace std;

struct pt
{
    double x, y;
};

int cp(pt p1, pt p2)
{
    return p1.x * p2.y - p1.y * p2.x;
}

int ccw(pt p1, pt p2, pt p3)
{
    pt p4 = {p2.x - p1.x, p2.y - p1.y};
    pt p5 = {p3.x - p1.x, p3.y - p1.y};
    if(cp(p4, p5) > 0) return 1; // ccw
    return -1; // cw
}
