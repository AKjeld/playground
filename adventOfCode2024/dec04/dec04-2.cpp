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

    string compare;

    int res = 0;

    for (int i = 1; i < matrSize - 1; i++)
    {
        vector<char> c = matr[i];
        int cSize = c.size();

        for (int j = 1; j < cSize - 1; j++)
        {
            if (matr[i][j] != 'A')
                continue;

            if (
                matr[i - 1][j - 1] == 'M' &&
                matr[i - 1][j + 1] == 'M' &&
                matr[i + 1][j - 1] == 'S' &&
                matr[i + 1][j + 1] == 'S')
            {
                res++;
                continue;
            }
            if (
                matr[i - 1][j - 1] == 'M' &&
                matr[i + 1][j - 1] == 'M' &&
                matr[i - 1][j + 1] == 'S' &&
                matr[i + 1][j + 1] == 'S')
            {
                res++;
                continue;
            }
            if (
                matr[i + 1][j + 1] == 'M' &&
                matr[i + 1][j - 1] == 'M' &&
                matr[i - 1][j + 1] == 'S' &&
                matr[i - 1][j - 1] == 'S')
            {
                res++;
                continue;
            }
            if (
                matr[i + 1][j + 1] == 'M' &&
                matr[i - 1][j + 1] == 'M' &&
                matr[i + 1][j - 1] == 'S' &&
                matr[i - 1][j - 1] == 'S')
            {
                res++;
                continue;
            }
            // // UR
            // if (
            //     matr[i - 1][j] == 'M' &&
            //     matr[i][j + 1] == 'M' &&
            //     matr[i + 1][j] == 'S' &&
            //     matr[i][j - 1] == 'S')
            // {
            //     res++;
            //     continue;
            // }
            // // RD
            // if (
            //     matr[i][j + 1] == 'M' &&
            //     matr[i + 1][j] == 'M' &&
            //     matr[i - 1][j] == 'S' &&
            //     matr[i][j - 1] == 'S')
            // {
            //     res++;
            //     continue;
            // }
            // // DL
            // if (
            //     matr[i + 1][j] == 'M' &&
            //     matr[i][j - 1] == 'M' &&
            //     matr[i - 1][j] == 'S' &&
            //     matr[i][j + 1] == 'S')
            // {
            //     res++;
            //     continue;
            // }
            // // LU
            // if (
            //     matr[i][j - 1] == 'M' &&
            //     matr[i - 1][j] == 'M' &&
            //     matr[i + 1][j] == 'S' &&
            //     matr[i][j + 1] == 'S')
            // {
            //     res++;
            //     continue;
            // }
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
