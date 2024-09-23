#include <iostream>
#include <vector>

using namespace std;

vector<char> base(int x, int n) {
    string s = "";
    if(n < 11) {
        while(x > 0) {
            s += '0' + x%n;
            x /= n;
        }
    } else {
        while(x > 0) {
            if(x%n > 9) s += 'A' + x%n - 10;
            else s += '0' + x%n;
            x /= n;
        }
    }
    vector<char> w(s.size());
    int j = 0;
    for(int k = s.size() - 1; k >= 0; --k) {
        w[k] = s[j];
        ++j;
    }
    return w;
}

int main() {
    int x, y;
    cin >> x >> y;

    int product = x*y;
    int n = 2;
    while(n < 17) {
        vector<char> num1 = base(x, n);
        vector<char> num2 = base(y, n);
        vector<char> prdct = base(product, n);

        for(int i = 0; i < prdct.size(); ++i) cout << prdct[i];
        cout << endl;
        //for(int i = 0; i < num1.size(); ++i) cout << num1[i];
        //cout << endl;
        //for(int i = 0; i < num2.size(); ++i) cout << num2[i];
        //cout << endl;
        ++n;
    }
}