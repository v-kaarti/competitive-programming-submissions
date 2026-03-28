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
    vector<int> v(n); for (auto& e : v) cin >> e;
    int l = 0, r = 0, able = 1;
    while (v[l] != n) l++, r++;
    for (int c = n - 1; c >= 1; --c) {
        if (l > 0 && v[l - 1] == c) {
            l--;
            continue;
        }
        if (r < n - 1 && v[r + 1] == c) {
            r++;
            continue;
        }
        able = 0;
        break;
    }
    cout << (able ? "YES\n" : "NO\n");
}

signed main() {
    fastio
    int t = 1;
    cin >> t;
    while (t--) solve();
}