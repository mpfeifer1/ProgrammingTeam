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

struct node {
    bool used = false;
    vector<int> children;
};

int countChildren(vector<node*> boxes, int index) {
    if(boxes[index]->used) {
        return 0;
    }
    boxes[index]->used = true;
    if(boxes[index]->children.size() == 0) {
        return 1;
    }
    
    int sum = 1;
    for(int i = 0; i < boxes[index]->children.size(); i++) {
        sum += countChildren(boxes, boxes[index]->children[i]);
    }
    return sum;
}

int main()
{
    vector<node*> boxes;
    
    int n;
    cin >> n;

    boxes.resize(n);
    for (int i = 0; i < n; i++)
        boxes[i] = new node;
    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        if(temp != 0) {
            boxes[temp-1]->children.push_back(i);
        }
    }
    
    int queries;
    cin >> queries;
    
    int sum;
    for(int j = 0; j < queries; j++) {
        sum = 0;
        int toCheck;
        cin >> toCheck;
        for(int k = 0; k < toCheck; k++) {
            int box;
            cin >> box;
            sum += countChildren(boxes, box-1);
        }
        cout << sum << endl;
        for(auto b : boxes) {
            b->used = false;
        }
    }
    
    return 0;
}
