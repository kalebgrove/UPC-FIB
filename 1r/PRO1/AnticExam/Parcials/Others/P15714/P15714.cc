#include <iostream>

using namespace std;

int main() {
    char c;
    bool letter = true;
    int count = 0;
    int smol = 0, med = 0, large = 0;

    while(cin >> c and c != '.'){

        if(c <= 'z' and c >= 'a') {
            ++count;
            while(letter) {
                cin >> c;
                if(c <= 'z' and c >= 'a') ++count;
                else letter = false;
            }
            if(count < 5) ++smol;
            else if(count >= 5 and count <= 9) ++med;
            else ++large;
        }

        letter = true;
        count = 0;

    }
    cout << smol << ',' << med << ',' << large << endl;
}