#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

void strdiv(string &s, unsigned long long div)
{
    unsigned long long carry = 0;
    unsigned long long l = s.length();
    for (unsigned long long i = 0; i < l; i++)
    {
        unsigned long long curr = carry * 10 + (s[i]-'0');
        unsigned long long temp = (curr)/div;
        carry = (curr) % div;
        s[i] = temp+'0';
    }
    while (s[0] == '0' && s.length() != 1)
    {
        s.erase(0,1);
    }
    
}

int main()
{
    string s;
    getline(cin, s);
    unsigned long long i = 2;
    
    while (s != "1")
    {
        unsigned long long j = i;
        if (j % 10 == 0)
        {
            j/=10;
            s.pop_back();
        }
        if (j != 1)
            strdiv(s, j);
        i++;
    }
    cout << i-1 << endl;
    
    return 0;
}
