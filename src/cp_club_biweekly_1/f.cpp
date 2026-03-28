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
    vector<vector<int>> v(n, vector<int>(3));

    for (int i = 0; i < n; ++i) cin >> v[i][0];
    for (int i = 0; i < n; ++i) cin >> v[i][1];
    for (int i = 0; i < n; ++i) cin >> v[i][2];

    int last = v[0][0];
    cout << last << " ";
    for (int i = 1; i < n - 1; ++i) {
        if (v[i][0] == last) cout << (last = v[i][1]);
        else cout << (last = v[i][0]);
        cout << " ";
    }

    for (int i = 0; i < 3; ++i) {
        if (v[n - 1][i] == last || v[n - 1][i] == v[0][0]) continue;
        cout << v[n - 1][i];
        break;
    }
    cout << endl;
}

signed main() {
    fastio
    int t = 1;
    cin >> t;
    while (t--) solve();
}