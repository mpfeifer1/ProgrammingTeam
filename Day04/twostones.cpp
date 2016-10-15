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
    ull n;
   cin >> n;
   cout << (n%2 == 0 ? "Bob" : "Alice" ) << endl;
}
