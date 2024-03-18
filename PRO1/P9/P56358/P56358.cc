#include <iostream>
#include <vector>

using namespace std;

struct Time {
    int hour, minute, second;
};

void one_second(const Time& t, Time& t1, Time& t2) {
    t1.second = t.second + 1;
    t1.minute = t.minute;
    t1.hour = t.hour;
    if(t1.second == 60) {
        ++t1.minute;
        t1.second = 0;
    }
    if(t1.minute == 60) {
        ++t1.hour;
        t1.minute = 0;
    }
    if(t1.hour == 24) t1.hour = 0;

    t2.second = t.second - 1;
    t2.minute = t.minute;
    t2.hour = t.hour;
    if(t2.second < 0) {
        --t2.minute;
        t2.second = 59;
    }
    if(t2.minute < 0) {
        --t2.hour;
        t2.minute = 59;
    }
    if(t2.hour < 0) t2.hour = 23;
}

int main() {
    Time t;
    Time t1;
    Time t2;
    while(cin >> t.hour >> t.minute >> t.second) {
        one_second(t, t1, t2);
        cout << t1.hour << ' ' << t1.minute << ' ' << t1.second << endl;
        cout << t2.hour << ' ' << t2.minute << ' ' << t2.second << endl;
    }
}