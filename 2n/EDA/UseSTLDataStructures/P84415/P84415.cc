#include <iostream>
#include <map>

using namespace std;

int main()
{
    string s;
    map<string, int> words;

    while (cin >> s)
    {
        if (s == "minimum?")
        {
            if (not words.empty())
            {
                auto it = words.begin();

                cout << "minimum: " << it->first << ", " << it->second << " time(s)" << endl;
            }
            else
            {
                cout << "indefinite minimum" << endl;
            }
        }
        else if (s == "maximum?")
        {
            if (not words.empty())
            {
                auto it = words.end();
                --it;

                cout << "maximum: " << it->first << ", " << it->second << " time(s)" << endl;
            }
            else
            {
                cout << "indefinite maximum" << endl;
            }
        }
        else if (s == "store")
        {
            string word;
            cin >> word;

            words[word]++;
        }
        else if (s == "delete")
        {
            string word;
            cin >> word;

            words[word]--;

            if (words[word] <= 0)
                words.erase(word);
        }
    }
}