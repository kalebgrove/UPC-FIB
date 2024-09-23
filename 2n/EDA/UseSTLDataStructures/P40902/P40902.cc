#include <iostream>
#include <set>
#include <map>

using namespace std;

int main()
{
    map<string, int> inside_casino;

    string s;

    while (cin >> s)
    {

        string op;
        cin >> op;

        if (op == "enters")
        {

            if (inside_casino.count(s) > 0)
            {
                cout << s << " is already in the casino" << endl;
            }
            else
            {

                inside_casino[s] = 0;
            }
        }
        else if (op == "leaves")
        {

            if (inside_casino.count(s) == 0)
            {
                cout << s << " is not in the casino" << endl;
            }
            else
            {
                cout << s << " has won " << inside_casino[s] << endl;

                inside_casino.erase(s);
            }
        }
        else if (op == "wins")
        {
            int amount;
            cin >> amount;

            if (inside_casino.count(s) == 0)
            {
                cout << s << " is not in the casino" << endl;
            }
            else
            {
                inside_casino[s] += amount;
            }
        }
    }
    cout << "----------" << endl;

    for (map<string, int>::iterator it = inside_casino.begin(); it != inside_casino.end(); ++it)
    {
        cout << (it->first) << " is winning " << (it->second) << endl;
    }
}