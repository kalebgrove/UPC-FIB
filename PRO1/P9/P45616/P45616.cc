#include <iostream>
#include <vector>

using namespace std;

struct Clock {
        int h;      // hours (0<=h<24)
        int m;      // minutes (0<=m<60)
        int s;      // seconds (0<=s<60)
};

Clock midnight(){
    Clock mid;
    mid.h = 0;
    mid.m = 0;
    mid.s = 0;
    return mid;
}
void increase(Clock& r){
    ++r.s;
    if(r.s == 60) {
        r.s = 0;
        ++r.m;
    }
    if(r.m == 60) {
        r.m = 0;
        ++r.h;
    }
    if(r.h == 24) {
        r.h = 0;
    }
}

void print(const Clock& r){
    if(r.h < 10) cout << 0 << r.h;
    else cout << r.h;
    cout << ':';
    if(r.m < 10) cout << 0 << r.m;
    else cout << r.m;
    cout << ':';
    if(r.s < 10) cout << 0 << r.s;
    else cout << r.s;
    cout << endl;
}