#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <iomanip>
#include <cctype>

using namespace std;

int main()
{
    string arr[26] = {"@", "8", "(", "|)", "3", "#", "6", "[-]", "|", "_|", "|<", "1", "[]\\/[]", "[]\\[]", "0", "|D", "(,)", "|Z", "$", "']['", "|_|", "\\/", "\\/\\/", "}{", "`/", "2"};
    
    
    string input;
    getline(cin, input);
    for(int i = 0; i < input.length(); i++) {
        char c = input[i];
        if(isalpha(c)) {
            c = tolower(c);
            cout << arr[c-'a'];
        }
        else {
            cout << c;
            }
    }
    cout << endl;

    return 0;
}
