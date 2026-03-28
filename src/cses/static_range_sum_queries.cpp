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
    int n, q; cin >> n >> q;
    vector<int> nums(n);
    for (auto& e : nums) cin >> e;
    vector<int> p(n);
    p[0] = nums[0];
    for (int i = 1; i < n; ++i) p[i] = p[i - 1] + nums[i];
    while (q--) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        cout << p[b] - p[a] + nums[a] << endl;
    }
    
}

signed main() {
    fastio
    int t = 1;
    // cin >> t;
    while (t--) solve();
}