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

    vector<int> prev(n + 1, -1);

    prev[1] = n + 1;

    queue<pair<int, int>> q;
    q.emplace(1, 0);

    int cost = -1;

    while (!q.empty()) {
        auto [u, c] = q.front();
        q.pop();

        if (u == n) {
            cost = c;
            break;
        }

        for (auto& v : g[u]) {
            if (prev[v] != -1) continue;
            prev[v] = u;
            q.emplace(v, cost + 1);
        }
    }

    if (cost == -1) {
        cout << "IMPOSSIBLE";
        return;
    }

    int last = n;
    vector<int> moves;

    while (last != n + 1) {
        moves.push_back(last);
        last = prev[last];
    }

    cout << moves.size() << endl;
    reverse(moves.begin(), moves.end());

    for (auto& e : moves) cout << e << " ";
}

signed main() {
    fastio
    int t = 1;
    // cin >> t;
    while (t--) solve();
}