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

int trav(int r, int c, int lor, int hir, int loc, int hic, int start) {

    int diam = (hir - lor + 1) / 2;
    
    if (diam < 1) {
        if (r == lor && c == loc) return start;
        if (r == hir && c == hic) return start + 1;
        if (r == hir && c == loc) return start + 2;
        if (r == loc && c == hic) return start + 3;
    }

    int dr, dc;
    int mr = (hir + lor) >> 1;
    int mc = (hic + loc) >> 1;
    dr = (r > mr) ? 1 : 0;
    dc = (c > mc) ? 1 : 0;
    
    if (dr == 0 && dc == 0) return trav(r, c, lor, mr, loc, mc, start);
    if (dr == 1 && dc == 1) return trav(r, c, mr + 1, hir, mc + 1, hic, start + diam * diam);
    if (dr == 1 && dc == 0) return trav(r, c, mr + 1, hir, loc, mc, start + 2 * diam * diam);
    if (dr == 0 && dc == 1) return trav(r, c, lor, mr, mc + 1, hic, start + 3 * diam * diam);

    return -1;
}

pair<int, int> get(int lor, int hir, int loc, int hic, int val, int start) {

    if (lor == hir) return {lor, loc};

    int diam = (hir - lor + 1) / 2;

    int dr, dc;

    int mr = (hir + lor) >> 1;
    int mc = (hic + loc) >> 1;

    if (val >= start + 3 * diam * diam) dr = 0, dc = 1;
    else if (val >= start + 2 * diam * diam) dr = 1, dc = 0;
    else if (val >= start + diam * diam) dr = 1, dc = 1;
    else dr = 0, dc = 0;
    
    if (dr == 0 && dc == 0) return get(lor, mr, loc, mc, val, start);
    if (dr == 1 && dc == 1) return get(mr + 1, hir, mc + 1, hic, val, start + diam * diam);
    if (dr == 1 && dc == 0) return get(mr + 1, hir, loc, mc, val, start + 2 * diam * diam);
    if (dr == 0 && dc == 1) return get(lor, mr, mc + 1, hic, val, start + 3 * diam * diam);

    return {-1, -1};
}


void solve(){
    int n, q;
    cin >> n >> q;
    char a, b;
    int c, d;
    while (q--) {
        cin >> a >> b;
        int m = (1 << n);
        if (a == '-') {
            cin >> c >> d;
            cout << trav(c - 1, d - 1, 0, m - 1, 0, m - 1, 1) << endl;
        }
        else {
            cin >> c;
            auto [x, y] = get(0, m - 1, 0, m - 1, c, 1);
            cout << x + 1 << " " << y + 1 << endl;
        }
    }
}

signed main() {
    fastio
    int t = 1;
    cin >> t;
    while (t--) solve();
}
