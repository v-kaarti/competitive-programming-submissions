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

pair<int,int> prefix(int start, int end, vector<int>& v, set<int>& vals) {
    vector<int> seg(v.begin() + start, v.begin() + end);
    int s = 0, minPref = 0, maxPref = 0, mx = 0, mn = 0;
    for (auto &x : seg) {
        s += x;
        mx = max(mx, s - minPref);
        mn = min(mn, s - maxPref);
        minPref = min(minPref, s);
        maxPref = max(maxPref, s);
    }
    int L = min(mn, 0LL), R = max(mx, 0LL);
    for (int val = L; val <= R; val++) vals.insert(val);
    return {L, R};
}

pair<int,int> suffix(int end, int start, vector<int>& v, set<int>& vals) {
    vector<int> seg;
    for (int i = end + 1; i <= start; i++) seg.push_back(v[i]);
    int s = 0, minPref = 0, maxPref = 0, mx = 0, mn = 0;
    for (auto &x : seg) {
        s += x;
        mx = max(mx, s - minPref);
        mn = min(mn, s - maxPref);
        minPref = min(minPref, s);
        maxPref = max(maxPref, s);
    }
    int L = min(mn, 0LL), R = max(mx, 0LL);
    for (int val = L; val <= R; val++) vals.insert(val);
    return {L, R};
}

void center(int special, vector<int>& v, set<int>& vals) {
    vector<int> pre(v.begin(), v.begin() + special), suf(v.begin() + special + 1, v.end());
    int mnf = 0, mxf = 0, mne = 0, mxe = 0, s = 0, mn = 0, mx = 0;

    for (int i = (int) pre.size() - 1; i >= 0; i--) {
        s += pre[i];
        mn = min(mn, s), mx = max(mx, s);
    }

    mne = mn, mxe = mx;

    s = mn = mx = 0;

    for (int i = 0; i < (int) suf.size(); ++i)  {
        s += suf[i];
        mn = min(mn, s), mx = max(mx, s);
    }

    mnf = mn, mxf = mx;

    int val = v[special];
    int L = mne + mnf + val, R = mxe + mxf + val;
    for (int s = L; s <= R; s++) vals.insert(s);
}

void solve() {
    int n; cin >> n;
    vector<int> v(n);
    int idx = -1;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (v[i] == 1 || v[i] == -1) continue;
        idx = i;
    }
    set<int> sums; 
    sums.insert(0);
    if (idx == -1) {
        prefix(0, n, v, sums);
    } else {
        prefix(0, idx, v, sums);
        suffix(idx, n - 1, v, sums);
        center(idx, v, sums);
    }
    cout << sums.size() << endl;
    for (auto &x : sums) cout << x << " ";
    cout << endl
}

signed main() {
    fastio
    int t; cin >> t;
    while(t--) solve();
    return 0;
}