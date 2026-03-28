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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n + 1, vector<int>());
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> colors(n + 1, -1);

    bool ok = true;

    auto dfs = [&](int u, auto&& dfs) {
        if (!ok) return;
        for (auto& v : g[u]) {
            if (colors[v] == colors[u])  {
                ok = false;
                return;
            }

            if (colors[v] != -1) continue;

            int next_color = (colors[u] == 1 ? 2 : 1);
            colors[v] = next_color;
            dfs(v, dfs);
        }
    };

    for (int i = 1; i <= n; ++i) {
        if (colors[i] != -1) continue;
        else colors[i] = 1;
        dfs(i, dfs);
    }

    if (!ok) {
        cout << "IMPOSSIBLE";
        return;
    }

    for (int i = 1; i <= n; ++i) {
        cout << colors[i] << " ";
    }
}

signed main() {
    fastio
    int t = 1;
    // cin >> t;
    while (t--) solve();
}