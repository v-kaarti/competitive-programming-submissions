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
    vector<vector<int>> a(n + 1, vector<int>(3));
    vector<vector<int>> dp(n + 1, vector<int>(3));
    for (int d = 1; d <= n; d++) cin >> a[d][0] >> a[d][1] >> a[d][2];
    dp[1][0] = a[1][0];
    dp[1][1] = a[1][1];
    dp[1][2] = a[1][2];
    for (int d = 2; d <= n; d++) {
        dp[d][0] = a[d][0] + max(dp[d - 1][1], dp[d - 1][2]);
        dp[d][1] = a[d][1] + max(dp[d - 1][0], dp[d - 1][2]);
        dp[d][2] = a[d][2] + max(dp[d - 1][0], dp[d - 1][1]);
    }
    cout << max({dp[n][0], dp[n][1], dp[n][2]}) << endl;
}

signed main() {
    fastio
    int t = 1;
    // cin >> t;
    while (t--) solve();
}