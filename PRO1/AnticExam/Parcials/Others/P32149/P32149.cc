#include <iostream>

using namespace std;

int main() {
    int n;
    int upward = 0;
    bool finish = false;

    while(cin >> n and not finish) {
        bool larger = true;

        while(n > 9 and larger){
            if(((n/10)%10 == 9 and n%10 == 0) or (n%10 - (n/10)%10) == 1) larger = true;
            else larger = false;
            n /= 10;
        }
        if(larger) upward += 1;
        else upward = 0;

        if(upward == 2) finish = true;
    }
    if(finish) cout << "YES" << endl;
    else cout << "NO" << endl;
}