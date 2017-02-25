#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
#include <cstdio>
#include <iomanip>
#include <queue>
#include <stack>
#include <set>
#include <functional>
#include <map>
#include <fstream>
#include <sstream>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;


struct Fenwick
{
    vector<ll> tree;
    
    Fenwick(int n){tree.resize(n, 0); }
    
    Fenwick(int n, vector<ll> val)
    {
        tree.resize(n, 0);
        for(int i=0; i<n; i++) increase(i, val[i]);
    }    
        
    void increase(int i, ll d)
    {
        for(; i<tree.size(); i|= i+1) tree[i] +=d;
    }
    
    long long sum(int i)
    {
        ll sum = 0;
        for(; i>0; i &= i-1) sum += tree[i-1];
        return sum;
    }
    
    ll getsum(int left, int right)
    {
        return sum(right+1) - sum(left);
    }
};


int main()
{
    ull n, q;
    
    scanf("%lli%lli", &n, &q);
    
    Fenwick wick(n);
    
    char c;
    ll a, b;
    for(ull i=0; i<q; i++)
    {
        scanf("%c", &c);
        scanf("%c", &c);

        switch(c)
        {
            case '+':
                scanf("%lli%lli", &a, &b);
                wick.increase(a, b);
            break;
            case '?':
                scanf("%lli", &a);
                printf("%lli\n", wick.sum(a));
            break;
        }
    }

    return 0;
}
