#include <iostream>

using namespace std;

int main() {
    int n;
    
    bool larger = false, end = false;
    int count = 0;

    while(not end and cin >> n) {
        string s;
        cin >> s;

        larger = true;

        string prev_s = s;
        int i = 0;
        while(i < n-1) {
            cin >> s;

            if(prev_s > s) {
                larger = false;
            }
            prev_s = s;
            ++i;
        }
        ++count;

        if(larger) {
            cout << "The first line in increasing order is " << count << ".\n";
            end = true;
        }
    }
    if(not larger) cout << "There is no line in increasing order.\n";
}