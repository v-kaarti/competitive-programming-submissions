#include <bits/stdc++.h>
#define int long long
using namespace std;



signed main() {
    int n = 1000, out = 0;
    vector<int> one(1000), two(1000);
    for (int i = 0; i < n; ++i) {
        cin >> one[i] >> two[i];
    }
    sort(one.begin(), one.end());
    sort(two.begin(), two.end());

    for (int i = 0; i < n; ++i) {
        out += abs(one[i] - two[i]);
    }

    cout << out;
}