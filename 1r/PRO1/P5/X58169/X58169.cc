#include <iostream>
using namespace std;

//Pre: evaluates two sequences of non negative integers, ending in 0.
//Post: calculates the maximum natural number of the first sequence, stores its value and its position and finds the position of this same number in the next sequence.
void infoSequence(int& max, int& lpos) {
    int temp_pos = 1;
    bool found = false;
    int n;
    if(max == -1) {
        while(cin >> n and n != 0) {
            if(n >= max) {
                max = n;
                lpos = temp_pos;
            }
            ++temp_pos;
        }
    } else {
        while(cin >> n and not found and n != 0) {
            if(n == max) {
                max = n;
                found = true;
                lpos = temp_pos;
            }
            ++temp_pos;
        }
    }
    
}

int main() {
    int max = -1, lpos = 0;
    infoSequence(max, lpos);
    
    const int fstmax = max, fstlpos = lpos;
    
    max = fstmax, lpos = 0;
    infoSequence(max, lpos);

    if(lpos != 0) cout << fstmax << ' ' << fstlpos << ' ' << lpos << endl;
    else cout << fstmax << ' ' << fstlpos << " -\n";
}