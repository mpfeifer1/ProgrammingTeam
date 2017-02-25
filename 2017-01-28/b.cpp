#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
#include <cstdio>
#include <iomanip>
#include <queue>
#include <stack>
#include <set>
#include <functional>
#include <map>
#include <fstream>
#include <sstream>


using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int main()
{

    int n;
  
    while(cin >> n)
    {
        unsigned char isStack = 1;
        unsigned char isQueue = 2;
        unsigned char isPriority = 4;
        
        stack<int> s;
        queue<int> q;
        priority_queue<int> pq;
        
        int type, x;
        
        for(int i=0; i<n; i++)
        {
            cin >> type >> x;
            switch(type)
            {
                case 1:
                    s.push(x);
                    q.push(x);
                    pq.push(x);
                break;
                case 2:
                    if(!s.size())
                    {
                        isStack = 0;
                        isPriority = 0;
                        isQueue = 0;
                    }
                    else
                    {
                        if(s.top() != x) isStack = 0;
                        if(pq.top() != x) isPriority = 0;
                        if(q.front() != x) isQueue = 0;
                        
                        s.pop();
                        q.pop();
                        pq.pop();
                    }
                break;
            }
        }
        
        unsigned char result = isStack | isPriority | isQueue;
        if(result == 1) cout << "stack" << endl;
        else if(result == 2) cout << "queue" << endl;
        else if(result == 4) cout << "priority queue" << endl;
        else if(result == 0) cout << "impossible" << endl;
        else cout << "not sure" << endl;
    }


    return 0;
}
