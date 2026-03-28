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
    vector<int> nums(2 * n);
    for (auto& e : nums) cin >> e;
    sort(nums.begin(), nums.end(), greater<>());
    
    int out = 0;
    for (int i = 0; i < 2 * n; ++i) {
        if (i % 2) out -= nums[i];
        else out += nums[i];
    }

    int out2 = 0;
    out2 += (nums[0] + nums[1]);
    for (int i = 2; i < 2 * n; ++i) {
        if (i % 2 == 0) out2 -= nums[i];
        else out2 += nums[i];
    }

    if (out >= out2) {
        cout << out << " ";
        for (auto& e : nums) cout << e << " ";
        cout << endl;
    }

    if (out2 > out) {
        cout << nums[0] << " ";
        cout << out2 << " ";
        for (int i = 1; i < 2 * n; ++i) cout << nums[i] << " ";
        cout << endl;
    }
}

signed main() {
    fastio
    int t = 1;
    cin >> t;
    while (t--) solve();
}