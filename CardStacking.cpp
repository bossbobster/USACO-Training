#include <iostream>
#include <deque>
#include <algorithm>
#include <vector>
using namespace std;

deque<int> cards;
vector<int> bessie;
int main()
{
    int n, k, p, idx = 0;
    cin >> n >> k >> p;
    for(int i = 0; i < k; i ++)
        cards.push_back(i + 1);
    while(!cards.empty())
    {
        if(idx == n - 1)
            bessie.push_back(cards.front());
        cards.pop_front();
        for(int i = 0; i < p; i ++)
        {
            cards.push_back(cards.front());
            cards.pop_front();
        }
        idx = (idx + 1) % n;
    }
    sort(bessie.begin(), bessie.end());
    for(int i = 0; i < bessie.size(); i ++)
        cout << bessie[i] << endl;
}
