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
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (auto& e : nums) cin >> e;
    int pairs = 0;
    map<int, int> counter;
    for (auto& e : nums) counter[e] += 1;
    for (auto& [key, v] : counter) {
        if (key > k / 2) break;
        if (k % 2 == 0 && key == k / 2) pairs += counter[key] / 2;
        else pairs += min(counter[key], counter[k - key]);
    }
    cout << pairs << endl;
}

signed main() {
    fastio
    int t = 1;
    cin >> t;
    while (t--) solve();
}