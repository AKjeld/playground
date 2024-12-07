#include <iostream>
// INCLUDES
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

int main()
{
    ifstream cin("input.txt");
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string line;

    int a, b, res = 0;
    bool c;

    bool dampener = false;

    while (getline(cin, line))
    {
        dampener = false;

        vector<int> e;
        istringstream iss(line);

        while (iss >> a)
        {
            e.push_back(a);
        }

        vector<vector<int>> matrix;

        for (int i = 0; i < e.size(); i++)
        {
            vector<int> tmp(e);
            tmp.erase(tmp.begin() + i);

            matrix.push_back(tmp);
        }

        for (auto i : matrix)
        {
            bool flag = true;

            a = i[0];
            b = i[1];

            c = a > b;

            for (int j = 1; j < i.size(); j++)
            {
                b = i[j];
                
                if (abs(a - b) > 3 || a - b == 0)
                {
                    flag = false;
                    break;
                }

                if (c && a < b)
                {
                    flag = false;
                    break;
                }

                if (!c && a > b)
                {
                    flag = false;
                    break;
                }

                a = b;
            }

            if (flag) {
                res++;
                break;
            }
        }
    }

    cout << res << endl;

    cerr << endl
         << "finished in "
         << clock() * 1.0 / CLOCKS_PER_SEC
         << " sec"
         << endl;

    return 0;
}
