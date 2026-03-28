// scale ai submission file
// note: compile with c++20

#include <bits/stdc++.h>
using namespace std;

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
    int n, m, ans = 0;
    cin >> n >> m;
    vector<vector<int>> store(n), parent(n, vector<int>(n, -1)), uniq(n, vector<int>(n, -1));

    auto first_dfs = [&](int v, int p, int rt, auto&& dfs) -> void {
        parent[rt][v] = p;
        for (auto to : store[v]) if (to != p) dfs(to, v, rt, dfs);
    };
    
    auto second_dfs = [&](int v, int p, int b, auto&& dfs2) -> void {
        if (uniq[b][v] == v) ans++, b = v;
        for (auto to : store[v]) if (to != p) dfs2(to, v, b, dfs2);
    };

    auto constructor = [&](int a, int b, auto&& add) -> void {
        if (uniq[a][b] == b || uniq[b][a] == a) return;
        if (uniq[a][b] != -1) add(uniq[a][b], b, add);
        else if (uniq[b][a] != -1) add(uniq[b][a], a, add);
        else {
            uniq[a][b] = b, uniq[b][a] = a;
            vector<pair<int, int>> upcoming;
            queue<int> q;
            q.push(b);
            while (!q.empty()) {
                auto v = q.front(); q.pop();
                for (auto to : store[v]) {
                    if (to != parent[a][v]) {
                        if (uniq[a][to] != -1) upcoming.pb(mp(to, b));
                        else uniq[a][to] = b, q.push(to);
                    }
                }
            }
            q.push(a);
            while (!q.empty()) {
                auto v = q.front(); q.pop();
                for (auto to : store[v]) {
                    if (to != parent[b][v]) {
                        if (uniq[b][to] != -1) upcoming.pb(mp(to, a));
                        else uniq[b][to] = a, q.push(to);
                    }
                }
            }
            for (auto& p : upcoming) add(p.first, p.second, add);
        }
    };

    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        a--, b--;
        store[a].pb(b), store[b].pb(a);
    }

    for (int i = 0; i < n; i++) first_dfs(i, -1, i, first_dfs);

    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        a--, b--;
        constructor(a, b, constructor);
    }

    for (int i = 0; i < n; i++) for (auto to : store[i]) second_dfs(to, i, i, second_dfs);

    cout << ans / (int) 2 << endl;
}

signed main() {
    fastio
    int t = 1;
    // cin >> t;
    while (t--) solve();
}