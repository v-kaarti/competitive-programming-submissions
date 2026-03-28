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
    int n, bot = INT_MAX, bot_idx = -1; cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
        if (nums[i] < bot) {
            bot += nums[i];
            bot_idx = i;
        }
    }
    vector<pair<int, int>> ops;
    for (int i = 0; i < n; ++i) {
        nums[i] -= bot;
        ops.emplace_back(bot_idx + 1, i + 1);
    }

    for (int i = 1; i < n; ++i) {
        if (nums[i] < nums[i - 1]) {
            nums[i] += nums[i - 1];
            ops.emplace_back(nums[i], nums)
        }
    }
}

signed main() {
    fastio
    int t = 1;
    cin >> t;
    while (t--) solve();
}