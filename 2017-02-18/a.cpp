#include <iostream>
#include <string>
using namespace std;

struct Node {
    bool end = false;
    Node *nexta = nullptr;
    Node *nextb = nullptr;
    Node *nextc = nullptr;
    
};
bool check(Node *curr, int miss, string &s, int n);

int main() {
    int inStrings, afterStrings;
    string temp;
    cin >> inStrings;
    cin >> afterStrings;
    Node *root = new Node();
    Node *curr = root;

    for(int i = 0; i < inStrings; i++)
    {
        cin >> temp;
        for(int j = 0; j < temp.length(); j++) {
            if(temp[j] == 'a') {
                if(curr->nexta != nullptr) {
                    curr = curr->nexta;
                }
                else {
                    curr->nexta = new Node();
                    curr = curr->nexta;
                }
            }
            if(temp[j] == 'b') {
                if(curr->nextb != nullptr) {
                    curr = curr->nextb;
                }
                else {
                    curr->nextb = new Node();
                    curr = curr->nextb;
                }
            }
            if(temp[j] == 'c') {
                if(curr->nextc != nullptr) {
                    curr = curr->nextc;
                }  
                else {
                    curr->nextc = new Node();
                    curr = curr->nextc;
                }
            }
        }
        curr->end = true;
        curr = root;
    }

    for(int i = 0; i<afterStrings; i++) {
        cin >> temp;
        int misses = 0;
        curr = root;
        int n = 0;
        if( check(curr, misses, temp, n))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}

bool check(Node *curr, int miss, string &s, int n) {
    // If too many misses, too bad
    if(miss > 1) {
        return false;
    }

    // If end of string
    if(n == s.length()) {
        // If it's not the end of a word, keep going
        if(!curr->end) {
            return false;
        }
        // If one miss, we win
        if(miss == 1) {
            return true;
        }
        // FML
        if(miss < 1) {
            return false;
        }
    }

    bool valid = false;
    if(curr->nexta != nullptr) {
        if(s[n] != 'a')
            valid = valid || check(curr->nexta, miss+1, s, n+1);
        else
            valid = valid || check(curr->nexta, miss, s, n+1);
    }
    if(curr->nextb != nullptr) {
        if(s[n] != 'b')
            valid = valid || check(curr->nextb, miss+1, s, n+1);
        else
            valid = valid || check(curr->nextb, miss, s, n+1);
    }
    if(curr->nextc != nullptr) {
        if(s[n] != 'c')
            valid = valid || check(curr->nextc, miss+1, s, n+1);
        else
            valid = valid || check(curr->nextc, miss, s, n+1);
   }

    return valid;
}