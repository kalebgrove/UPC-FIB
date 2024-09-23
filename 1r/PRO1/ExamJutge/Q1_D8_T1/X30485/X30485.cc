#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Point {
 double x, y, z;
};

struct Particle {
 Point p,v;             //P is position(3 coordinates) and v is velocity(3 coordinates);
 double m;
};

// Pre:
// Post: returns the sum of p1 and p2.
Point sum(Point p1, Point p2)   //This function calculates the sum of two coordinates(supposedly the same) and returns its value. We use this function for the first two lines. It is a function inside the data structure.
{
    Point result;
    result.x = p1.x + p2.x;
    result.y = p1.y + p2.y;
    result.z = p1.z + p2.z;
    return result;
}

// Pre:
// Post: returns a times p.
Point mul(double a, Point p)    //This function we will use to calculate the total sum of points that is found in the denominator of the function that calculates the center of mass. It is important to use curly brackets.
{                               //The variable double a will represent the multiplication of time and velocity for each of its components.
    Point result;
    result.x = a*p.x;
    result.y = a*p.y;
    result.z = a*p.z;
    return result;
}

Particle centerofmass(vector<Particle>& part, int n) {
    Point pos;
    pos.x = 0.0, pos.y = 0.0, pos.z = 0.0;

    Point vel;
    vel.x = 0.0, vel.y = 0.0, vel.z = 0.0;
    
    double t_mass = 0;
    for(int i = 0; i < n; ++i) {
        t_mass += part[i].m;
        pos = sum(pos, mul(part[i].m, part[i].p));
        vel = sum(vel, mul(part[i].m, part[i].v));
    }

    pos = mul(1/t_mass, pos);
    vel = mul(1/t_mass, vel);

    Particle mass_center;
    mass_center.p = pos;
    mass_center.v = vel;

    return mass_center;
}

void printDouble(double d)
{
 if (abs(d) < 1e-7)
  cout << 0.0;
 else
  cout << d;
}

void moveprint(vector<Particle>& part, int n, double t_time) {
    for(int i = 0; i < n; ++i) {
        part[i].p = sum(part[i].p, mul(t_time, part[i].v));

        printDouble(part[i].p.x);
        cout << ' ';
        printDouble(part[i].p.y);
        cout << ' ';
        printDouble(part[i].p.z);
        cout << '\n';
    }
}

void read(vector<Particle>& part, int i) {
    cin >> part[i].p.x >> part[i].p.y >> part[i].p.z;
    cin >> part[i].v.x >> part[i].v.y >> part[i].v.z;
    cin >> part[i].m;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);    
    cout.setf(ios::fixed);
    cout.precision(5);

    int n, k;
    while(cin >> n >> k){
        vector<Particle> part(n);

        for(int i = 0; i < n; ++i) read(part, i);

        Particle mass_center = centerofmass(part, n); //Now we will calculate the mass center and update it while an input time is being read.

        int time;
        double t_time = 0.0;

        for(int i  = 0; i < k; ++i) {
            cin >> time;
            t_time += time;
            mass_center.p = sum(mass_center.p, mul(time, mass_center.v));
            printDouble(mass_center.p.x);
            cout << ' ';
            printDouble(mass_center.p.y);
            cout << ' ';
            printDouble(mass_center.p.z);
            cout << '\n';
        }

        moveprint(part, n, t_time);

        cout << '\n';
    }
}