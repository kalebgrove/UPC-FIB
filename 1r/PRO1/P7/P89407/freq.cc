#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef vector<char> VC;
typedef vector<int> VI;

VI frequencies(VC num) {
    VI freq(16, 0);
    for(int i = 0; i < num.size(); ++i) {
        if(num[i] <= '9' and num[i] >= '0') ++freq[num[i] - '0'];
        else ++freq[num[i] - 'A' + 10];
    }
    return freq;
}

VC sum(VC x, VC y) {
    for(int i = 0; i < y.size(); ++i) x.push_back(y[i]);
    return x;
}

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

    while(cin >> x >> y) {
        cout << "solutions for " << x << " and " << y << endl;

        int length_x = trunc(log10(x)) + 1;
        int length_y = trunc(log10(y)) + 1;
        int product = x*y;
        int length_product = trunc(log10(product)) + 1;

        if(length_product == length_x + length_y) {
            int n = 2;
            while(n < 17) {
                VC num1 = base(x, n);
                VC num2 = base(y, n);
                VC prdct = base(product, n);
                
                VC w = sum(num1, num2);
                VI freq = frequencies(w);

                for(int i = 0; i < w.size(); ++i) cout << w[i];
                cout << endl;

                for(int i = 0; i < freq.size(); ++i) cout << freq[i];
                cout << endl;
                
                ++n;
            }
        }
    }
}