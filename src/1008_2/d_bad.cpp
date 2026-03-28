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
    vector<pair<char, int>> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second >> b[i].first >> b[i].second;
    }

    vector<int> mul_a(n), mul_b(n);

    mul_a[n - 1] = a[n - 1].first == 'x' ? a[n - 1].second : 1;
    mul_b[n - 1] = b[n - 1].first == 'x' ? b[n - 1].second : 1;

    for (int i = n - 2; i >= 0; --i) {
        mul_a[i] = a[i].first == 'x' ? a[i].second * mul_a[i + 1] : mul_a[i + 1];
        mul_b[i] = b[i].first == 'x' ? b[i].second * mul_b[i + 1] : mul_b[i + 1];
    }

    int l = 1, r = 1;
    for (int i = 0; i < n; ++i) {
        int extra_l = a[i].first == '+' ? a[i].second : (a[i].second - 1) * l;
        int extra_r = b[i].first == '+' ? b[i].second : (b[i].second - 1) * r;

        if (i == n - 1 || mul_a[i + 1] > mul_b[i + 1]) l += extra_l + extra_r;
        else r += extra_l + extra_r;
    }

    cout << l + r << endl;
}

signed main() {
    fastio
    int t = 1;
    cin >> t;
    while (t--) solve();
}