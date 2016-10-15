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
    string s, sub, sub2, m;
    int p = -1;
    cin >> s;
    cin >> m;
    int size = s.length();
    for(int i = 0; i< size; i++){
        
        p = m.find_first_of(s, p+1);
        
        
        if(m[p] == s[0]){
            s = s.substr(1, s.length()-1);
        }
        else{
            cout << "FAIL" << endl;
            return 0;
        }
    }
    cout << "PASS" << endl;
    
    return 0;
}
