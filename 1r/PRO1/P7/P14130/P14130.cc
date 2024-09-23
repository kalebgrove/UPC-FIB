#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> v(n);

    for(int i = 0; i < n; ++i) cin >> v[i];

    int ctr = 0;
    int element = v[n-1];

    for(int i = 0; i < n-1; ++i) {
        ctr += (v[i] == element);
    }
    cout << ctr << endl;
}