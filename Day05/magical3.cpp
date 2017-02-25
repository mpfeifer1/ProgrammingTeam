#include <iostream>
#include <cmath>

using namespace std;

int main() {
    long long n, m, b;
    cin >> n;
    do {

        if(n == 0) {
            return 0;
        }
    
        n -= 3;
        m = n;
        if(fmod(sqrt(n), 1) == 0) {
            m = sqrt(n);
        }

        if(n == 0) {
            cout << 4 << endl << endl;
        }
        else if(n < 4) {
            cout << "No such base" << endl << endl;
        }

        else if(n % 4 == 0) {
            cout << 4 << endl << endl;
        }
        else if(n % 6 == 0) {
            cout << 6 << endl << endl;
        }
        else if(n % 9 == 0) {
            cout << 9 << endl << endl;
        }


        else {
            while(m % 2 == 0) {
                m /= 2;
            }
            while(m % 3 == 0) {
                m /= 3;
            }
            cout << m << endl << endl;
        }

        b = 4;
        while(n % b) {
            b++;
        }
        cout << n/b << endl;

    } while(cin >> n);
}
