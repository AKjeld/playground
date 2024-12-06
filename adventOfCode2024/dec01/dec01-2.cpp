#include <iostream>
#include <fstream>
#include <unordered_map>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);

    ifstream cin("input.txt"); // Redirect cin to read from the file

    cin.tie(0);
    cout.tie(0);

    int a, b, c = 0;

    unordered_map<int, int> map_a;
    unordered_map<int, int> map_b;

    while (cin >> a >> b)
    {
        map_a[a] += 1;
        map_b[b] += 1;
    }

    for(auto i : map_a) {
        c += i.first * i.second * map_b[i.first];
    }

    cout << c << endl;

    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}
