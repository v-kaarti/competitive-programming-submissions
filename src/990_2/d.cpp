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
    vector<int> nums(n);
    for (auto& e : nums) cin >> e;
    vector<int> sor(n);
    sor[n - 1] = INF;
    int at_back = -1;
    for (int i = n - 2; i >= 0; --i) sor[i] = min(nums[i + 1], sor[i + 1]);
    for (int i = 0; i < n; ++i) {
        if (sor[i] < nums[i]) {
            nums[i]++;
            if (at_back == -1) at_back = nums[i];
            else at_back = min(at_back, nums[i]);
        } else if (at_back != -1 && nums[i] > at_back) {
            nums[i]++;
            if (at_back == -1) at_back = nums[i];
            else at_back = min(at_back, nums[i]);
        }
    }
    sort(nums.begin(), nums.end());
    for (auto& e : nums) cout << e << " ";
    cout << endl;
}

signed main() {
    fastio
    int t = 1;
    cin >> t;
    while (t--) solve();
}