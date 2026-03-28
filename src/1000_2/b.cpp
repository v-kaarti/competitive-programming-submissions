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

// 1 1

void solve(){
    int n, l, r, sum = 0, range_sum = 0, mod_sum = 0;
    cin >> n >> l >> r;
    r--, l--;
    vector<int> nums(n);
    for (auto& e : nums) cin >> e, sum += e;
    
    vector<int> beg, mid, end;

    for (int i = 0; i < l; i += 1) beg.push_back(nums[i]);
    for (int i = l; i <= r; i += 1) {
        mid.push_back(nums[i]);
        range_sum += nums[i];
    }

    mod_sum = range_sum;

    for (int i = r + 1; i < n; i += 1) end.push_back(nums[i]);

    sort(beg.begin(), beg.end());
    sort(mid.begin(), mid.end(), greater<int>());
    sort(end.begin(), end.end());

    int take_beg = min(mid.size(), beg.size());
    int take_end = min(mid.size(), end.size());

    for (int i = 1; i < beg.size(); i += 1) beg[i] += beg[i - 1];
    for (int i = 1; i < mid.size(); i += 1) mid[i] += mid[i - 1];
    for (int i = 1; i < end.size(); i += 1) end[i] += end[i - 1];

    for (int take = 1; take <= take_beg; take += 1) mod_sum = min(mod_sum, range_sum + beg[take - 1] - mid[take - 1]);
    for (int take = 1; take <= take_end; take += 1) mod_sum = min(mod_sum, range_sum + end[take - 1] - mid[take - 1]);

    cout << mod_sum << endl;
}

signed main() {
    fastio
    int t = 1;
    cin >> t;
    while (t--) solve();
}