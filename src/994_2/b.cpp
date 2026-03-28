#include <bits/stdc++.h>
using namespace std;

//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//template <class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);

#define int long long
#define endl "\n";
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) (int)(x).size()
#define mp(x, y) make_pair((x), (y))
#define pb push_back
#define INF (1LL << 59)

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    vector<pair<int, int>> vec;
    for (int i = 0; i < s.size(); ++i) {
        int idx = i + 1;
        if (s[i] == 's') vec.emplace_back(idx, s.size());
        if (s[i] == 'p') vec.emplace_back(1, idx);
    }

    sort(vec.begin(), vec.end(), [](auto a, auto b) {
        int a_size = a.second - a.first;
        int b_size = b.second - b.first;
        return a_size < b_size;
    });

    for (int i = 0; i < (int) vec.size() - 1; ++i) {
        auto [a, b] = vec[i];
        auto [c, d] = vec[i + 1];
        if (!(a >= c && b <= d)) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}

signed main() {
    fastio
    int t = 1;
    cin >> t;
    while (t--) solve();
}