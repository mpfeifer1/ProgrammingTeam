#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int main()
{
    ifstream fin;
    fin.open("e.in");
    ofstream fout;
    fout.open("e.out");

    int a, b, c;
    int j = 1;
    while(fin >> a && fin >> b && fin >> c) {
        
        if( a == 0 && b==0 && c==0) {
            return 0;
        }
        fout << "Case " << j << ":"<<  endl;
        j++;
        for(int i = 1; i <= c; i++) {
            if(i % a == 0 || i % b == 0) {
                if(i % a == 0) {
                    fout << "Fizz";
                }
                if(i % b ==0) {
                    fout << "Buzz";
                }
            }
            else {
                fout << i;
            }
            fout << endl;
        }
    }

    return 0;
}
