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

vector<int> a, b;

bool f(int p) {
    int sell = 0, buy = 0;
    for (auto& e : a) if (p >= e) sell++;
    for (auto& e : b) if (p <= e) buy++;
    return sell >= buy;
}

void solve(){
    int n, m;
    cin >> n >> m;
    a.resize(n);
    b.resize(m);
    for (auto& e : a) cin >> e;
    for (auto& e : b) cin >> e;
    int l = -1, r = 1e9 + 1;
    while (r - l > 1) {
        int m = l + (r - l) / 2;
        if (f(m)) r = m;
        else l = m;
    }
    cout << r;
}

signed main() {
    fastio
    int t = 1;
    // cin >> t;
    while (t--) solve();
}