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

void solve() {
    int n, mx = 0; cin >> n;
    string b(n, '0');
    vector<pair<int, int>> v(n);

    for (auto& [l , r] : v) {
        cin >> l >> r;
        mx = max(mx, r);
    }

    vector<int> counts(mx + 1, 0), o(mx + 1, 0);
    
    for (int i = 0; i < n; ++i) {
        if (v[i].first == v[i].second) {
            o[v[i].first] = 1;
            counts[v[i].first] += 1;
        }
    }

    for (int i = 1; i < o.size(); ++i) o[i] += o[i - 1];
    for (int i = 0; i < n; ++i) {
        auto [l, r] = v[i];
        int count = r - l + 1, occ = o[r] - o[l - 1];
        if (l == r && counts[l] == 1) occ -= 1;
        if (count > occ) b[i] = '1';
    }
    cout << b << endl;
}

signed main() {
    fastio
    int t = 1;
    cin >> t;
    while (t--) solve();
}