#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;

    while(cin >> n) {

    vector<int> v(n);

    for(int i = 0; i < n; ++i) cin >> v[i];

    if(n != 0) cout << v[n-1];
    for(int i = n-2; i >= 0; --i) cout<< ' ' << v[i];
    cout << endl;
    }
}