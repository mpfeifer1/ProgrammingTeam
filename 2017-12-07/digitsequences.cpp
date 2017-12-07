#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    int casenum = 1;
    while(cin >> n && n != 0) {
        // Set up storage
        unordered_set<string> seen;
        unordered_map<string, vector<string>> adj;
        unordered_map<string, int> deg;
        unordered_map<string, int> dist;

        // Read input
        for(int i = 0; i < n; i++) {
            string s;
            cin >> s;

            while(s.length() < 5) {
                s = "0" + s;
            }

            deg[s] = 0;
            adj[s] = {};
            dist[s] = 1;
            seen.insert(s);
        }

        // Connect graph
        for(auto i : seen) {
            for(int j = 0; j < 5; j++) {
                string temp = i;
                temp[j]++;
                while(temp[j] <= '9') {
                    if(deg.count(temp) > 0) {
                        adj[i].push_back(temp);
                        deg[temp]++;
                    }
                    temp[j]++;
                }
            }
        }

        // Prepare toposort
        queue<string> zeroin;
        for(auto i : seen) {
            if(deg[i] == 0) {
                zeroin.push(i);
            }
        }

        // Run toposort
        int best = 0;
        while(!zeroin.empty()) {
            string curr = zeroin.front();
            zeroin.pop();

            for(auto i : adj[curr]) {
                dist[i] = max(dist[i], dist[curr]+1);
                best = max(dist[i], best);

                deg[i]--;
                if(deg[i] == 0) {
                    zeroin.push(i);
                }
            }
        }

        // Print answer
        cout << "Case " << casenum << ". " << best << " values" << endl;
        casenum++;
    }
}
