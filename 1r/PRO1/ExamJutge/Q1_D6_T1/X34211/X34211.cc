#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> numbers(n);

    for(int i = 0; i < n; ++i) cin >> numbers[i];

    string operands;
    vector<char> op(n);
    while(cin >> operands) {
        for(int i = 0; i < operands.size(); ++i) op[i] = operands[i];

        int sum = 0;
        for(int i = 0; i < n; ++i) {
            if(op[i] == '-') sum += -numbers[i];
            else sum += numbers[i];
        }
        cout << sum << endl;
    }
}