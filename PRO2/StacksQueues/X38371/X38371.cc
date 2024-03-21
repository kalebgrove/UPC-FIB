/* Estadístiques d'una seqüència d'enters amb esborrat del més antic

Kaleb Grove - https://github.com/kalebgrove/UPC-FIB
*/
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

void maxi(int& maximum, queue<int> q) {
    maximum = -1001;
    while(not q.empty()) {
        maximum = max(maximum, q.front());
        q.pop();
    }
}

void mini(int& minimum, queue<int> q) {
    minimum = 1001;
    while(not q.empty()) {
        minimum = min(minimum, q.front());
        q.pop();
    }
}

int main() {
    int n;
    int sum = 0;
    int num = 0;
    int minimum = 1001;
    int maximum = -1001;

    queue<int> list;

    bool end = false;

    while(not end and cin >> n and n != 1001) {
        if(n >= -1000 and n <= 1000) {
            sum += n;
            ++num;
            list.push(n);
            minimum = min(minimum, n);
            maximum = max(maximum, n);
            cout << "min " << minimum << "; max " << maximum << "; media " << (double(sum)/num) << endl; 
        } else {
            if(not list.empty()) {
                sum -= list.front();
                --num;
                int x = list.front();
                list.pop();
                if(x == maximum) maxi(maximum, list);
                if(x == minimum) mini(minimum, list);
                if(list.empty()) {
                    cout << 0 << endl;
                    minimum = 1001;
                    maximum = -1001;
                }
                else {
                    cout << "min " << minimum << "; max " << maximum << "; media " << (double(sum)/num) << endl;
                }
            } else {
                cout << 0 << endl;
                minimum = 1001;
                maximum = -1001;
            }
        }
    }
}