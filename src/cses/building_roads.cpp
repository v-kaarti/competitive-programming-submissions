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

struct DSU {
    vector<int> p;
    vector<int> sz;

    DSU(int n) {
        p.resize(n + 1);
        sz.resize(n + 1);
        iota(p.begin(), p.end(), 0);
        fill(sz.begin(), sz.end(), 1);
    }

    int find(int u) {
        if (u == p[u]) return u;
        return p[u] = find(p[u]);
    }

    void unite(int u, int v) {
        u = find(u);
        v = find(v);

        if (u == v) return;

        if (sz[u] < sz[v]) swap(u, v);

        p[v] = u;
        sz[u] += sz[v];
    }
};

void solve(){
    int n, m;
    cin >> n >> m;

    DSU s(n + 1);

    vector<pair<int, int>> edges;

    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        s.unite(u, v);
    }

    set<int> track;
    for (int i = 1; i <= n; ++i) track.insert(s.find(i));

    vector<int> leads(track.begin(), track.end());

    cout << leads.size() - 1 << endl;

    for (int i = 1; i < (int) leads.size(); ++i) {
        cout << leads[0] << " " << leads[i] << endl;
    }
   
}

signed main() {
    fastio
    int t = 1;
    // cin >> t;
    while (t--) solve();
}