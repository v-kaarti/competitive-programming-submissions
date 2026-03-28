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
    vector<set<int>> adj(n);
    vector<pair<int, int>> deg(n);

    for (int i = 1; i < n; i += 1) {
        int u, v; cin >> u >> v;
        // CANCER BARBS SEGFAULT
        u--, v--;
        adj[u].insert(v);
        adj[v].insert(u);
        deg[u] = {deg[u].first + 1, u};
        deg[v] = {deg[v].first + 1, v};
    }

    sort(deg.begin(), deg.end(), greater<pair<int, int>>());
    int f = -1, s = -1;
    vector<int> first, second;
    for (auto& [d, v] : deg) {
        if (f == -1) f = d;
        if (d == f) first.push_back(v);
        else {
            if (s == -1) s = d;
            if (d == s) second.push_back(v);
            else {
                break;
            }
        }
    }


    // 3 always poss
    if (first.size() >= 3) cout << 2 * f - 1;
    // 2, 1 cases
    else if (first.size() >= 2) {
        if (adj[first[0]].contains(first[1])) cout << 2 * f - 2;
        else cout << 2 * f - 1;
    } else {
        for (auto& e : second) {
            if (!adj[first[0]].contains(e)) {
                cout << f + s - 1 << endl;
                return;
            }
        }
        cout << f + s - 2;
    }
    cout << endl;
}

signed main() {
    fastio
    int t = 1;
    cin >> t;
    while (t--) solve();
}