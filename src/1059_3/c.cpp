#include <bits/stdc++.h>
#include <cmath>
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

int lg2(int a) {
    int m = 1;
    int e = 0;
    while (m * 2 <= a) e++, m *= 2;
    return e;
}

void solve(){
    int a, b; cin >> a >> b;
    int a2 = a, b2 = b;;
    if (lg2(a) < lg2(b)) {
        cout << -1 << endl;
        return;
    }
    vector<int> ops{};

    int c = 0;
    while (a2 > 0) {
        if (!(a2 & 1)) ops.push_back(1 << c);
        a2 >>= 1;
        c++;
    }

    
    c = 0;
    while (b > 0) {
        if (!(b & 1)) ops.push_back(1 << c);
        b >>= 1;
        c++;
    }

    for (auto& e : ops) a ^= e;

    ops.push_back(a - b2);

    cout << ops.size() << endl;
    for (auto& e : ops) cout << e << " ";
    cout << endl;
}

signed main() {
    fastio
    int t = 1;
    cin >> t;
    while (t--) solve();
}