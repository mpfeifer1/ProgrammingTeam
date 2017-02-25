#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

bool isPrime(ll n)
{
    if (n % 2 == 0 || (long long)n < 2)
        return false;
    
    ll sq = sqrt(n);
    
    for (ll i = 3; i < sq; i+=2)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

ll getNextP(ll n)
{
    if ((long long)n < 2)
        return 2;
    ll i = n+1;
    while (!isPrime(i))
    {
        i++;
    }
    return i;
    
}


int main()
{
    ifstream fin;
    fin.open("z.in");
    ofstream fout;
    fout.open("z.out");
    int c = 1;
    
    ll n;
    while (fin >> n)
    {
        fout <<  "Case " << c++ << ": The next prime after " << (long long)n << " is " << getNextP(n) << "." << endl << endl;
    }

    return 0;
}
