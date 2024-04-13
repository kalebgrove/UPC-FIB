#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> VI;

void max(int m, const VI& v, int& maximum) {
    for(int i = 0; i < m; ++i) {
        maximum = max(maximum, v[i]);
    }
}

int main() {
    int n;

    while(cin >> n){
        VI v(0);
        while(n != -1) {
            v.push_back(n);
            cin >> n;
        }

        int temp_ctr = 0;
        int ctr = 0;
        int maximum = -1;

        for(int i = 1; i < v.size(); ++i) {
            max(i, v, maximum);
            if(v[i] <= 1+maximum) ++temp_ctr;
            else temp_ctr = 0;

            ctr = max(ctr, temp_ctr);
        }
        if(maximum != -1 or v.size() == 1) ++ctr;
        cout << ctr << endl;
    }
}