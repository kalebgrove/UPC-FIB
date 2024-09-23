#include <iostream>

using namespace std;

int main() {
    char c;
    int sign = 1;
    int sum = 0, temp_sum = 0;
    bool is_num = true, point = false;

    while(cin >> c and not point){
        
        is_num = true;

        if(point) {
            cout << sum << endl;
        } else if(c == '-'){
            sign *= -1;
        } else if(c <= '9' and c >= '0') {
            temp_sum = (int(c) - int('0'))*sign;

            while(is_num and cin >> c) {
                if(c <= '9' and c >= '0') temp_sum = temp_sum*10 + (int(c) - int('0'))*sign;
                else is_num = false;
            }
            sum = sum + temp_sum;
            temp_sum = 0;
            if(c == '-') sign = -1;
            else if(c == '.') point = true;
            else sign = 1;
        }
    }
}