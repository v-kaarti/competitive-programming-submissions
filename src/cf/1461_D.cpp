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
    vector<int> a(n), s(q), prefix(n);
    unordered_set<int> sums;
    for (auto& e : a) cin >> e;
    for (auto& e : s) cin >> e;
    sort(a.begin(), a.end());
    prefix[0] = a[0];
    for (int i = 1; i < n; ++i) prefix[i] = prefix[i - 1] + a[i];
    auto process = [&](int l, int r, auto&& process) -> void {
        if (a[l] == a[r]) {
            sums.insert(a[l] * (r - l + 1));
            return;
        }

        int sum = prefix[r]; 
        if (l > 0) sum -= prefix[l - 1];
        sums.insert(sum);

        int m = (a[r] + a[l]) / 2, p = l;
        while (a[p] <= m) p++;

        process(l, p - 1, process), process(p, r, process);
    };
    process(0, n - 1, process);
    for (auto& query : s) {
        if (sums.contains(query)) cout << "YES\n";
        else cout << "NO\n";
    }
}

signed main() {
    fastio
    int t = 1;
    cin >> t;
    while (t--) solve();
}   