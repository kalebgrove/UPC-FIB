#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> v(n);
    for(int i = 0; i < n; ++i) cin >> v[i];

    vector<int> freq(1001, 0);
    
    for(int i = 0; i < n; ++i) {
            ++freq[v[i] - 1000000000];
    }

    for(int i = 0; i < 1001; ++i) {
        int sum = 1000000000+i;
        if(freq[i] != 0) cout << sum << " : " << freq[i] << endl;
    }
}