#include <iostream>
// INCLUDES
#include <fstream>
#include <unordered_map>
#include <vector>
#include <sstream>
#include <set>

using namespace std;

pair<int, int> calc_dist(pair<int, int> pair_a, pair<int, int> pair_b)
{
    return make_pair(pair_a.first - pair_b.first, pair_a.second - pair_b.second);
}

bool in_bounds(pair<int, int> pair, int xlen, int ylen)
{
    return pair.first < xlen && pair.first >= 0 && pair.second < ylen && pair.second >= 0;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ifstream cin("input.txt");

    unordered_map<char, vector<pair<int, int>>> map_list;

    set<pair<int, int>> res;

    string t;

    int n, m, i = 0;

    while (cin >> t)
    {
        stringstream s(t);
        char a;
        int j = 0;

        while (s >> a)
        {
            if (a != '.')
                map_list[a].push_back((make_pair(i, j)));
            j++;
        }

        m = j;
        i++;
    }

    n = i;

    for (auto antenna : map_list)
    {
        vector<pair<int, int>> &vec = antenna.second;

        for (int i = 0; i < vec.size() - 1; i++)
        {
            pair<int, int> p = vec[i];

            for (int j = i + 1; j < vec.size(); j++)
            {
                pair<int, int> dist = calc_dist(p, vec[j]);

                pair<int, int> anti = p;

                while (in_bounds(anti, n, m))
                {
                    res.insert(anti);
                    anti = calc_dist(anti, dist);
                }

                dist = calc_dist(vec[j], p);
                anti = p;

                while (in_bounds(anti, n, m))
                {
                    res.insert(anti);
                    anti = calc_dist(anti, dist);
                }
            }
        }
    }

    cout << res.size() << endl;

    cerr << endl
         << "finished in "
         << clock() * 1.0 / CLOCKS_PER_SEC
         << " sec"
         << endl;
    return 0;
}
