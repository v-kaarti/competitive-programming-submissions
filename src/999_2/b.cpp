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
    map<int, int> mp;
    for (auto& e : nums) {
        cin >> e;
        mp[e] += 1;
    }

    vector<int> pairs;
    for (auto& [k, v] : mp) {
        if (v == 4) {
            cout << k << " " << k << " " << k << " " << k << endl;
            return;
        }
        if (v >= 2) pairs.push_back(k);
    }

    if (pairs.size() >= 2) {
        int a = pairs[0], b = pairs[1];
        cout << a << " " << a << " " << b << " " << b << endl;
        return;
    }

    if (pairs.size() <= 0) {
        cout << -1 << endl;
        return;
    }

    int leg = pairs[0];
    mp[leg] -= 2;
    if (mp[leg] <= 0) mp.erase(leg);

    vector<int> cands;
    for (auto& [k, _] : mp) cands.push_back(k);

    int a, b, c, d;
    a = b = leg;

    int req = a + b;

    for (int i = 1; i < cands.size(); i++) {
        if (cands[i] - cands[i - 1] < req) {
            c = cands[i], d = cands[i - 1];
            cout << a << " " << b << " " << c << " " << d << endl;
            return;
        }
    }
    
    cout << -1 << endl;
    
}

signed main() {
    fastio
    int t = 1;
    cin >> t;
    while (t--) solve();
}