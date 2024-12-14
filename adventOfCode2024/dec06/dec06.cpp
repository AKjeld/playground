#include <iostream>
// INCLUDES
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

char turn(char d)
{
    switch (d)
    {
    case 'v':
        return '<';
    case '<':
        return '^';
    case '^':
        return '>';
    case '>':
        return 'v';
    default:
        return '1';
    }
}

vector<vector<char>> move(
    char a,
    int x,
    int y,
    vector<vector<char>> map)
{
    int xcp = x, ycp = y;

    if (
        a == '>' && ++y > (map[x].size() - 1) ||
        a == 'v' && ++x > (map.size() - 1) ||
        a == '<' && --y < 0 ||
        a == '^' && --x < 0)
    {
        return map;
    }

    if (map[x][y] == '#')
        return move(turn(a), xcp, ycp, map);

    map[x][y] = 'X';

    return move(a, x, y, map);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ifstream cin("input.txt");

    vector<vector<char>> map;
    string t;

    int x, y, i = 0;
    char a;

    while (getline(cin, t))
    {
        vector<char> vec_a;
        stringstream ss(t);

        int j = 0;

        while (ss >> a)
        {
            if (turn(a) != '1')
                x = i, y = j;

            vec_a.push_back(a);
            j++;
        }

        i++;
        map.push_back(vec_a);
    }

    map = move(map[x][y], x, y, map);

    int res = 0;

    for (auto vec : map)
        for (auto c : vec)
            res += c == 'X';

    cout << res;

    cerr << endl
         << "finished in "
         << clock() * 1.0 / CLOCKS_PER_SEC
         << " sec"
         << endl;
    return 0;
}
