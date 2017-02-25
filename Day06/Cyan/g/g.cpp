#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

struct ghost {
    bool collided = false;
    char d = 'N';
    int x = 0;
    int y = 0;
    double cTime = 0;  
};

bool opposite(char c1, char c2) {
    if(c1 == 'E' && c2 == 'W') {
        return true;
    }
    if(c1 == 'W' && c2 == 'E') {
        return true;
    }
    if(c1 == 'N' && c2 == 'S') {
        return true;
    }
    if(c1 == 'S' && c2 == 'N') {
        return true;
    }
    return false;
}

int main()
{
    ifstream fin;
    fin.open("g.in");
    ofstream fout;
    fout.open("g.out");

    int x, y;
    char d;
    int i = 1;
    while(fin >> x >> y >> d) {
        if(x == 0 && y == 0 && d == '0') {
            return 0;
        }
        fout << "Case " << i << ": ";
        i++;
        
        vector<ghost> g;
        
        int j;
        fin >> j;
        for(int k = 0; k < j; k++) {
            int gx;
            int gy;
            char gd;
            fin >> gx >> gy;
            fin >> gd;
            ghost g1;
            g1.d = gd;
            g1.x = gx;
            g1.y = gy;
            g.push_back(g1);
        }
        
        for(int k = 0; k < j; k++) {
            // Going same direction
            if(d == g[k].d) {
                // ignore ghost
            }
            // Going opposite
            else if(opposite(d, g[k].d)) {
                // Going E/W  and lined up
                if((d == 'E' || d == 'W') && y == g[k].y) {
                    // If East and not past each other
                    if(d == 'E' && x < g[k].x) {
                        g[k].collided = true;
                        g[k].cTime = (g[k].x - x) / 2.0;
                    }
                    // West
                    if(d == 'W' && x > g[k].x) {
                        g[k].collided = true;
                        g[k].cTime = (x - g[k].x) / 2.0;
                    }
                }
                // N/S and lined up
                if((d == 'N' || d == 'S') && x == g[k].x) {
                    // If N and not past each other
                    if(d == 'N' && y < g[k].y) {
                        g[k].collided = true;
                        g[k].cTime = (g[k].y - y) / 2.0;
                    }
                    // S
                    if(d == 'S' && y > g[k].y) {
                        g[k].collided = true;
                        g[k].cTime = (y - g[k].y) / 2.0;
                    }
                }
            }
            // going perpindicular
            else {
                int maxx = abs(x) + abs(g[k].x);
                int maxy = abs(y) + abs(g[k].y);
                for(int l = 1; l <= maxx || l <= maxy; l++) {

                    int gx = g[k].x;
                    int gy = g[k].y;
                    int tx = x;
                    int ty = y;
                    if(d == 'N') {
                        ty = y + l;
                    }
                    if(d == 'S') {
                        ty = y - l;
                    }
                    if(d == 'W') {
                        tx = x - l;
                    }
                    if(d == 'E') {
                        tx = x + l;
                    }
                    if(g[k].d == 'N') {
                        gy = g[k].y + l;
                    }
                    if(g[k].d == 'S') {
                        gy = g[k].y - l;
                    }
                    if(g[k].d == 'W') {
                        gx = g[k].x - l;
                    }
                    if(g[k].d == 'E') {
                        gx = g[k].x + l;
                    }
                    
                    if(gx == tx && gy == ty) {
                        g[k].collided = true;
                        g[k].cTime = l;
                    }
                }
            }
        }
        
        bool safe = true;
        double min = 0;    
        for(int k = 0; k < j; k++) {
            if(safe) {
                if(g[k].collided) {
                    safe = false;
                    min = g[k].cTime;
                }
            }
            else {
                if(g[k].collided && g[k].cTime < min) {
                    min = g[k].cTime;
                }
            }
        }
        
        if(safe) {
            fout << "SAFE" << endl;
        }
        else {
	  fout << setprecision(1) << fixed <<  min << endl;
        }
    }

    return 0;
}
