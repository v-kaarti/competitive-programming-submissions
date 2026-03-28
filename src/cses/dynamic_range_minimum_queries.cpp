#include <bits/stdc++.h>
using namespace std;

//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//template <class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);

#define int long long
#define endl "\n"
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) (int)(x).size()
#define mp(x, y) make_pair((x), (y))
#define pb push_back
#define INF (1LL << 59)

vector<int> seg;

void build(vector<int>& nums, int v, int tl, int tr) {
    if (tl == tr) {
        seg[v] = nums[tl];
        return;
    }
    int m = (tl + tr) >> 1;
    build(nums, v << 1, tl, m);
    build(nums, v << 1 | 1, m + 1, tr);
    seg[v] = min(seg[v << 1], seg[v << 1 | 1]);
}

int query(int v, int tl, int tr, int ql, int qr) {
    if (tl >= ql && tr <= qr) return seg[v];
    if (qr < tl || ql > tr) return INF;
    
    int m = (tl + tr) >> 1; 
    int l = query(v << 1, tl, m, ql, qr);
    int r = query(v << 1 | 1, m + 1, tr, ql, qr);

    return min(l ,r);
}

void update(int v, int tl, int tr, int pos, int val) {
    if (tl == pos && tr == pos) {
        seg[v] = val;
        return;
    }

    if (pos < tl || pos > tr) return;

    int m = (tl + tr) >> 1;
    
    update(v << 1, tl, m, pos, val);
    update(v << 1 | 1, m + 1, tr, pos, val); 

    seg[v] = min(seg[v << 1], seg[v << 1 | 1]);
}

void solve(){
    int n, q, type, a, b;
    cin >> n >> q;
    vector<int> nums(n);
    for (auto& e : nums) cin >> e;

    seg.resize(4 * n);
    build(nums, 1, 0, n - 1);

    while (q--) {
        cin >> type >> a >> b;
        if (type == 2) cout << query(1, 0, n - 1, a - 1, b - 1) << endl;
        else update(1, 0, n - 1, a - 1, b);
    }

    return;
}

signed main() {
    fastio
    int t = 1;
    // cin >> t
    while (t--) solve();
}