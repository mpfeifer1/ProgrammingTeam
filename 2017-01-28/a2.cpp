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
    
    ll getSum(int left, int right)
    {
        return sum(right+1) - sum(left);
    }
};


int main()
{
    ull n, m;

    cin >> n;
    n++;
    
    vector<ll> treeStart(n, 1);
    vector<ull> arr(n);
    vector<ull> locs(n);
    
    for ( int i = 1; i < n; i++ )
    {
        cin >> m;
        arr[i] = m;
        locs[m] = i;
    }
    
    Fenwick tree(n, treeStart);
    tree.increase(0,-1);
    
    int loc = 1;
    int desired = 0;
    ll moves = 0;
    
    for(int i = 1; i < n; i++)
    {
     //   cout << "Moves: " << moves << endl;

        desired = locs[i];
       //         cout << "alsdfn "  << loc << " " << desired << endl;
        int left = 0, right = 0;
        int mid;
        if(loc < desired)
        {
            mid = tree.getSum(desired, n-1);
            right = tree.getSum(1,loc);// + tree.getSum(desired, n-1);
            left = tree.getSum(loc, desired);
   //                 cout << left << " : " << right << " : " << mid << endl;     
            right += mid;
            left--;
            
            right--;
            
        }
        else if(desired < loc) 
        {
            right = tree.getSum(desired, loc);
            left = tree.getSum(1, desired); //+ tree.getSum(loc, n-1);
            mid = tree.getSum(loc, n-1);;
 //                   cout << left << " : " << right << " : " << mid << endl;     
            left += mid;    
            left--;
            right--;
        }
        
        if(right < left) {
            moves += right;
        }
        else if(left < right) {
            moves += left;
        }
        else
            moves += left;
        

        //cout << "LOC: " << loc << endl;
        //cout << left << " : " << right << endl;
        loc = desired;
        tree.increase(desired, -1);
        
        loc++;
        if(loc >= n ) {
            loc = 1;
        }
        while(tree.getSum(loc,loc) == 0 && loc != desired) {
            loc++;
            if(loc >= n ) {
                loc = 1;
            }
        }

        moves++;
        
    }
    
    cout << moves << endl;

    return 0;
}
