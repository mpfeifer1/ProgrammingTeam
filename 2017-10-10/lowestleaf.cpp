#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct node {
    node* l;
    node* r;
    int n;
};

node* solve(vector<int> postfix, vector<int> infix) {
    // Base case
    if(postfix.size() == 0) {
        return nullptr;
    }

    // Create a new node
    node* n = new node;
    n->n = postfix.back();

    // Find the infix number
    int item = postfix.back();
    int pos = distance(infix.begin(), find(infix.begin(), infix.end(), item));

    // Build 4 new vectors
    vector<int> postL(postfix.begin(), postfix.begin()+pos);
    vector<int> postR(postfix.begin()+pos, postfix.end()-1);

    vector<int> inL(infix.begin(), infix.begin()+pos);
    vector<int> inR(infix.begin()+pos+1, infix.end());

    // Recursively solve
    n->l = solve(postL, inL);
    n->r = solve(postR, inR);

    // Return the tree
    return n;
}

int depth(node* n, int d) {
    if(n == nullptr) {
        return d;
    }

    int md = 0;
    md = max(md, depth(n->l, d+1));
    md = max(md, depth(n->r, d+1));

    return md;
}

int countleaves(node* n, int currdepth, int maxdepth) {
    if(n == nullptr) {
        if(currdepth == maxdepth) {
            return 1;
        }
        return 0;
    }

    int leaves = 0;
    leaves += countleaves(n->l, currdepth+1, maxdepth);
    leaves += countleaves(n->r, currdepth+1, maxdepth);
    return leaves;
}

int main() {
    vector<int> postfix;
    vector<int> infix;
    int tree = 1;

    ifstream fin;
    ofstream fout;
    fin.open("c.in");
    fout.open("c.out");

    int temp;
    while(fin >> temp && temp >= 0) {
        // Print case
        fout << "Tree " << tree << ": ";
        tree++;

        // Read in input
        postfix.push_back(temp);
        while(fin >> temp && temp >= 0) {
            postfix.push_back(temp);
        }
        while(fin >> temp && temp >= 0) {
            infix.push_back(temp);
        }

        // Solve the problem
        node* tree = solve(postfix, infix);
        int d = depth(tree, 0);
        int l = countleaves(tree, 0, d) / 2;

        // Print the answer
        if(l == 1) {
            fout << l << " leaf node on level " << d-1 << endl;
        }
        else {
            fout << l << " leaf nodes on level " << d-1 << endl;
        }

        // Clear out old data
        postfix.clear();
        infix.clear();
    }
}
