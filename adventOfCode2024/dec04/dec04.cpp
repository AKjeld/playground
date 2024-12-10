#include <iostream>
// INCLUDES
#include <fstream>
#include <unordered_map>
#include <vector>
#include <sstream>

using namespace std;

int main()
{
    ifstream cin("input.txt");
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    char a;
    string b;

    vector<vector<char>> matr;

    while (getline(cin, b))
    {
        vector<char> c;
        stringstream ssb(b);

        while (ssb >> a)
        {
            c.push_back(a);
        }
        matr.push_back(c);
    }

    bool valid;

    int matrSize = matr.size();

    b = "XMAS";

    string compare;

    int res = 0;

    for (int i = 0; i < matrSize; i++)
    {
        vector<char> c = matr[i];
        int cSize = c.size();

        for (int j = 0; j < cSize; j++)
        {

            bool right = j + b.length() <= cSize;
            bool left = j + 1 >= b.length();
            bool down = i + b.length() <= matrSize;
            bool up = i + 1 >= b.length();

            if (right)
            {
                compare = string() +
                          matr[i][j] +
                          matr[i][j + 1] +
                          matr[i][j + 2] +
                          matr[i][j + 3];

                res += compare == b;
            }
            if (left)
            {
                compare = string() +
                          matr[i][j] +
                          matr[i][j - 1] +
                          matr[i][j - 2] +
                          matr[i][j - 3];

                res += compare == b;
            }
            if (down)
            {
                compare = string() +
                          matr[i][j] +
                          matr[i + 1][j] +
                          matr[i + 2][j] +
                          matr[i + 3][j];

                res += compare == b;
            }
            if (up)
            {
                compare = string() +
                          matr[i][j] +
                          matr[i - 1][j] +
                          matr[i - 2][j] +
                          matr[i - 3][j];

                res += compare == b;
            }
            if (down && right)
            {
                compare = string() +
                          matr[i][j] +
                          matr[i + 1][j + 1] +
                          matr[i + 2][j + 2] +
                          matr[i + 3][j + 3];

                res += compare == b;
            }
            if (down && left)
            {
                compare = string() +
                          matr[i][j] +
                          matr[i + 1][j - 1] +
                          matr[i + 2][j - 2] +
                          matr[i + 3][j - 3];

                res += compare == b;
            }
            if (up && left)
            {
                compare = string() +
                          matr[i][j] +
                          matr[i - 1][j - 1] +
                          matr[i - 2][j - 2] +
                          matr[i - 3][j - 3];

                res += compare == b;
            }
            if (up && right)
            {
                compare = string() +
                          matr[i][j] +
                          matr[i - 1][j + 1] +
                          matr[i - 2][j + 2] +
                          matr[i - 3][j + 3];

                res += compare == b;
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
