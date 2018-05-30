// Michael Pfeifer
// Version 04, 2018/02/17

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef unsigned int uint;
typedef unsigned long long ull;

const ld  pi   = 4.0*atanl(1.0);
const int iinf = 1e9 + 10;
const ll  inf  = 1e18 + iinf + 10;
const int mod  = 1000000007;
const ld  prec = .000001;

#define enld endl
#define endl '\n'
#define pb push_back
#define debug(x) cout<<#x<<" -> "<<x<<'\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define uni(x) (x).erase(unique(all(x)), (x).end())
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define rep1(i, n) for (ll i = 1; i <= (ll)(n); ++i)
#define umap unordered_map
#define uset unordered_set

template<class TIn>
using indexed_set = tree<
        TIn, null_type, less<TIn>,
        rb_tree_tag, tree_order_statistics_node_update>;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

void file() {
    auto a = freopen("a.in",  "r", stdin);
    auto b = freopen("a.out", "w", stdout);
    if(!a || !b) cout << "uh oh" << endl;
}




int n, m;

int find(vector<int>& d, int a) {
    if(d[a] == -1) return a;
    return d[a] = find(d, d[a]);
}

void join(vector<int>& d, int a, int b) {
    a = find(d, a);
    b = find(d, b);
    if(a == b) return;
    d[a] = b;
}

int spot(int i, int j) {
    return i*m+j;
}

void solve() {
    vector<vector<int>> v;
    v.resize(n+2, vector<int>(m*4+2, 0));

    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < m; j++) {
            char c;
            cin >> c;
            if(isdigit(c)) {
                c -= '0';
            }
            else {
                c -= 'a';
                c += 10;
            }

            v[i][j*4+1] = (c & (1 << 3)) > 0;
            v[i][j*4+2] = (c & (1 << 2)) > 0;
            v[i][j*4+3] = (c & (1 << 1)) > 0;
            v[i][j*4+4] = (c & (1 << 0)) > 0;
        }
    }

    m *= 4;

    n += 2;
    m += 2;

    /*
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << v[i][j];
        }
        cout << endl;
    }
    */

    // Join all of same color
    vector<int> d(n*m, -1);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(i > 0) {
                if(v[i][j] == v[i-1][j]) {
                    join(d, spot(i,j), spot(i-1,j));
                }
            }
            if(j > 0) {
                if(v[i][j] == v[i][j-1]) {
                    join(d, spot(i,j), spot(i,j-1));
                }
            }
        }
    }

    // Map parent of black to parent of white
    map<int, set<int>> ans;
    for(int i = 1; i < n-1; i++) {
        for(int j = 1; j < m-1; j++) {
            if(v[i][j] == 1) {
                int here = find(d, spot(i,j));

                if(v[i][j-1] == 0) {
                    ans[here].insert(find(d, spot(i,j-1)));
                }
                if(v[i-1][j] == 0) {
                    ans[here].insert(find(d, spot(i-1,j)));
                }
                if(v[i][j+1] == 0) {
                    ans[here].insert(find(d, spot(i,j+1)));
                }
                if(v[i+1][j] == 0) {
                    ans[here].insert(find(d, spot(i+1,j)));
                }
            }
        }
    }

    string all;
    for(auto j : ans) {
        if(j.second.size() == 1) {
            all.pb('W');
        }
        if(j.second.size() == 2) {
            all.pb('A');
        }
        if(j.second.size() == 3) {
            all.pb('K');
        }
        if(j.second.size() == 4) {
            all.pb('J');
        }
        if(j.second.size() == 5) {
            all.pb('S');
        }
        if(j.second.size() == 6) {
            all.pb('D');
        }
    }

    sort(all(all));
    cout << all << endl;
}

int main() {
    //file();
    //fast();

    int cases = 1;
    while(cin >> n && cin >> m && m != 0 && n != 0) {
        cout << "Case " << cases << ": ";
        solve();
        cases++;
    }

    return 0;
}
