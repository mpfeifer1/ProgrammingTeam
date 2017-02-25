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
    int n;
    ull m;

    cin >> n;
    
    vector<ll> treeStart(n+1, 1);
    vector<ull> arr(n+1);
    
    for ( int i = 0; i < n; i++ )
    {
        cin >> m;
        arr[m] = i;
        //cout << m << " : " << arr[m] << endl;   
    }
    
    Fenwick tree(n, treeStart);
    tree.increase(0, -1);
    
    ull left = 1;
    ull right = n;
    
    for(;;)
    {
        if(left == right) break;
        
        //cerr << left << " : " << arr[left] << endl;
        cout << tree.getsum(0, arr[left]) << endl;
        tree.increase(arr[left++], -1);
        
        if(left == right) break;
        
        //cerr << right << " : " << arr[right] << endl;
        cout << tree.getsum(arr[right]+1, n-1) << endl;
        tree.increase(arr[right--], -1);
        
    }
    
    cout << 0 << endl;

    return 0;
}
