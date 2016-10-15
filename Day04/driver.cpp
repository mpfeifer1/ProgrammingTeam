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
    int n;
    vector<int> toll;
    vector<int> time;
    
    cin >> n;
    
    for(int i = 0; i < n-1; i++) {
        int temp;
        cin >> temp;
        toll.push_back(temp);
    }
    
    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        time.push_back(temp);
    }
    
    int t = 0;
    int pos = 0;
    int end = time[n-1];
    int cost = 0;
    while(pos < n) {
        if(time[pos+1] <= t) {
            cost+=toll[pos];
            //cout << "Added " << toll[pos] << endl;
            pos++;
        }
        else if() {
            
        {
        else {
            cost+=toll[pos-1];
            //cout << "Added " << toll[pos-1] << endl;
            pos--;
        }
        t++;
    }
    cout << cost << endl;
    return 0;
}
