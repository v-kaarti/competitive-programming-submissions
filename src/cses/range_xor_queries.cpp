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

vector<int> seg;

int query(int v, int tl, int tr, int ql, int qr) {
    if (tl >= ql && tr <= qr) return seg[v];
    if (ql > tr || qr < tl) return 0;

    int m = (tl + tr) >> 1;
    int l = query(v << 1, tl, m, ql, qr);
    int r = query(v << 1 | 1, m + 1, tr, ql, qr); 

    return l ^ r;
}

void build(int v, int tl, int tr, vector<int>& nums) {
    if (tl == tr) {
        seg[v] = nums[tl];
        return;
    }

    int m = (tl + tr) >> 1;
    build(v << 1, tl, m, nums);
    build(v << 1 | 1, m + 1, tr, nums);

    seg[v] = seg[v << 1] ^ seg[v << 1 | 1];
}

void solve(){
    int n, q;
    cin >> n >> q;
    seg.resize(4 * n);
    vector<int> nums(n);
    for (auto& e : nums) cin >> e;
    build(1, 0, n - 1, nums);

    while (q--) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        cout << query(1, 0, n - 1, a, b) << endl;
    }
}

signed main() {
    fastio
    int t = 1;
    // cin >> t;
    while (t--) solve();
}