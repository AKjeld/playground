#include <iostream>
// INCLUDES
#include <fstream>
#include <sstream>

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

    while (getline(cin, line))
    {
        istringstream iss(line);
        res++;

        iss >> a >> b;
        c = a > b;

        do
        {
            if (abs(a - b) > 3 || a - b == 0)
            {
                res--;
                break;
            }

            if (c && a < b)
            {
                res--;
                break;
            }

            if (!c && a > b)
            {
                res--;
                break;
            }

            a = b;

        } while (iss >> b);
    }

    cout << res << endl;

    cerr << endl
         << "finished in "
         << clock() * 1.0 / CLOCKS_PER_SEC
         << " sec"
         << endl;

    return 0;
}
