#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int times;
    cin >> times;
    for(int i = 0; i < times; i++) {
        int votes, max = 0, nextMax = 0;
        int maxLocation = 0, total = 0;
        cin >> votes;
        bool tied = false;
        for(int j = 0; j < votes; j++) {
            int temp;
            cin >> temp;
            total += temp;
            if(temp > max) {
                nextMax = max;
                max = temp;
                tied = false;
                maxLocation = j;
            }
            else if(temp == max) {
                tied = true;
            }
        }
        if(tied) {
            cout << "no winner" << endl;
        }
        else {
            if(max * 2 > total) {
                cout << "majority winner ";
            }
            else {
                cout << "minority winner ";
            }
            cout << maxLocation + 1 << endl;
        }
    }
}
