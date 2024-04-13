#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Slot {
 vector<string> listsubjects;
 vector<string> listteachers;
};

typedef vector<vector<Slot> > TableSlots;

int num_digits(int n) {
    int ctr = 1;
    while(n > 9) {
        n /= 10;
        ++ctr;
    }
    return 10-ctr;
}

void print_subjects(TableSlots& table, int start, int end) {
    cout << "number of subjects per slot:\n" << " h    monday   tuesday wednesday  thursday    friday\n";

    for(int i = start; i < end; ++i) {
        if(i < 10) cout << ' ';
        cout << i;
        for(int j = 0; j < 5; ++j) {
            int num_dig = num_digits(table[i][j].listsubjects.size());
            for(int k = 0; k < num_dig; ++k) cout << ' ';
            cout << table[i][j].listsubjects.size();
        }
        cout << endl;
    }
}

void print_teachers(vector<vector<int> >& teacher_count, int start, int end) {
    cout << "number of teachers per slot:\n" << " h    monday   tuesday wednesday  thursday    friday\n";

    for(int i = start; i < end; ++i) {
        if(i < 10) cout << ' ';
        cout << i;
        for(int j = 0; j < 5; ++j) {
            int num_dig = num_digits(teacher_count[i][j]);
            for(int k = 0; k < num_dig; ++k) cout << ' ';
            cout << teacher_count[i][j];
        }
        cout << endl;
    }
}

int main() {
    TableSlots table(25, vector<Slot>(5));
    vector<vector<int> > teacher_count(25, vector<int>(5));
    
    string sub, teach, day;
    int start, end;
    int min = 25, max = 0;
    int day_Index;

    while(cin >> sub >> teach >> day >> start >> end) {
        for(int i = start; i < end; ++i) {
            if(day == "monday") day_Index = 0;
            else if(day == "tuesday") day_Index = 1;
            else if(day == "wednesday") day_Index = 2;
            else if(day == "thursday") day_Index = 3;
            else day_Index = 4;

            table[i][day_Index].listsubjects.push_back(sub);
            table[i][day_Index].listteachers.push_back(teach);
            ++teacher_count[i][day_Index];
        }
        if(start < min) min = start;
        if(end > max) max = end;
    }

    print_subjects(table, min, max);

    for(int i = 0; i < 25; ++i) {
        for(int j = 0; j < 5; ++j) {
            sort(table[i][j].listteachers.begin(), table[i][j].listteachers.end());
        }
    }

    int replacements = 0;
    for(int i = 0; i < 25; ++i) {
        for(int j = 0; j < 5; ++j) {
            int k = 0;
            while(k < table[i][j].listsubjects.size() and k+1 < table[i][j].listsubjects.size()) {
                if(table[i][j].listteachers[k] == table[i][j].listteachers[k+1]) {
                    ++replacements;
                    --teacher_count[i][j];
                }
                ++k;
            }
        }
    }
    print_teachers(teacher_count, min, max);
    cout << "number of replacements needed to avoid conflicts:\n" << replacements << endl;
}