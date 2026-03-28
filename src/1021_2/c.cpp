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
    int n;
    cin >> n;
    vector<int> nums(n);
    map<int, int> mp;

    for (auto& e : nums) cin >> e, e++, mp[e]++;

    for (auto& [_, v] : mp) {
        if (v >= 4) {
            cout << "YES" << endl;
            return;
        }
    }

    // need ANY min interval that has mutable endpts

    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());

    int start = -1, prev = -1, counter = 0;
    for (auto& e : nums) {
        if (prev == -1) {
            prev = e;
            continue;
        }

        if (e == prev + 1) {
            if (start == -1) {
                start = prev;
                counter = 0;
                if (mp[prev] >= 2) counter++;
            }
            prev = e;
            if (mp[e] >= 2) counter++;
            continue;
        }

        if (start != -1 && counter >= 2) {
            cout << "YES" << endl;
            return;
        }

        prev = e;
        start = -1;
        counter = 0;
    }

    if (start != -1 && counter >= 2) {
        cout << "YES" << endl;
        return;
    }

    cout << "NO" << endl;
   
}

signed main() {
    fastio
    int t = 1;
    cin >> t;
    while (t--) solve();
}