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
    vector<vector<int>> arrs(n);
    int twodex = -1, twomn = INT_MAX;
    int mn = INT_MAX;
    for (int i = 0; i < n; ++i) {
        auto& a = arrs[i];
        int l; cin >> l;
        a.resize(l);
        for (auto& e : a) cin >> e;
        sort(a.begin(), a.end());
        if (a[1] < twomn) twodex = i, twomn = a[1];
        mn = min(mn, a[0]);
    }
    
    int s = 0;
    for (int i = 0; i < n; ++i) {
        if (i == twodex) s += mn;
        else s += arrs[i][1];
    }

    cout << s << endl;
}

signed main() {
    fastio
    int t = 1;
    cin >> t;
    while (t--) solve();
}