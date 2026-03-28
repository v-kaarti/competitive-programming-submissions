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

void printv(vector<int>& v) {
    for (auto& e : v) cout << e << " ";
    cout << endl;
}
void solve(){
    int n; cin >> n;
    vector<int> v(n), mx(n); for (auto& e : v) cin >> e;
    mx[0] = v[0];
    for (int i = 1; i < n; ++i) mx[i] = max(mx[i - 1], v[i]);
    int ans = 0;
    for (int i = 1; i < n; ++i) {
        if (i % 2 && v[i] <= v[i - 1]) {
            v[i] = mx[i];
            ans += max(0LL, v[i - 1] - v[i] + 1);
            v[i - 1] = v[i] - 1;
        }
        else if (i % 2 == 0 && v[i] >= v[i - 1]) {
            v[i - 1] = mx[i - 1];
            ans += max(0LL, v[i] - v[i - 1] + 1);
            v[i] = v[i - 1] - 1;
        }
    }
    cout << ans << endl;
}

signed main() {
    fastio
    int t = 1;
    cin >> t;
    while (t--) solve();
}