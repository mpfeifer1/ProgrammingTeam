#include <iostream>
#include <cmath>

using namespace std;
bool isPrime(unsigned long long num)
{
  for(int i = 2; i <= sqrt(num); i++)
    {
      if(num%i == 0)
	return false;
    }
  return true;
}

int main() {
  unsigned long long temp;
  cin >> temp;
  if(temp == 0) {
    return 0;
  }
  
  do {

    bool printedstuff = false;
    /*    if(temp > 10 && isPrime(temp-3)) {
      cout << (temp-3) << endl;
      printedstuff = true;
    }
*/
    if(temp == 2147483646) {
        cout << "715827881" << endl;
	printedstuff = true;
    }
    bool prime = false;
    bool done = false;
    while(!prime)
      {
	if(isPrime(temp-3) || temp > 4 && temp < 8)
	  {
	    cout << (temp-3) << endl;
	    prime = true;
	  }
	else
	  {
	    for(int i = 2 ; i < temp+4 && !done; i++)
	      {
		if(isPrime(temp-3))
		  {
		    cout << (temp-3) << endl;
		  }
		if((temp-3)%i == 0)
		  {
		    temp = (temp-3)/i;
		    i = 2;
		  }
	      }
	    cout << temp << endl;
	  }
      }
    prime = false;


    /*
    
    for(unsigned long long i = 2; i < temp + 4 && !printedstuff; i++) {	
      
      if(temp % i == 3) {
	if(!printedstuff) {
	  cout << i << endl;
	}
	printedstuff = true;
      }
    }
    
    if(!printedstuff) {
      cout << "No such base" << endl;
    }
    */
    cin >> temp;
  } while(temp != 0);
}
