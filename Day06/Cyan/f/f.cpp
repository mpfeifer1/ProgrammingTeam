#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int main()
{
    ifstream fin;
    fin.open("f.in");
    ofstream fout;
    fout.open("f.out");
    ull a[1000][1000];
    int n, m, maxI, maxJ, c = 1;
    fin >> n >> m;
    while (n != 0 || m != 0)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                fin >> a[i][j];
        }
        for (int i = 1; i < n; i++)
            a[i][0] += a[i-1][0];
        for (int i = 1; i < m; i++)
            a[0][i] += a[0][i-1];
        for (int i = 1; i  < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                a[i][j] += max(a[i-1][j], a[i][j-1]);
            }
        }
        fout << "Case " << c++ << ":";
        for (int i = 0; i < n; i++)
            fout << " " << a[i][m-1];
        fout << endl;
        /*
        for (int i = 0; i  < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cerr << a[i][j] << " ";
            }
            cerr << endl;
        }*/
        fin >> n >> m;
    }


    return 0;
}
