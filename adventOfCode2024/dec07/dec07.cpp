#include <iostream>
#// INCLUDES
#include <fstream>
#include <unordered_map>
#include <vector>
#include <sstream>

using namespace std;

void check(
    int i,
    vector<int> &vec,
    long sum,
    long tar,
    bool &flag)
{
    if (flag)
        return;

    if (i == vec.size())
    {
        if (sum == tar)
            flag = true;
        return;
    }

    check(
        i + 1,
        vec,
        sum + vec[i],
        tar,
        flag);

    if (sum == 0)
        sum = 1;

    check(
        i + 1,
        vec,
        sum * vec[i],
        tar,
        flag);

    return;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ifstream cin("input.txt");

    string t;

    long res = 0;

    while (getline(cin, t))
    {
        stringstream s(t);

        char _;
        long tar;

        s >> tar >> _;

        vector<int> vec;
        int a;

        while (s >> a)
            vec.push_back(a);

        bool flag = false;

        check(0, vec, 0, tar, flag);

        if (flag)
            res += tar;

        cout << flag << endl;
    }

    cout << res << endl;

    cerr << endl
         << "finished in "
         << clock() * 1.0 / CLOCKS_PER_SEC
         << " sec"
         << endl;
    return 0;
}
