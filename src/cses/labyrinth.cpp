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
    pair<int, int> start, end;
    bool ok = false;

    vector<vector<char>> a(n, vector<char>(m));
    for (int r = 0; r < n; ++r) {
        string s;
        cin >> s;
        for (int c = 0; c < m; ++c) {
            a[r][c] = s[c];
            if (a[r][c] == 'A') start = {r, c};
            if (a[r][c] == 'B') end = {r, c};
        }
    }

    vector<vector<pair<pair<int, int>, char>>> prev(n, vector<pair<pair<int, int>, char>>(m));

    queue<pair<int, int>> q;

    q.push(start);

    while (!q.empty()) {
        if (q.front() == end) {
            ok = true;
            break;
        }

        auto [r, c] = q.front();
        q.pop();

        for (int dr = -1; dr <= 1; ++dr) {
            for (int dc = -1; dc <= 1; ++dc) {
                int nr = r + dr, nc = c + dc;
                if (abs(dr) + abs(dc) != 1) continue;
                if (min(nr, nc) < 0 || nr >= n || nc >= m) continue;
                if (a[nr][nc] == '#') continue;

                a[nr][nc] = '#';
                char dir;
                if (dr == 0 && dc == 1) dir = 'R';
                if (dr == 0 && dc == -1) dir = 'L';
                if (dr == 1 && dc == 0) dir = 'D';
                if (dr == -1 && dc == 0) dir = 'U';

                prev[nr][nc] = {{r, c}, dir};
                q.push({nr, nc});
            }
        }
    }

    if (!ok) {
        cout << "NO";
        return;
    }

    pair<int, int> back = end;
    string out;
    while (back != start) {
        auto [r, c] = back;
        auto [before, dir] = prev[r][c];
        out.push_back(dir);
        back = before;
    }

    reverse(out.begin(), out.end());
    cout << "YES" << endl << out.size() << endl << out;
}

signed main() {
    fastio
    int t = 1;
    // cin >> t;
    while (t--) solve();
}