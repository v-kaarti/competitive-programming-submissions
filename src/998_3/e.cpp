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

class DSU {
public:
    vector<int> parent;
    vector<int> size;

    DSU(int n) {
        parent = vector<int>(n);
        size = vector<int>(n, 1);
        for (int i = 0; i < n; i += 1) parent[i] = i;
    }
    int find(int x) {
        if (x == parent[x]) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b){
        a = find(a); 
        b = find(b);
        
        if (a == b) return;

        if (size[a] < size[b]) swap(a, b);
        parent[b] = a;

        size[a] += size[b];
    }
};

void solve(){
    int n, m1, m2, plus, minus;
    cin >> n >> m1 >> m2;
    plus = minus = 0;
    vector<pair<int, int>> ef(m1), eg(m2);
    for (auto& [u, v] : ef) {
        cin >> u >> v;
        u -= 1, v -= 1;
    }
    for (auto& [u, v] : eg) {
        cin >> u >> v;
        u -= 1, v -= 1;
    }
    DSU f(n), g(n);
    for (auto& [u, v] : eg) g.unite(u, v);
    for (auto& [u, v] : ef) {
        if (g.find(u) == g.find(v)) f.unite(u, v);
        else minus += 1;
    }

    unordered_map<int, unordered_set<int>> subs;
    for (int i = 0; i < n; ++i) {
        subs[g.find(i)].insert(f.find(i));
    }
    for (auto& [c, sub_set] : subs) {
        plus += sub_set.size() - 1;
    }

    cout << plus + minus << endl;
}

signed main() {
    fastio
    int t = 1;
    cin >> t;
    while (t--) solve();
}