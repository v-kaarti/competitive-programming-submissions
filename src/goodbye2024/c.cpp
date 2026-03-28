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

unordered_map<int, pair<int, int>> memo;

pair<int, int> bang(int n, int k) {
    if (n < k) return {0, 0};
    if (memo.contains(n)) return memo[n];

    pair<int, int> ans;
    int m = (n + 1) / 2, rec = n / 2;
    auto [running, count] = bang(rec, k);

    if (n % 2 == 0) {
        ans = {2 * running + rec * count, 2 * count};
    }
    else {
        ans = {m + 2 * running + m * count, 2 * count + 1};
    }
    return (memo[n] = ans);
}

void solve() {
    memo = unordered_map<int, pair<int, int>>();
    int n, k;
    cin >> n >> k;
    cout << 
        (k > n ? 0 :
                    k == 1 ? n * (n + 1) / 2 :
                        bang(n, k).first) << endl;
}

signed main() {
    fastio
    int t = 1;
    cin >> t;
    while (t--) solve();
}
