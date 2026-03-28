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

void solve_left(string s) {
    int first = s[0] - '0'; 
    int second = s[1] - '0';
    int sum = first + second;
    cout << to_string(sum) + s.substr(2) << endl;
    return;
}

void solve_right(string s, int idx) {
    int first = s[idx] - '0';
    int second = s[idx + 1] - '0';
    int sum = first + second;
    cout << s.substr(0, idx) + to_string(sum) + s.substr(idx + 2) << endl;
    return;
}

void solve(){
    string s; cin >> s;
    int n = s.size();
    int rightmost_idx = -1;
    
    for (int i = 0; i < n - 1; i++) { 
        int first = s[i] - '0', second = s[i + 1] - '0';
        int sum = first + second;
        if (sum >= 10) {
            rightmost_idx = i;
        }
    }
    
    if (rightmost_idx != -1) {
        solve_right(s, rightmost_idx);
    } else {
        solve_left(s);
    }
}

signed main() {
    fastio
    int t = 1;
    cin >> t;
    while (t--) solve();
}
