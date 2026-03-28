#include <bits/stdc++.h>
using namespace std;

//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//template <class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);

#define int long long
#define endl "\n"
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) (int)(x).size()
#define mp(x, y) make_pair((x), (y))
#define pb push_back
#define INF (1LL << 59)

vector<long long> primes;

vector<long long> trial_division4(long long n) {
    vector<long long> factorization;
    for (long long d : primes) {
        if (d * d > n)
            break;
        if (n % d == 0) {
            factorization.push_back(d);
            while ((n % d == 0)) n /= d;
        }
    }
    if (n > 1)
        factorization.push_back(n);
    return factorization;
}

void printv(vector<int> v) {
    for (auto& e : v) cout << e << " ";
    cout << endl;
}


void solve(){
    int n; cin >> n;
    int temp;
    vector<int> v(n); for (auto& e : v) cin >> e;
    for (int i = 0; i < n; ++i) cin >> temp;

    int best = 2;

    set<int> seen_normal;
    set<int> seen_plus1;
    for (int i = 0; i < n; ++i) {
        vector<int> facs = trial_division4(v[i]);
        vector<int> facs_plus_1 = trial_division4(v[i] + 1);
        for (auto e : facs) {
            if (seen_normal.contains(e)) best = min(best, 0LL);
            if (seen_plus1.contains(e)) best = min(best, 1LL);
        }
        for (auto e : facs_plus_1) {
            if (seen_normal.contains(e)) best = min(best, 1LL);
        }
        for (auto& e : facs) seen_normal.insert(e);
        for (auto& e : facs_plus_1) seen_plus1.insert(e);
    }

    cout << best << endl;
}

signed main() {
    fastio
    int N = 2 * 1e5;
    vector<bool> is_prime(N + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= N; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= N; j += i)
                is_prime[j] = false;
        }
    }
    for (int i = 2; i <= N; ++i) if (is_prime[i]) primes.push_back(i);
    int t = 1;
    cin >> t;
    while (t--) solve();
}