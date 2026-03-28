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
    int n, X; cin >> n >> X;
    vector<int> v(n), order;
    for (auto& e : v) cin >> e;
    sort(v.begin(), v.end());
    int b = 0, e = n - 1, val = 0, bp = 0;
    while (order.size() < n) {
        if ((val + v[e]) / X > val / X) {
            order.push_back(v[e]);
            val += v[e];
            bp += v[e];
            e--;
        } else {
            order.push_back(v[b]);
            val += v[b];
            b++;
        }
    }
    
    cout << bp << endl;
    for (auto& e : order) cout << e << " ";
    cout << endl;
}

signed main() {
    fastio
    int t = 1;
    cin >> t;
    while (t--) solve();
}