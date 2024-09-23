#include <iostream>

using namespace std;

int main() {
    int n;
    int count = 0;
    int triplet_cnt = 0, triplet = 0;

    while(cin >> n) {
        int pos = 1;
        int x = n;
        bool fantastic = true;
        
        if(x == 0 and pos%2 == 1) {
                fantastic = false;
                triplet = 0;
                ++pos;
            }

        while(x > 0 and fantastic) {
            if((x%10)%2 != pos%2){
                fantastic = false;
                triplet = 0;
            }
            x /= 10;
            ++pos;
        }
        ++count;
        if(fantastic) ++triplet;

        if(triplet == 3) {
            ++triplet_cnt;
            triplet = 2;
        }
    }
    cout << "fantastic numbers: " << count << endl;
    cout << "fantastic triplets: " << triplet_cnt << endl;
}