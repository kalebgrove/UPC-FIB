#include <iostream>

using namespace std;

int main() {
    string name;
    
    while(cin >> name){
        int n = 0;
        int sum = 0;

        cout << name << endl;
        cout << "+---------+" << endl;

        while(n != int(-1) and cin >> n){
            sum += n;
        }
        ++sum;
        int ten = 1000000;
        char c = 'G';
        
        while(sum > 0) {
            int letter = sum/ten;

            if(letter != 0) {
                cout << '|';

                for(int i = 0; i < letter; ++i) {
                    cout << c;
                }
                for(int i = 0; i < 9 - letter; ++i) {
                    cout << ' ';
                }
                cout << '|' << endl;
            }
            sum -= letter*ten;
            ten /= 10;
            --c;
        }
        cout << "+---------+" << endl;
        cout << endl;
    }
}