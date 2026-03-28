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

// na's last hope
void solve(){
    int n, m; cin >> n >> m;
    vector<int> avec(n), bvec(m);
    
    for (auto& e : avec) cin >> e;
    for (auto& e : bvec) cin >> e;

    if (accumulate(avec.begin(), avec.end(), 0) != accumulate(bvec.begin(), bvec.end(), 0)) {
        cout << "NO" << endl;
        return;
    }

    unordered_map<int, int> a;
    for (auto& e : avec) a[e] += 1;

    // go backwards
    multiset<int, greater<int>> b(bvec.begin(), bvec.end());

    // mazincore
    auto constructable = [&](int v, auto&& constructable) -> bool {
        if (a[v] > 0) {
            a[v] -= 1;
            return true;
        }

        if (v == 1) return false;

        return constructable(v / 2, constructable) && constructable(v - v / 2, constructable);
    };

    
    for (auto& v : b) {
        if (!constructable(v, constructable)) {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
}

signed main() {
    fastio
    int t = 1;
    cin >> t;
    while (t--) solve();
}