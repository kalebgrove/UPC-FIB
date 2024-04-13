#include <iostream>
#include <math.h>

using namespace std;

double travelled(double x, double y, double x1, double y1) {
    double distance = sqrt((x1-x)*(x1-x)+(y1-y)*(y1-y));
    return distance;
}

int main() {
    cout.setf(ios::fixed);
    cout.precision(4);

    string route;
    double x1, y1, xpos, ypos;
    
    while(cin >> route) {
        double distance = 0;

        cin >> xpos >> ypos;
        double x = xpos;
        double y = ypos;

        bool finished = false;

        while(not finished and cin >> x1 >> y1){
            distance += travelled(x, y, x1, y1);
            if(x1 == xpos and y1 == ypos) finished = true;
            x = x1;
            y = y1;
        }

        cout << "Route " << route << ": " << distance << endl;
    }
}