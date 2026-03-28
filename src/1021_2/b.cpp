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
    int n, k;
    cin >> n >> k;
    vector<int> bars(n);
    for (auto& e : bars) cin >> e; 

    sort(bars.begin(), bars.end());
    
    int middle = n - k;

    // median minimizes abs loss

    cout << 1 + bars[(middle / 2) + k] - bars[(middle + 1) / 2 - 1] << endl;

}

signed main() {
    fastio
    int t = 1;
    cin >> t;
    while (t--) solve();
}