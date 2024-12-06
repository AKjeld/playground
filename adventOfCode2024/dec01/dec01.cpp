#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main() {
    ifstream cin("input.txt");  // Redirect cin to read from the file
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a, b, c = 0, d = 0;
    
    vector<int> vec_a;
    
    vector<int> vec_b;

    while (cin >> a >> b) 
    {
        vec_a.push_back(a);
        vec_b.push_back(b);
        c++;
    }

    sort(vec_a.begin(), vec_a.end());
    sort(vec_b.begin(), vec_b.end());

    for (int i = 0; i < c; i++)
    {
        d += abs(vec_a[i] - vec_b[i]);
    }

    cout << d << endl;

    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}
