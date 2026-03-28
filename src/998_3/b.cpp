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

bool eq_dist(vector<int>& cards, int dist) {
    if (cards.size() <= 1) return true;
    for (int i = 1; i < (int) cards.size(); i += 1) {
        int curr_dist = cards[i] - cards[i - 1];
        if (curr_dist != dist) return false;
    }
    return true;
}

void solve(){
    int n, m; cin >> n >> m;
    vector<pair<vector<int>, int>> cows(n, make_pair(vector<int>(m), 0));

    for (int i = 0; i < n; ++i) {
        for (auto& e : cows[i].first) {
            cin >> e;
        }
        cows[i].second = i + 1;
        sort(cows[i].first.begin(), cows[i].first.end());
    }

    sort(cows.begin(), cows.end());

    vector<int> order;

    for (auto& [cards, index] : cows) {
        if (eq_dist(cards, n)) {
            order.push_back(index);
        } else {
            cout << -1 << endl;
            return;
        }
    }

    for (auto& idx : order) cout << idx << " ";
    cout << endl;
    return;
}

signed main() {
    fastio
    int t = 1;
    cin >> t;
    while (t--) solve();
}