#include <iostream>
using namespace std;

string st = "ABCD";

void swap(int p1, int p2)
{
    char a = st[p1];
    st[p1] = st[p2];
    st[p2] = a;
}

void permutations(int depth)
{
    //base case
    if(depth == st.length() - 1)
        cout << st << endl;
    for(int i = depth; i < st.length(); i ++)
    {
        swap(i, depth);
        permutations(depth + 1);
        swap(i, depth);
    }
}

int main()
{
    permutations(0);
}
