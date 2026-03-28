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
    int n, mx = 0; cin >> n;
    vector<int> l(n), r(n);
    unordered_map<int, vector<int>> start, end;
    for (int i = 0; i < n; ++i) {
        cin >> l[i] >> r[i];
        start[l[i]].push_back(i);
        end[r[i] + 1].push_back(i);
        mx = max(mx, r[i]);
    }
    vector<int> v(mx + 1);
    string b(n, '0');
    for (int i = 0; i < n; i += 1) {
        v[l[i]] += 1;
        v[r[i] + 1] -= 1;
    }
    unordered_set<int> curr;
    int count = 0;
    for (int i = 0; i < v.size(); ++i) {
        count += v[i];
        for (auto& e : start[i]) curr.insert(e);
        for (auto& e : end[i]) curr.erase(e);
        if (curr.size() == 1) b[*curr.begin()] = '1';
    }
    cout << b << endl;
}

signed main() {
    fastio
    int t = 1;
    cin >> t;
    while (t--) solve();
}