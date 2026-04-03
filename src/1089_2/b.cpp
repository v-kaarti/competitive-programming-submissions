#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

// #define V_KAARTI_LOCAL

using namespace std;

using namespace __gnu_pbds;
template <class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());

#define int long long
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sor(x) sort(all(x));
#define ins insert
#define ft front()
#define bk back()
#define f first
#define s second
#define sz(x) (int)(x).size()
#define mp(x, y) make_pair((x), (y))
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define INF (1e18)

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define F0R(i, a) FOR(i, 0, a)
#define ROF(i, a, b) for (int i = (b) - 1; i >= (a); --i)
#define R0F(i, a) ROF(i, 0, a)
#define rep(a) F0R(_, a)
#define each(a, x) for (auto &a : x)

using db = double;
template <class T> using V = vector<T>;
using pi = pair<int, int>;
using pd = pair<db, db>;
using vi = V<int>;
using vb = V<bool>;
using vd = V<db>;
using vs = V<string>;
using vpi = V<pi>;
using vpd = V<pd>;

template<typename T, typename = void>
struct is_iterable : false_type {};

template<typename T>
struct is_iterable<T, void_t<decltype(begin(declval<T>())),decltype(end(declval<T>()))>> : true_type {};

template<typename T>
typename enable_if<is_iterable<T>::value&&!is_same<T, string>::value,ostream&>::type
operator<<(ostream &cout, T const &v);

template<typename A, typename B>
ostream& operator<<(ostream &cout, pair<A, B> const &p) {
    return cout << "(" << p.f << ", " << p.s << ")";
}

template<typename T>
typename enable_if<is_iterable<T>::value&&!is_same<T, string>::value,ostream&>::type
operator<<(ostream &cout, T const &v) {
    cout << "[";
    for (auto it = v.begin(); it != v.end();) {
        cout << *it;
        if (++it != v.end()) cout << ", ";
    }
    return cout << "]";
}

template<typename A, typename B>
istream& operator>>(istream& cin, pair<A, B> &p) {
    cin >> p.first;
    return cin >> p.second;
}

template<typename T>
void debug_named(string s, T x) {
    cerr << "\033[1;34m" << s
         << "\033[0;32m = \033[35m" << x
         << "\033[0m\n";
}

template<typename T, typename... Args>
void debug_named(string s, T x, Args... args) {
    for (int i = 0, b = 0; i < (int)s.size(); i++) {
        if (s[i] == '(' || s[i] == '{') b++;
        else if (s[i] == ')' || s[i] == '}') b--;
        else if (s[i] == ',' && b == 0) {
            cerr << "\033[1;34m" << s.substr(0, i)
                 << "\033[0;32m = \033[35m" << x
                 << "\033[31m | ";
            debug_named(s.substr(s.find_first_not_of(' ', i + 1)), args...);
            break;
        }
    }
}

template<typename T>
void debug_nameless(T x) {
    cerr << "\033[35m" << x << "\033[0m\n";
}

template<typename T, typename... Args>
void debug_nameless(T x, Args... args) {
    cerr << "\033[35m" << x << "\033[31m | ";
    debug_nameless(args...);
}

#ifdef V_KAARTI_LOCAL
    #define ppr(...) debug_named(#__VA_ARGS__, __VA_ARGS__)
    #define pr(...)  debug_nameless(__VA_ARGS__)
#else
    #define ppr(...) ((void)0)
    #define pr(...)  ((void)0)
#endif

const int NT_MAX = 1;
vector<int> primes;
vector<bool> is_comp(NT_MAX + 1, false);
bool primes_ready = false;

bool is_prime_single(long long n) {
    if (n < 2) return false;
    if (n % 2 == 0) return n == 2;
    for (long long i = 3; i * i <= n; i += 2)
        if (n % i == 0) return false;
    return true;
}

void gen_primes(int n = NT_MAX) {
    is_comp.assign(n + 1, false);
    primes.clear();
    for (int i = 2; i <= n; i++) {
        if (!is_comp[i]) {
            primes.push_back(i);
            if ((long long)i * i <= n) {
                for (int j = i * i; j <= n; j += i) is_comp[j] = true;
            }
        }
    }
    primes_ready = true;
}

vector<long long> factors(long long n) {
    if (!primes_ready) gen_primes();
    vector<long long> f;
    for (long long p : primes) {
        if (p * p > n) break;
        while (n % p == 0) {
            f.push_back(p);
            n /= p;
        }
    }
    if (n > 1) f.push_back(n);
    return f;
}

vector<long long> get_divs(long long n) {
    vector<long long> d;
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            d.push_back(i);
            if (i * i != n) d.push_back(n / i);
        }
    }
    sort(d.begin(), d.end());
    return d;
}

void precompute() {}


void solve(int tc){
    int n; cin >> n;
    vi nums(n);
    vi mod(n);
    each(e, nums) cin >> e;
    F0R(i, n) {
        mod[i] = ((nums[i] - 1) - i + n) % n;
        if (mod[i] == 0) mod[i] = n;
    }

    mod.insert(mod.end(), mod.begin(), mod.end());

    multiset<int> ms;
    map<int, vi> expires;
    int ans = 1;
    F0R(i, 2 * n) {
        each(e, expires[i]) ms.erase(ms.find(e));
        expires.erase(i);

        int e = mod[i];
        ms.insert(e);
        expires[i + e].push_back(e);

        ans = max(ans, (int) ms.size());
    }
    cout << ans << endl;
}

signed main() {
    fastio
    precompute(); 

    int t = 1;
    cin >> t;
    for (int tc = 0; tc < t; tc++) {
        ppr(tc); pr(string(50, '-'));
        solve(tc);
        pr(string(50, '-') + "\n");
    }
}