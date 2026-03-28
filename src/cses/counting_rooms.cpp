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

    int n, m; cin >> n >> m;
    vector<vector<char>> a(n, vector<char>(m));
    for (auto& e :a) {
        string s;
        cin >> s;
        for (int i = 0; i < m; ++i) e[i] = s[i];
    }

    auto dfs = [&](int r, int c, auto&& dfs) -> void {
        a[r][c] = '#';
        for (int dr = -1; dr <= 1; ++dr) {
            for (int dc = -1; dc <= 1; ++dc) {
                if (abs(dr) + abs(dc) != 1) continue;
                int nr = r + dr, nc = c + dc;
                if (min(nr, nc) < 0 || nr >= n || nc >= m) continue;
                if (a[nr][nc] == '#') continue;
                dfs(nr, nc, dfs);
            }
        }
    };

    int ans = 0;

    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < m; ++c) {
            if (a[r][c] == '.') ans++, dfs(r, c, dfs);
        }
    }

    cout << ans << endl;
}

signed main() {
    fastio
    int t = 1;
    // cin >> t;
    while (t--) solve();
}