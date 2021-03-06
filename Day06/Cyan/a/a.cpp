#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

struct car{
    int back;
    int front;
};

bool collision(car c1, car c2)
{
    c1.front = c1.back + 44;
    c2.front = c2.back + 44;
    if(c1.front >= c2.back)
        return true;
        /*
    if (c1.front >= c2.back && c1.front <= c2.front)
        return true;
    if (c2.front >= c1.back && c2.front <= c1.front)
        return true;*/
    return false;
}

int main()
{
    ifstream fin;
    fin.open("a.in");
    ofstream fout;
    fout.open("a.out");
    int posa, posb;
    bool collisions;
    fin >> posa >> posb;
    
    while(posa != 0 || posb != 0)
      {
	car a, b;
	int time = 0;
	a.back = posa * 10;
	b.back = posb * 10;
	int n = 0, temp;
	bool frontis1 = posa > posb;
        queue<int>c1Times;
        queue<int>c2Times;
	int timechange;
	
	fin >> n;
        for (int i = 0; i < n; i++)
        {
            fin >> temp;
            c1Times.push(temp);
        }
        fin >> n;
        for (int i = 0; i < n; i++)
        {
            fin >> temp;
            c2Times.push(temp);
        }
	bool c1d, c2d;
	while(collisions == false)
	  {
	    if(c1Times.empty() && c2Times.empty())
	      break;
	    if(c1Times.empty() && !c2Times.empty())
	      {
		while(!c2Times.mpty())
		  {
		    if(c2d)
		      {
			timechange = time - c2Times.front();
			a.back += timechang*10;
		      }
		    c2d = !c2d;
		    time = c2Times.front();
		    c2Time.pop();
		  }
	      }
	    if(!c1Times.empty() && c2Times.empty())
	      {
		while(!c1Times.mpty())
		  {
		    if(c1d)
		      {
			timechange = time - c1Times.front();
			b.back += timechange*10;
		      }
		    c1d = !c1d;
		    time = c1Times.front();
		    c1Time.pop();
		  }
	      }

	    if(c1Times.front() < c2Times.front())
	      {
		if(c1d)
		  {
		    timechange = time - c1Times.front();
		    a.back += timechange * 10;
		  }
		c1d = !c1d;
		time = c1Times.front();
		c1Time.pop();
	      }
	    else if(c1Times.front() > c2Times.front())
	      {
		if(c2d)
		  {
		    timechange = time - c2Times.front();
		    b.back += timechange * 10;
		  }
		c2d = !c2d;
		time = c2Times.front();
		c2Time.pop();
	      }
	    if(collision(a, b))
	      {
	       cout << "collision" << endl;
	       break;
	      }
	    
	  }

      }

    












    
    /*
    int c = 1;
    int b1, b2;
    bool frontis1 = true;
    fin >> b1 >> b2;
    while (b1 != 0 || b2 != 0)
    {
        car c1, c2;
        frontis1 = b1 > b2;
        
        c1.back = b1*10;
        c2.back = b2*10;
        
        queue<int>c1Times;
        queue<int>c2Times;
        int n, temp;
        fin >> n;
        for (int i = 0; i < n; i++)
        {
            fin >> temp;
            c1Times.push(temp);
        }
        fin >> n;
        for (int i = 0; i < n; i++)
        {
            fin >> temp;
            c2Times.push(temp);
        }
        
        // have read in times
        int time = 0; // clock
        int c1T = c1Times.front(), c2T = c2Times.front();
        c1Times.pop();
        c2Times.pop(); 
        bool c1D = false, c2D = false; // driving or waiting for each car
        bool broke = false;
        
        while(true)
        {
            int elapsed;
            if (c1Times.empty() && c2Times.empty() && c1D == c2D)
                break;
                
            // Time = min(c1T, c2T) and advance that time
            if (c1T < c2T) 
            {
                elapsed = c1T - time;
                time = c1T;
                if (c1Times.empty())
                    c1T = 1 << 30;
                else
                {
                    c1T = c1Times.front();
                    c1Times.pop();
                }
                c1D = !c1D;
            } 
            
            else if (c1T > c2T)
            {
                elapsed = c2T - time;
                time = c2T;
                
                if (c2Times.empty())
                    c2T = 1 << 30;
                else
                {
                    c2T = c2Times.front();
                    c2Times.pop();
                }
                c2D = !c2D;
            }
            
            else if (c1T == c2T)
            {
                elapsed = c2T - time;
                time = c2T;
                
                if(!c1Times.empty())
                {
                    c1T = c1Times.front();
                    c1Times.pop();
                    c1D = !c1D;
                }
                
                if(!c2Times.empty())
                {
                    c2T = c2Times.front();
                    c2Times.pop();
                    c2D = !c2D;
                }
                
            }   
            
            car t1, t2;
            t1.back = c1.back + (c1D? elapsed*10 : 0);
            t2.back = c2.back + (c2D? elapsed*10 : 0);
            
            if (collision(frontis1?t2:t1, frontis1?t1:t2))
            {
                broke = true;
                break;
            }
            else
            {
                c1 = t1;
                c2 = t2;
            }
        }
        
        fout << "Case " << c++ << ": "; 
        if (!broke)
        {
            //safe and sound
            fout << "safe and sound" << endl;
        }
        else
        {
            // clock
            
            //find collision time
            fout << "bumper tap at time " << time << endl;
        }
        
        fin >> b1 >> b2;
    }


    return 0;*/
}






/*


while (!collision(c1, c2))
        {
            
            // if no more times to start/stop && not still counting
            if (c1Times.empty() && c2Times.empty() && (time > c1T && time > c2T))
                {broke = true;
                break;}
                
            if (c1T == time)
                c1D = !c1D;
            if (c2T == time)
                c2D = !c2D;
            if (c1T == time && !c1Times.empty())
            {   
                c1T = c1Times.front();
                c1Times.pop();
            }
            
            if (c2T == time && !c2Times.empty())
            {   
                c2T = c2Times.front();
                c2Times.pop();
            }
            
            if (c1D)
                c1.back+=10;
            if (c2D)
                c2.back+=10;
            
            time++;
        }
        
        
        
        
        
        */
