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

void build(vector<int>& nums, int v, int tl, int tr) {
    if (tl == tr) {
        seg[v] = nums[tl];
        return;
    }

    int m = (tl + tr) >> 1;
    build(nums, v << 1, tl, m);
    build(nums, v << 1 | 1, m + 1, tr);
    seg[v] = seg[v << 1] + seg[v << 1 | 1];
}

int query(int v, int ql, int qr, int tl, int tr) {
    if (tl >= ql && tr <= qr) return seg[v];
    if (ql > tr || qr < tl) return 0;
    int m = (tl + tr) >> 1;
    return query(v << 1, ql, qr, tl, m) + 
           query(v << 1 | 1, ql, qr, m + 1, tr);
}

void modify(int v, int tl, int tr, int pos, int change) {
    if (pos == tl && pos == tr) {
        seg[v] = change;
        return;
    }

    if (pos > tr || pos < tl) return;

    int m = (tl + tr) >> 1;

    modify(v << 1, tl, m, pos, change);
    modify(v << 1 | 1, m + 1, tr, pos, change);

    seg[v] = seg[v << 1] + seg[v << 1 | 1];
}

void solve(){
    int n, q;
    int type, a, b;
    cin >> n >> q;
    vector<int> vals(n);
    for (auto& e : vals) cin >> e;
    seg.resize(4 * n);
    build(vals, 1, 0, n - 1);
    while (q--) {
        cin >> type >> a >> b;
        if (type == 1) {
            a--;
            modify(1, 0, n - 1, a, b);
        }

        if (type == 2) {
            a--, b--;
            cout << query(1, a, b, 0, n - 1) << endl;
        }
    }
}

signed main() {
    fastio
    int t = 1;
    // cin >> t;
    while (t--) solve();
}