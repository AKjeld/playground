#include <iostream>
// INCLUDES
#include <fstream>
#include <unordered_map>
#include <vector>
#include <sstream>

using namespace std;

unordered_map<int, unordered_map<int, bool>> compare;

bool comp(int a, int b)
{
    return compare[a][b];
}

bool isValid(vector<int> row)
{
    return is_sorted(row.begin(), row.end(), comp);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ifstream cin("input.txt");

    int a, b;
    char delimiter;

    string token;

    while (getline(cin, token))
    {
        stringstream ss(token);
        if (!(ss >> a >> delimiter >> b))
            break;

        compare[a][b] = true;
    }

    long res = 0;

    string line;

    while (getline(cin, line))
    {
        vector<int> row;
        stringstream s(line);

        while (getline(s, token, ','))
        {
            row.push_back(stoi(token));
        }

        if (!isValid(row))
        {
            sort(row.begin(), row.end(), comp);
            res += row[row.size() / 2];
        }
    }

    cout << res << endl;

    cerr << endl
         << "finished in $"
         << clock() * 1.0 / CLOCKS_PER_SEC
         << " sec"
         << endl;
    return 0;
}
