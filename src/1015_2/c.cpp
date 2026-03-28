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
    int n; cin >> n;
    vector<pair<int, int>> pairs(n);

    for (auto& [a, _] : pairs) cin >> a;
    for (auto& [_, b] : pairs) cin >> b;

    map<pair<int, int>, int> check;
    for (int i = 0; i < n; ++i) check[pairs[i]] = i;

    int ind = -1;

    for (int i = 0; i < n; ++i) {
        auto& [a, b] = pairs[i];
        if (a == b) {
            if (n % 2 == 0) {
                cout << -1 << endl;
                return;
            }
            else {
                if (ind != -1) {
                    cout << -1 << endl;
                    return;
                }

                ind = i;
            }
        }
        if (!check.contains({b, a})) {
            cout << -1 << endl;
            return;
        }
    }

    vector<pair<int, int>> moves;

    // place in middle if needed
    if (ind != -1 && ind != n / 2) {
        pair<int, int> dupe = pairs[ind];
        pair<int, int> place = pairs[n / 2];
        
        check[place] = ind;
        check[dupe] = n / 2;

        swap(pairs[ind], pairs[n / 2]);

        moves.emplace_back(ind, n / 2);
    }

    for (int i = 0; i < n; ++i) {
        pair<int, int> curr = pairs[i];
        auto [a, b] = curr;
        pair<int, int> complement = {b, a};

        int comp_ind = check[complement];
        int curr_ind = i;

        if (comp_ind != n - i - 1) {
            int swap_ind = n - i - 1;

            pair<int, int> swap_pair = pairs[swap_ind];

            check[swap_pair] = comp_ind;
            check[complement] = n - i - 1;

            swap(pairs[comp_ind], pairs[n - i - 1]);

            moves.emplace_back(comp_ind, n - i - 1);
        }

    }

    cout << moves.size() << endl;
    for (auto& [i, j] : moves) cout << i + 1 << " " << j + 1 << endl;
}

signed main() {
    fastio
    int t = 1;
    cin >> t;
    while (t--) solve();
}