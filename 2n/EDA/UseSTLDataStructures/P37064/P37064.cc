#include <iostream>
#include <set>

using namespace std;

int main()
{
    string s;

    set<string> words;

    int size = 1;

    cin >> s;

    words.insert(s);

    auto it = words.begin();

    if (s != "END")
    {
        cout << s << endl;
        cin >> s;
    }

    while (s != "END")
    {
        words.insert(s);
        ++size;

        if (s < *it)
        {
            --it;
        }

        if (size % 2 != 0 and size > 1)
        {
            ++it;
        }

        cout << *it << endl;

        cin >> s;
    }
}