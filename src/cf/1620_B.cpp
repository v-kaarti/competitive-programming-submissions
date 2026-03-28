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
    int w, h, k, tmp; cin >> w >> h;
    int bot_min, bot_max, top_min, top_max, left_min, left_max, right_min, right_max;
    int bot, top, left, right;
    bot_min = top_min = left_min = right_min = INT_MAX;
    bot_max = top_max = left_max = right_max = 0;

    cin >> k;
    for (int i = 0; i < k; ++i) {
        cin >> tmp; 
        bot_min = min(bot_min, tmp);
        bot_max = max(bot_max, tmp);
    }
    bot = bot_max - bot_min;

    cin >> k;
    for (int i = 0; i < k; ++i) {
        cin >> tmp; 
        top_min = min(top_min, tmp);
        top_max = max(top_max, tmp);
    }
    top = top_max - top_min;

    cin >> k;
    for (int i = 0; i < k; ++i) {
        cin >> tmp; 
        left_min = min(left_min, tmp);
        left_max = max(left_max, tmp);
    }
    left = left_max - left_min;

    cin >> k;
    for (int i = 0; i < k; ++i) {
        cin >> tmp; 
        right_min = min(right_min, tmp);
        right_max = max(right_max, tmp);
    }
    right = right_max - right_min;

    // for cf resubmission

    cout << max({top * h, bot * h, left * w, right * w}) << endl;
}

signed main() {
    fastio
    int t = 1;
    cin >> t;
    while (t--) solve();
}