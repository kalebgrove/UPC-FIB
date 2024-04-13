#include <iostream>

using namespace std;

int main() {
    char c;

    while(cin >> c) {
        int ctr = 0, a_ctr = 0;
        bool string = false;

        while(c != '$') {

            if(c <= 'z' and c >= 'a') {
                string = true;
                if(c == 'a') ++a_ctr;
            }

            if(c == '#') {
                if(a_ctr == 0 and string) {
                    ++ctr;
                    //cout << i << endl;
                }
                a_ctr = 0;
                string = false;
            }

            cin >> c;

        }
        if(a_ctr == 0 and string) ++ctr;
        cout << ctr << endl;
    }
}