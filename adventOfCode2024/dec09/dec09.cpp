#include <iostream>
// INCLUDES
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int getLast(int &index, vector<int> &vec)
{
    while (index >= 0)
    {
        if (vec[index] != -1)
        {
            return vec[index--];
        }
        index--;
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ifstream cin("input.txt");

    vector<int> a;

    char t;
    int b = 0;
    bool f = true;

    while (cin >> t)
    {
        int ti = (int)t - 48;
        for (int i = 0; i < ti; i++)
        {
            a.push_back(f ? b : -1);
        }
        b += f;
        f = !f;
    }

    int factor = 0;
    int index = a.size() - 1;
    long res = 0;

    for (int indexTwo = 0; indexTwo <= index; indexTwo++)
    {
        int m = a[indexTwo];
        int d = m == -1 ? getLast(index, a) : m;
        res += factor++ * d;
    }

    cout << endl
         << res
         << endl;

    cerr << endl
         << "finished in "
         << clock() * 1.0 / CLOCKS_PER_SEC
         << " sec"
         << endl;
    return 0;
}
