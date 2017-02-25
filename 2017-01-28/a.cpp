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
    ull n;
    ull m;
    ll inHand = 1;
    cin >> n;
    
    vector<ull> order(n);
    vector<ll> treeStart(n, 1);
    
    for(ull i=0; i<n; i++)
    {
        cin >> m;

        order[m-1] = i;
        
    }
    
    Fenwick tree(n, treeStart);
    
    ull distLeft;
    ull distRight;
    ull moves = 0;
    
    for(int i=0; i<n; i++)
    {
        ull target = order[i];
        if(target > inHand)
        {
            distRight = tree.getsum(inHand, target);
            distLeft = tree.sum(inHand) + tree.getsum(target, n-1) - 1;
        }
        else
        {
            distLeft = tree.getsum(inHand, target);
            distRight = tree.sum(inHand) + tree.getsum(target, n-1) - 1;
        }
        
                
        cerr << "Target ball: " << order[i]+1 << endl;
        cerr << "Ball in hand: " << inHand+1 << endl;
        cerr << "Left: " << distLeft << endl;
        cerr << "Right: " << distRight << endl;
        
        moves += min(distLeft, distRight) + 1;
        tree.increase(target, -1);
        
        int j = order[i];
        do
        {
            j = (j+1)%n;
        }while(tree.getsum(j, j) == 0);
        inHand = j;
               

        
    }
    
    cout << moves << endl;

    return 0;
}
