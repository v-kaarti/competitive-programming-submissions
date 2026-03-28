#include <bits/stdc++.h>
#define int long long
using namespace std;



signed main() {
    int n = 1000, out = 0, temp;
    vector<int> one(1000);
    unordered_map<int, int> counts;
    for (int i = 0; i < n; ++i) {
        cin >> one[i];
        cin >> temp; counts[temp] += 1;
    }

    for (int i = 0; i < n; ++i) {
        // cout << one[i] << " " << counts[one[i]] << endl;
        out += one[i] * counts[one[i]];
    }

    cout << out;
}