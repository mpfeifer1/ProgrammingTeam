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
    int count = 0;
    int scores[26] = {0};
    string rw;
    vector<int>right;
    
    char c;
    int t;
     
     cin >> t;
     while (t >= 0)
     {
        cin >> c >> rw;
        if (rw == "right")
        {
            scores[c-'A'] += t;
            right.push_back(scores[c-'A']);
        }
        else
        scores[c-'A'] += 20;
        cin >> t;
     }
    t = 0; 
     cout << right.size();
     for (int i = 0; i < right.size(); i++)
     {
        t += right[i];
    }
    cout << " " << t << endl;
    
    return 0;
}
