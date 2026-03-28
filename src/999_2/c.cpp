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

int M = 998244353;

void solve(){
    int n, ans = 0; cin >> n;
    vector<int> nums(n);
    for (auto& e : nums) cin >> e;

    // one indexed
    vector<map<int, int>> dp(n + 2, {{}});

    dp[1][0] = 1;
    for (int i = 1; i <= n; i += 1) {
        for (auto& [liars, count] : dp[i]) {
            int curr = nums[i - 1], next = -1;

            // honesty angle
            if (curr == liars) dp[i + 1][liars] = (dp[i + 1][liars] + count) % M;

            // we can lie
            if (i < n) {
                next = nums[i - 1 + 1];
                if (liars + 1 == next) dp[i + 2][liars + 1] = (dp[i + 2][liars + 1] + count) % M;
            } 

            // free lie
            if (next == -1) {
                dp[i + 1][liars + 1] = (dp[i + 1][liars + 1] + count) % M;
            }
        }
    }

    for (auto& [_, v] : dp[n + 1]) ans = (ans + v) % M;
    cout << ans << endl;
}

signed main() {
    fastio
    int t = 1;
    cin >> t;
    while (t--) solve();
}