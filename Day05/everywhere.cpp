#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  int lcount;
  int scount;
  vector<string> strings;
  int locCount;
  vector<string>::iterator it;
  cin >> lcount;

  for(int i = 0; i < lcount; i++)
    {
      cin >> scount;
      for(int j = 0; j < scount; j++)
	{
	  string temp;
	  cin >> temp;
	  bool found = false;
	  for(int k = 0; k < strings.size(); k++) {
	    if(temp == strings[k]) {
	      found = true;
	    }
	  }
	  if(!found) {
	    strings.push_back(temp);
	  }
	}
      cout << strings.size() << endl;
      strings.resize(0);
    }
  
}
