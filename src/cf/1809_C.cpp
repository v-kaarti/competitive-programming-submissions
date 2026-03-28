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

vector<int> solve_nk(int n, int k) {
    if (n == 0) return {};
    if (k < n) {
        vector<int> v(n, -1);
        if (k > 0) v[k - 1] = 100, v[k] = -200;
        return v;
    } else {
        vector<int> v = solve_nk(n - 1, k - n);
        v.push_back(1000);
        return v;
    }
}

void solve(){
    int n, k; cin >> n >> k;
    for (auto& e : solve_nk(n, k)) cout << e << " ";
    cout << endl;
}

signed main() {
    fastio
    int t = 1;
    cin >> t;
    while (t--) solve();
}