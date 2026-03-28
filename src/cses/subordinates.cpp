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
    int n;
    cin >> n;
    vector<vector<int>> g(n + 1, vector<int>());
    for (int i = 2; i <= n; ++i) {
        int p; cin >> p;
        g[p].push_back(i);
    }
    
    vector<int> out(n + 1, 0);
    auto dfs = [&](int p, auto&& dfs) -> void {
        for (auto& c : g[p]) {
            dfs(c, dfs);
            out[p] += out[c] + 1;
        } 
    };
    dfs(1, dfs);
    for (int i = 1; i <= n; ++i) cout << out[i] << " ";
}

signed main() {
    fastio
    int t = 1;
    // cin >> t;
    while (t--) solve();
}