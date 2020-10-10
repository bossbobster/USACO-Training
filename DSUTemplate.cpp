#include <iostream>
#include <algorithm>
using namespace std;

struct dsu
{
    // parent array
    int par[100000];
    // size array
    int size[100000];
    // constructor
    dsu(int s)
    {
        for(int i = 0; i <= s; i ++)
        {
            par[i] = i; size[i] = 1;
        }
    }
    // find root of n
    int root(int n)
    {
        if(par[n] == n || par[n] == -1)
            return n;
        return par[n] = root(par[n]);
    }
    // return true if n and m are in the same CC
    bool con(int n, int m)
    {
        return (root(n) == root(m));
    }
    // connect n and m
    void un(int n, int m)
    {
        n = root(n); m = root(m);
        if(n == m) return;
        if(size[n] < size[m])
            swap(n, m);
        par[m] = n;
        size[n] += size[m];
    }
};
