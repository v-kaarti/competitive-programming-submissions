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
    int n, m, k, unknown = -1;
    cin >> n >> m >> k;
    vector<int> missing(m);
    unordered_set<int> known;
    string res;
    for (int i = 0; i < m; ++i) cin >> missing[i];
    for (int i = 0; i < k; ++i) {
        int temp; cin >> temp;
        known.insert(temp);
    }
    if (known.size() < n - 1) cout << string(m, '0');
    else if (known.size() == n) cout << string(m, '1');
    else {
        string res;
        for (int i = 1; i <= n; ++i) {
            if (!known.contains(i)) {
                unknown = i;
                break;
            }
        }
        for (int i = 0; i < m; ++i) {
            if (missing[i] != unknown) res.push_back('0');
            else res.push_back('1');
        }
        cout << res;
    }
    cout << endl;
}

signed main() {
    fastio
    int t = 1;
    cin >> t;
    while (t--) solve();
}