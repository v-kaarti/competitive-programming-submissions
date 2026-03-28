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

int profit(vector<int>& cus_a, vector<int>& cus_b, int price, int k) {
    int n = cus_a.size();

    auto l = lower_bound(cus_a.begin(), cus_a.end(), price);
    auto r = lower_bound(cus_b.begin(), cus_b.end(), price);

    int li = distance(cus_a.begin(), l);
    int ri = distance(cus_b.begin(), r);  

    int total = (n - ri), bad = li - ri;

    return bad > k ? 0 : price * total;
}

void solve(){
    int n, k, ans = 0;
    cin >> n >> k;
    vector<int> cus_a(n), cus_b(n);
    vector<int> boundaries;
    for (int i = 0; i < n; ++i) {
        cin >> cus_a[i];
        boundaries.push_back(cus_a[i]);
    }
    for (int i = 0; i < n; ++i) {
        cin >> cus_b[i];
        boundaries.push_back(cus_b[i]);
    }

    sort(cus_a.begin(), cus_a.end());
    sort(cus_b.begin(), cus_b.end());

    for (auto& price : boundaries) {
        ans = max(ans, profit(cus_a, cus_b, price, k));
    }

    cout << ans << endl;
}

signed main() {
    fastio
    int t = 1;
    cin >> t;
    while (t--) solve();
}