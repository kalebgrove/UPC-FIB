/* Estudiants que s'inscriuen en assignatures

Kaleb Grove - https://github.com/kalebgrove/UPC-FIB
*/
#include <iostream>
#include <map>
#include <set>

using namespace std;

int main() {
    string s;

    map<string, set<string>> students;
    map<string, set<string>> classes;

    while(cin >> s) {
        if(s == "ENROLL") {
            string student;
            string subject;
            cin >> student >> subject;

            students[student].insert(subject);

            classes[subject].insert(student);
        }
        else if(s == "QUIT") {
            string student;
            string subject;
            cin >> student >> subject;

            students[student].erase(subject);

            classes[subject].erase(student);
        }
        else if(s == "SUBJECTSOFSTUDENT") {
            string student;
            cin >> student;

            set<string> subj = students[student];

            bool space = false;

            for(set<string>::iterator it = subj.begin(); it != subj.end(); ++it) {
                if(it != subj.begin()) space = true;
                if(space) cout << ' ';
                cout << *it;
            }

            cout << endl;
        }
        else if(s == "STUDENTSOFSUBJECT") {
            string subject;
            cin >> subject;

            set<string> stu = classes[subject];

            bool space = false;

            for(set<string>::iterator it = stu.begin(); it != stu.end(); ++it) {
                if(it != stu.begin()) space = true;
                if(space) cout << ' ';
                cout << *it;
            }

            cout << endl;
        }
    }
}