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
    int n, d; cin >> n >> d;
    cout << 1 << " ";
    if (d == 3 || d == 6 || d == 9 || n >= 3) cout << 3 << " ";
    if (d == 5) cout << 5 << " ";
    if (d == 7 || n >= 3) cout << 7 << " ";
    if (d == 9 || d == 3 && n >= 3 || d == 6 && n >= 3 || n >= 6) cout << 9; 
    cout << endl;
}

signed main() {
    fastio
    int t = 1;
    cin >> t;
    while (t--) solve();
}