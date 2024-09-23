#include <iostream>
#include <map>

using namespace std;

int main()
{
    // Character that will be read
    char c;

    // Map that will have the primary key as the value and the value as the number of repetitions
    map<int, int> list_num;

    while (cin >> c)
    {
        if (c == 'A')
        {
            if (list_num.empty())
            {
                cout << "error!" << endl;
            }
            else
            {
                map<int, int>::iterator it = list_num.end();

                int greatest = (--it)->first;

                if (list_num[greatest] > 0)
                    cout << greatest << endl;
            }
        }
        else if (c == 'S')
        {
            int number;
            cin >> number;

            list_num[number]++;
        }
        else if (c == 'R')
        {
            if (!list_num.empty())
            {
                map<int, int>::iterator it = list_num.end();
                --it;
                int greatest = it->first;

                --list_num[greatest];

                if (list_num[greatest] <= 0)
                    list_num.erase(it);
            }
            else
            {
                cout << "error!" << endl;
            }
        }
        else if (c == 'I')
        {
            int number;
            cin >> number;

            if (!list_num.empty())
            {
                map<int, int>::iterator it = list_num.end();

                int num = (--it)->first;

                --list_num[num];

                if (list_num[num] <= 0)
                    list_num.erase(it);

                list_num[num + number]++;
            }
            else
            {
                cout << "error!" << endl;
            }
        }
        else if (c == 'D')
        {
            int number;
            cin >> number;

            if (!list_num.empty())
            {
                map<int, int>::iterator it = list_num.end();

                int num = (--it)->first;

                --list_num[num];

                if (list_num[num] <= 0 and it != list_num.end())
                    list_num.erase(it);

                list_num[num - number]++;
            }
            else
            {
                cout << "error!" << endl;
            }
        }
    }
}