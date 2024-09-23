#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;

    while(cin >> n){

        vector<int> x(n);
        
        int sum = 0;
        bool found = false;

        for(int i = 0; i < n; ++i) {
            cin >> x[i];
            sum += x[i];
        }

        int ctr = 0;

        while(not found and ctr < n) {
            if(sum - x[ctr] == x[ctr]) found = true;
            ++ctr;
        }       
        
        if(found) cout << "YES\n";
        else cout << "NO\n";
    }
}