#include <iostream>
// INCLUDES
#include <fstream>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <set>

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

set<pair<int, int>> potentials;

void move(
    char a,
    int x,
    int y,
    vector<vector<char>>& map)
{
    int xcp = x, ycp = y;

    if (
        (a == '>' && ++y > (map[x].size() - 1)) ||
        (a == 'v' && ++x > (map.size() - 1)) ||
        (a == '<' && --y < 0) ||
        (a == '^' && --x < 0))
    {
        return;
    }

    if (map[x][y] == '#')
        return move(turn(a), xcp, ycp, map);

    potentials.insert(make_pair(x, y));

    return move(a, x, y, map);
}

bool detectLoop(
    char a,
    int x,
    int y,
    int dur,
    int maxDuration,
    vector<vector<char>> &map)
{
    // Very insane edgecase if whole loop is overwritten while moving.
    if (map[x][y] == a || dur >= maxDuration) 
        return true;

    map[x][y] = a;

    int xcp = x, ycp = y;

    if (
        (a == '>' && ++y > (map[x].size() - 1)) ||
        (a == 'v' && ++x > (map.size() - 1)) ||
        (a == '<' && --y < 0) ||
        (a == '^' && --x < 0))
    {
        return false;
    }

    if (map[x][y] == '#')
        return detectLoop(turn(a), xcp, ycp, ++dur, maxDuration, map);

    return detectLoop(a, x, y, ++dur, maxDuration, map);
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

    move(map[x][y], x, y, map);

    cout << "TOTAL FIELDS * DIRECTIONS: " << i*i*4 << endl;
    cout << "POTENTIALS: " << potentials.size() << endl;

    int res = 0;

    for (auto p : potentials)
    {
        auto mapx = map;
        mapx[p.first][p.second] = '#';
        mapx[x][y] = '.';

        res += detectLoop(map[x][y], x, y, 0, i*i*4, mapx);
    }

    cout << endl
         << res << endl;

    cerr << endl
         << "finished in "
         << clock() * 1.0 / CLOCKS_PER_SEC
         << " sec"
         << endl;
    return 0;
}
