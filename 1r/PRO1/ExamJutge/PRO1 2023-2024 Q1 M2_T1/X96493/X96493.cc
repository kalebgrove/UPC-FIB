#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


// Pre: Let n be v.size(). Then, for each i in {0..n-2}, |v[i]-v[i+1]|<=2 holds.
//      In addition, there is exactly one i in {0..n-2} satisfying |v[i]-v[i+1]|=1.
// Post: The function returns this particular i in {0..n-2} satisfying |v[i]-v[i+1]|=1.
int positionDistance1(const vector<int> &v) {
    int n = v.size();
    int left = 0;
    int right = n-1;

    while(left+1 < right) {
        int middle = (left + right)/2;
        if(v[middle]%2 == v[0]%2) left = middle;
        else right = middle;
    }
    return left;
}