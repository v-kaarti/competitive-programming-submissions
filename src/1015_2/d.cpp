#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
#define int long long
#define endl "\n";
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) (int)(x).size()
#define mp(x, y) make_pair((x), (y))
#define pb push_back
#define INF (int) 1e9

void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    
    // m doesnt work -> one survivor
    int val = n / (m + 1), pad = -1;

    // also, k can be big
    val = min(val, n - m * k);
    
    if (k > val) pad = k - val;

    vector<int> seg(val), out, padseg;
    if (pad != -1) padseg = vector<int>(pad, INF);
    iota(seg.begin(), seg.end(), 0);

    for (int i = 0; i <= m; ++i) {
        out.insert(out.end(), seg.begin(), seg.end());
        if (pad != -1 && i != m) out.insert(out.end(), padseg.begin(), padseg.end());
    }

    if ((m + 1) * (int) seg.size() + m * (int) padseg.size() < n) {
        while (out.size() < n) out.push_back(INF);
    }  

    for (auto& e : out) cout << e << " ";
    cout << endl;
}

signed main() {
    fastio
    int t = 1;
    cin >> t;
    while (t--) solve();
}