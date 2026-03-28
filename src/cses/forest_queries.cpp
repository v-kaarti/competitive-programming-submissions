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
    int n, q;
    cin >> n >> q;
    string s;
    vector<vector<int>> f(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; ++i) {
        cin >> s;
        for (int j = 1; j <= n; ++j) {
            f[i][j] = s[j - 1] == '.' ? 0 : 1;  
        }
    }
    vector<vector<int>> p(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            p[i][j] = p[i - 1][j] + p[i][j - 1] + f[i][j] - p[i - 1][j - 1];
        }
    }

    while (q--) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;

        cout << (p[r2][c2] - p[r2][c1 - 1] - p[r1 - 1][c2] + p[r1 - 1][c1 - 1]) << endl;
    }
}

signed main() {
    fastio
    int t = 1;
    // cin >> t;
    while (t--) solve();
}