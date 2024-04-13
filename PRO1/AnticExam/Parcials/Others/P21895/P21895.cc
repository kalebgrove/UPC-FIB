#include <iostream>

using namespace std;

int main() {
    int n;
    int count = 0;

    while(cin >> n) {
        bool strobo = true;
        int aux = n;
        int reversed = 0;

        while(aux > 0 and strobo) {
            
            if(aux%10 == 2 or aux%10 == 3 or aux%10 == 4 or aux%10 == 5 or aux%10 == 7) strobo = false;
            else {
                if(aux%10 == 6) {
                    reversed = 9 + reversed*10;
                } else if(aux%10 == 9) {
                    reversed = reversed*10 + 6;
                } else {
                    reversed = reversed*10 + aux%10;
                }
            }
            aux /= 10;
        }

        if(reversed == n) {
            cout << n << " is strobogrammatic" << endl;
            if(reversed%2 == 1) ++count;
        }
        else cout << n << " is not strobogrammatic" << endl;
    }
    cout << endl;
    cout << "odd strobogrammatic: " << count << endl;
}