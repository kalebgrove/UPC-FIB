#include <iostream>
#include <vector>

using namespace std;

bool prime(int n) {
    for(int i = 2; i*i <= n; ++i) {
        if(n%i == 0) return false;
    }
    return true;
}

int main() {
    int n;
    while(cin >> n) {
        vector<int> v(n);
        for(int i = 0; i < n; ++i) cin >> v[i];

        int ctr = 0;
        bool found = false;
        
        while(not found and ctr < n) {
            for(int i = ctr+1; i < n; ++i) {
                if(prime(v[ctr] + v[i])) found = true;
            }
            ++ctr;
        }

        if(found) cout << "yes\n";
        else cout << "no\n";
    }
}