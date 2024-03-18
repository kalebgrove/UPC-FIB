#include <iostream>

using namespace std;

int main() {
    cout.setf(ios::fixed);
    cout.precision(4);

    int n;
    cin >> n;
    
    for(int i = 0; i < n; ++i) {

        int m;
        cin >> m;
        double number;

        cin >> number;
            
        double max = number;
        double min = number;
        double sum = number;

        int count = 1;

        for(int j = 0; j < m-1; ++j) {
            cin >> number;

            if(number > max) max = number;
            else if(number < min) min = number;
            sum += number;
            ++count;
        }
        cout << min << ' ' << max << ' ' << double(sum/count) << endl;
    }

}