#include <bits/stdc++.h>
using namespace std;

//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//template <class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);

#define int long long
#define endl "\n"
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) (int)(x).size()
#define mp(x, y) make_pair((x), (y))
#define pb push_back
#define INF (1LL << 59)

void solve(){
    int n, m; cin >> n >> m;
    vector<int> h(n), p(m);
    for (auto& e : h) cin >> e;;
    for (auto& e : p) cin >> e;

    multiset<int> s(h.begin(), h.end());

    for (auto& c : p) {
        auto it = s.upper_bound(c);
        if (it == s.begin()) cout << -1 << endl;
        else {
            auto tix = prev(it);
            cout << *tix << endl;
            s.erase(tix);
        }
    }
}

signed main() {
    fastio
    int t = 1;
    // cin >> t;
    while (t--) solve();
}