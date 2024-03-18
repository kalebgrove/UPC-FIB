#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int position(double x, const vector<double>& v, int left, int right) {
    while(left <= right) {
        int middle = (left+right)/2;

        if(v[middle] < x) left = middle + 1;
        else if(v[middle] > x) right = middle - 1;
        else return middle;
    }
    return -1;
}

int main() {
    vector<double> v(5);

    for(int i = 0; i < 5; ++i) cin >> v[i];

    sort(v.begin(), v.end());

    cout << position(3, v, 0, 4) << endl;
}