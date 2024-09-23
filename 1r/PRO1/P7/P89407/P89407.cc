#include <iostream>
#include <vector>

using namespace std;
typedef vector<char> VC;
typedef vector<int> VI;

VI frequencies(VC num) {
    VI freq(16, 0);
    for(int i = 0; i < num.size(); ++i) {
        if(num[i] <= '9' and num[i] >= '0') ++freq[int(num[i]) - int('0')];
        else ++freq[int(num[i]) - int('A') + 10];
    }
    return freq;
}

VC base(int x, int n) {
    string s = "";
    while(x > 0) {
        if(x%n > 9) s += 'A' + x%n - 10;
        else s += '0' + x%n;
        x /= n;
    }

    VC w(s.size());
    
    int j = 0;
    for(int k = s.size() - 1; k >= 0; --k) {
        w[k] = s[j];
        ++j;
    }
    return w;
}

bool same(VC num1, VC num2, VC product) {
    
    for(int i = 0; i < num2.size(); ++i) num1.push_back(num2[i]);
    VI freqx_y = frequencies(num1);
    VI freq_prdct = frequencies(product);

    if(freqx_y != freq_prdct) return false;
    return true;
}

int main() {
    int x, y;

    while(cin >> x >> y) {
        cout << "solutions for " << x << " and " << y << endl;

        int n = 2, ctr = 0;
        while(n < 17 and (x != 0 or y != 0)) {
            VC num1 = base(x, n);
            VC num2 = base(y, n);
            VC prdct = base(x*y, n);
                
            if(same(num1, num2, prdct)) {
                for(int i = 0; i < num1.size(); ++i) cout << num1[i];
                cout << " * ";
                for(int i = 0; i < num2.size(); ++i) cout << num2[i];
                cout << " = ";
                for(int i = 0; i < prdct.size(); ++i) cout << prdct[i];
                cout << " (base " << n << ")\n";
                ++ctr;
            }
            ++n;
        }
        if(ctr == 0) cout << "none of them\n";
        cout << endl;
    }
}