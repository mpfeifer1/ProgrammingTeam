#include <iostream>
#include <vector>

using namespace std;

struct Group;
struct Node;

struct Group {
    vector<Node*> nodes;
    int sum = 0;
};

struct Node {
    Group* g = nullptr;
    int index;
};

int main() {
    int integers, commands;
    while(cin >> integers && cin >> commands) {
        vector<Group*> groups;
        vector<Node*> nodes;
        for(int i = 1; i <= integers; i++) {
            Node* n = new Node();
            n->index = i;
            nodes.push_back(n);
            Group* g = new Group();
            g->nodes.push_back(n);
            groups.push_back(g);
            g->sum += i;
            n->g = g;
        }
        for(int i = 0; i < commands; i++) {
            int command;
            cin >> command;



            if(command == 1) {
                // Union
                int num1, num2;
                cin >> num1 >> num2;

                if(num1 == num2) {
                    continue;
                }

                Node* node1 = nodes[num1-1];
                Node* node2 = nodes[num2-1];

                Group* g1 = node1->g;
                Group* g2 = node2->g;
                int size = g2->nodes.size();
                for(int j = 0; j < size; j++) {
                    g2->nodes[j]->g = g1;
                    g1->nodes.push_back(g2->nodes[j]);
                    g1->sum += g2->nodes[j]->index;
                }
                g2->nodes.clear();
                delete g2;
            }



            if(command == 2) {
                // Move
                int num1, num2;
                cin >> num1 >> num2;

                if(num1 == num2) {
                    continue;
                }

                Node* node1 = nodes[num1-1];
                Node* node2 = nodes[num2-1];

                // If they are in the same group
                if(node1->g == node2->g) {
                    continue; // Double check this
                }

                // add node1 to that group
                node2->g->nodes.push_back(node1);
                // update sum of old and new groups
                node1->g->sum -= node1->index;
                node2->g->sum += node1->index;
                // remove node1 from its old group
                for(int j = 0; j < node1->g->nodes.size(); j++) {
                    if(node1->g->nodes[j] == node1) {
                        node1->g->nodes.erase(node1->g->nodes.begin()+j);
                        node1->g = node2->g;
                        break;
                    }
                }
            }



            if(command == 3) {
                // Return sum
                int num;
                cin >> num;
                cout << nodes[num-1]->g->nodes.size() << " " << nodes[num-1]->g->sum << endl;
            }



        }
    }
}
