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
    int start, end;
    string in;
    int cases, count = 0, pcount=0;
    string sub, subCopy;
    bool palin = true;
    cin >> in;
    cin >> cases;
    
    while(count != cases)
    {
        cin >> start >> end;
        start = start-1;
        end = end-1;
        //pcount += end - start;
        for(int i = start; i <= end; i++)
        {
            for(int j = i+1; j <= end; j++)
            {
               //sub = in.substr( i, j-i+1 );
               //cout << sub << endl;
               //subCopy = sub;
               //reverse(subCopy.begin(), subCopy.end());
               //if(sub == subCopy)
                   // pcount++;
                    
                for(int k = i; k <= ((i+j)/2)+1; k++)
                {
                    
                    //cout << in[k] << " " << in[j - k] << endl;
                    if(in[k] != in[j-k+i])
                    { 
                       palin = false;
                       break;
                    }
                }
                    if(palin == true)
                    {
                        
                        //cout << "palin" << endl;
                        pcount++;
                    }
                    palin = true;
            }
                
        }
        pcount += (end-start+1);
    cout << pcount << endl;
    pcount = 0;
    count++;
    }
    return 0;
}
