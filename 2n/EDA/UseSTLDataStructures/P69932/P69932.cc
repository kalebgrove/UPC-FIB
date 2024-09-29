#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

void mystoi(string &s, vector<int> &numbers)
{

    stringstream ss(s);
    string temp;

    while (ss >> temp) // extract numbers separated by spaces
    {
        numbers.push_back(stoi(temp)); // convert string to integer and add to vector
    }

    return;
}

int main()
{
    string s;

    while (getline(cin, s))
    {
        vector<int> numbers;

        mystoi(s, numbers);

        sort(numbers.begin(), numbers.end());

        int max = 1;
        int temp = 1;

        int n = numbers.size();

        for (int i = 1; i < n; ++i)
        {
            if (numbers[i - 1] < numbers[i] and ((numbers[i - 1] % 2 == 0 and numbers[i] % 2 != 0) or (numbers[i - 1] % 2 != 0 and numbers[i] % 2 == 0)))
            {
                ++temp;
            }
            else
            {
                if (temp > max)
                {
                    max = temp;
                }
            }
        }

        if (temp > max)
            max = temp;

        if (not numbers.empty())
            cout << max << endl;
        else
            cout << 0 << endl;
    }
}