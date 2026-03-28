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
    int n, k, even = 0, odd = 0, temp;
    cin >> n >> k;
    while (n--) {
        cin >> temp;
        if (temp % 2 == 0) even++;
        else odd++;
    }
    while (k--) {
        if (odd > 1) odd -= 2, even++;
        else if (even > 1) even--;
    }
    cout << odd + even << endl;
}

signed main() {
    fastio
    int t = 1;
    cin >> t;
    while (t--) solve();
}