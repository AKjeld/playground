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

    string token;
    string match = "(lum";

    long res = 0;

    bool evil = false;
    int a;

    while (getline(cin, token, ')'))
    {
        a = token.length();

        if (!evil && a > 5 && token.substr(a - 6, a) == "don't(")
        {
            evil = true;
            continue;
        }

        if (evil)
        {
            evil = !(a > 2 && token.substr(a - 3, a) == "do(");
            continue;
        }

        reverse(token.begin(), token.end());

        int i = token.find(match);

        if (i == -1)
        {
            continue;
        }

        token = token.substr(0, i + match.length());

        reverse(token.begin(), token.end());
        token = token.substr(4, token.length());

        stringstream s(token);

        int a, b;
        char delimiter;

        if (!(s >> a >> delimiter >> b))
            continue;
        if (delimiter != ',' || a > 999 || a <= 0 || b > 999 || b <= 0)
            continue;
        if (s >> delimiter)
            continue;

        res += a * b;

        cout << token << endl;
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
