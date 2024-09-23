#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

struct Slot {
    vector<string> listsubjects;
    vector<string> listteachers;
};

typedef vector<vector<Slot>> TableSlots;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);    
    cout.setf(ios::fixed);
    cout.precision(5);

    map<string, int> days = {{"monday", 0}, {"tuesday", 1}, {"wednesday", 2}, {"thursday", 3}, {"friday", 4}};
    TableSlots table(24, vector<Slot>(5));

    string subject, teacher, day;
    int start, end;
    while (cin >> subject >> teacher >> day >> start >> end) {
        for (int i = start; i < end; ++i) {
            table[i][days[day]].listsubjects.push_back(subject);
            table[i][days[day]].listteachers.push_back(teacher);
        }
    }

    cout << "number of subjects per slot:\n";
    cout << " h    monday   tuesday wednesday  thursday    friday\n";
    for (int i = 0; i < 24; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (!table[i][j].listsubjects.empty()) {
                cout << i << ' ';
                for (int k = 0; k < 5; ++k) {
                    cout << table[i][k].listsubjects.size() << ' ';
                }
                cout << '\n';
                break;
            }
        }
    }

    cout << "number of teachers per slot:\n";
    cout << " h    monday   tuesday wednesday  thursday    friday\n";
    for (int i = 0; i < 24; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (!table[i][j].listteachers.empty()) {
                cout << i << ' ';
                for (int k = 0; k < 5; ++k) {
                    set<string> unique_teachers(table[i][k].listteachers.begin(), table[i][k].listteachers.end());
                    cout << unique_teachers.size() << ' ';
                }
                cout << '\n';
                break;
            }
        }
    }

    int replacements = 0;
    for (int i = 0; i < 24; ++i) {
        for (int j = 0; j < 5; ++j) {
            map<string, int> teacher_count;
            for (const string& teacher : table[i][j].listteachers) {
                teacher_count[teacher]++;
                if (teacher_count[teacher] > 1) {
                    replacements++;
                }
            }
        }
    }

    cout << "number of replacements needed to avoid conflicts:\n";
    cout << replacements << '\n';

    return 0;
}
