/* Estadístiques d'una seqüència d'enters amb esborrat

Kaleb Grove - https://github.com/kalebgrove/UPC-FIB
*/
#include <iostream>
#include <list>

using namespace std;

void min(list<int>& l, int& minimum) {
    list<int>::iterator it = l.begin();

    minimum = *it;

    while(it != l.end()) {
        if(*it < minimum) minimum = *it;
        ++it;
    }
}

void max(list<int>& l, int& maximum) {
    list<int>::iterator it = l.begin();

    maximum = *it;

    while(it != l.end()) {
        if(*it > maximum) maximum = *it;
        ++it;
    }
}

void remove(list<int>& l, int n, bool& found) {
    list<int>::iterator it = l.begin();

    found = false;
    while(it != l.end() and not found) {
        if(*it == n) {
            found = true;
            it = l.erase(it);
        }
        else ++it;
    }
}

int main() {
    int x, y;
    
    list<int> l;

    int minimum, maximum;
    int num = 0;
    double sum = 0;

    while(cin >> x >> y) {

        if(x == -1) {
            sum += y;
            ++num;
            l.push_back(y);

            if(num == 1) {
                maximum = y;
                minimum = y;
            } else {
                if(y > maximum) maximum = y;
                if(y < minimum) minimum = y;
            }

        } else if(x == -2) {
            bool found = false;
            if(not l.empty()) remove(l, y, found);

            if(not l.empty() and found) {
                sum -= y;
                --num;

                if(y == minimum) min(l, minimum);
                if(y == maximum) max(l, maximum);
            }
            
        } else if(x == 0) {
            return 0;
        }

        if(not l.empty()) cout << minimum << ' ' << maximum << ' ' << sum/num << endl;
        else {
            sum = 0;
            num = 0;
            cout << 0 << endl;
        }
    }
}