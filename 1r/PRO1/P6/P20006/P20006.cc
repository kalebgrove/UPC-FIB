#include <iostream>

using namespace std;

int calc(char c, int sum, int temps, int n1, int n2, int ctr) {
    if(cin >> c) {
        if(c <= '9' and c >= '0') {
            n1 = int(c) - int('0');
            sum = n1;
            if(ctr == 0) calc(c, sum, temps, n1, n1, ++ctr);
            else calc(c, sum, temps, n1, n2, ++ctr);
        } else {
            if(ctr == 1) {
                if(c == '+') sum += n2;
                else if(c == '-') sum -= n2;
                else if(c == '*') sum *= n2;
            } else if(ctr == 2) {
                if(c == '+') temps = n1 + n2;
                else if(c == '-') temps = n2 - n1;
                else if(c == '*') temps = n2*n1;
            } else if(ctr == 0) {
                if(c == '+') sum += temps;
                else if(c == '-') sum = temps - sum;
                else if(c == '*') sum = temps * sum;
            }
            calc(c, sum, temps, 0, 0, 0);
        } 
    }
    return sum;    
}

void calc2(char c, int sum = 0, int temps = 0, int n1 = 0, int n2 = 0, int ctr = 0) {
    if(cin >> c) {
        return calc2(c);
        if(c <= '9' and '0' <= c) {
            n1 = int(c) - int('0');
            sum = n1;
            n2 = n1;
            ++ctr;
        } else {

        }
    }
    cout << sum << endl;
}

int main() {
    cout << calc('0', 0, 0, 0, 0, 0) << endl;
}