#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <cctype>
#include <iomanip>

using namespace std;

int main()
{
    int n, i;
    vector<string> names;
    string s, next;
    cin >> n;
    
        cin >> s;
        cin >> next;
        if (s < next)
        {
            for (int j = 1; j < n-1; j++)
            {
                s = next;
                cin >> next;
                if (!(s < next))
                    {while (j < n-2){j++;cin >> s;}cout << "NEITHER" << endl;
                    
                    return 0;}
            }
            cout << "INCREASING" << endl;
            return 0;
        }
        if (s > next)
        {
            for (int j = 1; j < n-1; j++)
            {
                s = next;
                cin >> next;
                if (!(s > next))
                    {while (j < n-2){j++;cin >> s;}cout << "NEITHER" << endl;return 0;}
            }
            cout << "DECREASING" << endl;
            return 0;
        }
        
    /*
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        names.push_back(s);
    }
    if (names[0] < names[1])
    {
        i = 0;
        while (i < n-1 && names[i] < names[i+1] )
        {
            i++;
        }
        if (i == n-1)
        {
            cout << "INCREASING" << endl;
            return 0;
        }
        else
            cout << "NEITHER" << endl;
    }
    else if (names[0] > names[1])
    {
        i = 0; 
        while (i < n-1 && names[i] > names[i+1] )
        {
            i++;
        }
        if (i == n-1)
        {
            cout << "DECREASING" << endl;
            return 0;
        }
    }
    cout << "NEITHER" << endl;
    
    
    return 0;*/
}
