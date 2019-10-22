#include <iostream>
#include <bitset>
#include <set>
#include <map>
#include <vector>
using namespace std;

struct simpleState
{
    bitset<16> state;
};

struct state
{
    bitset<16> state; int idx;
};

inline bool operator<(const simpleState &b1, const simpleState &b2)
{
    return b1.state.to_ulong() < b2.state.to_ulong();
}

bitset<16> lights;
set<simpleState> previous;
map<simpleState, int> states;
vector<state> prevStates;
int main()
{
    int n, idx = 0, num, found = -1;
    long long b;
    cin >> n >> b;
    for(int i = 0; i < n; i ++)
    {
        cin >> num;
        lights[i] = num;
    }
    simpleState cur2;
    state cur1;
    cur1.state = lights;
    cur1.idx = 0;
    cur2.state = lights;
    states.insert(pair<simpleState, int>(cur2, idx));
    prevStates.push_back(cur1);
    previous.insert(cur2);
    idx ++;
    while(idx < b + 1)
    {
        for(int i = 0; i < n; i ++)
        {
            if(i > 0)
            {
                if(prevStates[idx - 1].state[i - 1])
                    lights[i] = !lights[i];
            }
            else
            {
                if(prevStates[idx - 1].state[n - 1])
                    lights[i] = !lights[i];
            }
        }
        cur2.state = lights;
        cur1.state = lights;
        cur1.idx = idx;
        if(previous.find(cur2) != previous.end())
        {
            found = states.find(cur2)->second;
            break;
        }
        states.insert(pair<simpleState, int>(cur2, idx));
        prevStates.push_back(cur1);
        previous.insert(cur2);
        idx ++;
    }
    if(found != -1)
        for(int i = 0; i < n; i ++)
        {
            if(idx - found > 1)
                cout << prevStates[((b - found) % (idx - found)) + found].state[i] << "\n";
            else
                cout << prevStates[((b - found) % (idx - found)) + found].state[i] << "\n";
        }
    else
        for(int i = 0; i < n; i ++)
            cout << prevStates[idx - 1].state[i] << "\n";
}
