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
    int n, a, b;
    string s;
    cin >> n >> a >> b >> s;

    if (b >= 0) {
        cout << a * n + b * n << endl;
        return;
    }

    if (n == 1) {
        cout << a * n + b << endl;
        return;
    }

    int curr = 1, ans1 = 0, ans2 = 0;

    for (int i = 1; i < n; ++i) {

        if (s[i] != s[i - 1] && s[i] == '0') ans1++, curr = 1;
        else if (s[i] != s[i - 1] && s[i] == '1') ans2++, curr = 1;
        else curr += 1;

        if (i == n - 1) {
            if (s[i] == '1') ans1++;
            else ans2++;
        }
    }

    cout << n * a + b * min({ans1 + 1, ans2 + 1, ans1 + ans2}) << endl;

}

signed main() {
    fastio
    int t = 1;
    cin >> t;
    while (t--) solve();
}