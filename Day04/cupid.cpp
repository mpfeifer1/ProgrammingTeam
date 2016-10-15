#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <cctype>
#include <iomanip>

using namespace std;

typedef unsigned long long ull;

int main()
{
    int n, m, k, start, end;
    cin >>n >> m >> k;
    int*boys = new int[n];
    int*girls = new int[n];
    bool*used = new bool[n];
    for (int i = 0; i < n; i++)
    {
        cin >> boys[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> girls[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> start >> end;
        
        
        
        for (int i = 0; i < n; i++)
        {
            used[i] = false;
        }
            
        int c = 0;
        bool found = false;
        
        
        for (int i = start; i <= end; i++)
        {
            found = false;
            for (int j = start; j <= end; j++)
            {
                if (!used[j] && boys[j] == girls[j])
                {
                    
                    c++;
                    used[j] = true;
                    break;
                }
            }
        }
        
        cout << c << endl;
    }
    return 0;
}
