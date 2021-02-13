#include <iostream>
#include <iomanip>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
#include <bitset>
#include <unordered_set>
using namespace std;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<long long, long long> pll;
#define max(n, m) ((n>m)?n:m)
#define min(n, m) ((n<m)?n:m)
#define f first
#define s second

int main()
{
    long long n;
    cin >> n;
    // (N - 1) choose 3 for all - 4 * (N / 2) choose 3 for the bad cases
    long long ans = (n - 1) * (n - 2) * (n - 3) / 6;
    ans -= 4 * ((n / 2) * (n / 2 - 1) * (n / 2 - 2) / 6);
    cout << ans << "\n";
}
