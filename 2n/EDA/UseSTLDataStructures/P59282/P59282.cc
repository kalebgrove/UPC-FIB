#include <iostream>
#include <map>

using namespace std;

int main()
{
    cout.setf(ios::fixed);
    cout.precision(4);

    map<int, int> numbers;

    int size = 0;
    double avg = 0;

    string s;

    while (cin >> s)
    {
        if (s == "number")
        {
            int num;
            cin >> num;

            ++size;

            avg = double((size - 1)) / size * avg + double(num) / size;

            numbers[num]++;
        }
        else if (s == "delete")
        {
            if (!numbers.empty())
            {
                auto it = numbers.begin();
                int val = it->first;
                numbers[val]--;

                if (numbers[val] <= 0)
                    numbers.erase(it);

                --size;

                if (size != 0)
                    avg = double(size + 1) / size * avg - double(val) / size;
            }
        }

        if (!numbers.empty())
        {
            map<int, int>::iterator it = numbers.begin();
            map<int, int>::iterator it2 = numbers.end();
            --it2;

            cout << "minimum: " << it->first << ", maximum: " << it2->first << ", average: " << avg << endl;
        }
        else
        {
            cout << "no elements" << endl;
        }
    }
}