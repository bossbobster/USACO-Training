#include <iostream>
using namespace std;

int n, idx = 1;
bool done = false;
char ans;
void ruler(int n1)
{
    if(done) return;
    if(n1 <= 2) return;
    if(idx == n) { ans = 'm'; done = true; }
    if(idx > n) { ans = 'o'; done = true; }
    ruler(n1 - 1);
    if(done) return;
    idx += n1;
    if(idx == n) { ans = 'm'; done = true; }
    if(idx > n) { ans = 'o'; done = true; }
    ruler(n1 - 1);
}

int main()
{
    cin >> n;
    ruler(100);
    cout << ans;
}
