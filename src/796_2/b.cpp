#include <bits/stdc++.h>
#include <climits>
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

int ops(int mn) {
    int out = 0;
    while (mn % 2 == 0) {
        mn /= 2;
        out++;
    }
    return out;
}
void solve(){
    int n, out = 0, can = 0, mn = LLONG_MAX; cin >> n;
    vector<int> v(n); for (auto& e : v) cin >> e;
    vector<int> odds;

    for (auto& e : v) {
        if (e % 2 == 0) odds.push_back(e);
        else can = 1;
    }

    if (odds.size() == 0) {
        cout << out << endl;
        return;
    }

    out = odds.size() - 1;

    if (can == 1) {
        cout << out + 1 << endl;
        return;
    }

    int mops = LLONG_MAX;
    for (auto& odd : odds) {
        mops = min(mops, ops(odd));
    }

    cout << out + mops << endl;
}

signed main() {
    fastio
    int t = 1;
    cin >> t;
    while (t--) solve();
}