#include "bits/stdc++.h"
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

/* 
find my code templates at https://github.com/galencolin/cp-templates
also maybe subscribe please thanks 
*/

#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL);}
#define f first
#define s second
#define getunique(v) {sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end());}
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define NP(a) next_permutation(all(a))

typedef long double ld;
typedef unsigned long long ull;

using ll = int;
// using ll = int;
// #pragma warning("int")
//
using vl = vector<ll>;
using vvl = vector<vl>;
using pl = pair<ll, ll>;
using pd = pair<ld, ld>;

#define F(i, n) for (ll i = 0; i < n; i++)

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
// #include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds; 

template <typename num_t>
using ordered_set = tree<num_t, null_type, less<num_t>, rb_tree_tag, tree_order_statistics_node_update>;

const string PAIR_LEFT = "(";
const string PAIR_RIGHT = ")";
const string IT_LEFT = "[";
const string IT_RIGHT = "]";
const string PAIR_SEP = ", ";
const string IT_SEP = ", ";

// const string PAIR_LEFT = "(";
// const string PAIR_RIGHT = ")";
// const string IT_LEFT = "[";
// const string IT_RIGHT = "]";
// const string PAIR_SEP = " ";
// const string IT_SEP = " ";

// const string PAIR_LEFT = "{";
// const string PAIR_RIGHT = "}";
// const string IT_LEFT = "{";
// const string IT_RIGHT = "}";
// const string PAIR_SEP = ", ";
// const string IT_SEP = ", ";

// benq - print any container + pair
template<typename T, typename = void> struct is_iterable : false_type {};
template<typename T> struct is_iterable<T, void_t<decltype(begin(declval<T>())),decltype(end(declval<T>()))>> : true_type {};
template<typename T> typename enable_if<is_iterable<T>::value&&!is_same<T, string>::value,ostream&>::type operator<<(ostream &cout, T const &v);
template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p) { return cout << PAIR_LEFT << p.f << PAIR_SEP << p.s << PAIR_RIGHT; }
template<typename T> typename enable_if<is_iterable<T>::value&&!is_same<T, string>::value,ostream&>::type operator<<(ostream &cout, T const &v) {
    cout << IT_LEFT; 
    for (auto it = v.begin(); it != v.end();) {
        cout << *it;
        if (++it != v.end()) cout << IT_SEP;
    }
    return cout << IT_RIGHT;
}
template<typename A, typename B> istream& operator>>(istream& cin, pair<A, B> &p) {
    cin >> p.first;
    return cin >> p.second;
}

template<typename T> void debug(string s, T x) {cerr << "\033[1;34m" << s << "\033[0;32m = \033[35m" << x << "\033[0m\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++; else
        if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << "\033[1;34m" << s.substr(0, i) << "\033[0;32m = \033[35m" << x << "\033[31m | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}
template<typename T> void debug_nameless(T x) {cerr << "\033[35m" << x << "\033[0m\n";}
template<typename T, typename... Args> void debug_nameless(T x, Args... args) {cerr << "\033[35m" << x << "\033[31m | "; debug_nameless(args...);}

#ifdef galen_colin_local
#define pr(...) debug(#__VA_ARGS__, __VA_ARGS__)
#define prs(...) debug_nameless(__VA_ARGS__)
const bool local_ = true;
#else
#define pr(...) 135
#define prs(...) 135
const bool local_ = false;
#endif

mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
// mt19937_64 rng(61378913);
/* usage - just do rng() */

void usaco(string filename) {
// #pragma message("be careful, freopen may be wrong")
    freopen((filename + ".in").c_str(), "r", stdin);
    freopen((filename + ".out").c_str(), "w", stdout);
}

// #include <atcoder/all>
// using namespace atcoder;

// const ld pi = 3.14159265358979323846;
// const ll mod = 1000000007;
const ll mod = 998244353;
// ll mod;

namespace number_theory {
	ll gcd(ll x, ll y) {
	  if (x == 0) return y;
	  if (y == 0) return x;
	  return gcd(y, x % y);
	}
	bool isprime(ll n) { 
	  if (n <= 1) return false; 
	  if (n <= 3) return true; 
	  
	  if (n % 2 == 0 || n % 3 == 0) return false; 
	  
	  for (ll i = 5; i * i <= n; i += 6) 
		if (n % i == 0 || n % (i+2) == 0) 
		  return false; 
	  
	  return true; 
	} 
	 
	bool prime[15000105]; 
	void sieve(int n) { 
	  for (ll i = 0; i <= n; i++) prime[i] = 1;
	  for (ll p = 2; p * p <= n; p++) { 
		if (prime[p] == true) { 
		  for (ll i = p * p; i <= n; i += p) 
			prime[i] = false; 
		} 
	  } 
	  prime[1] = prime[0] = 0;
	} 
	 
	vector<ll> primelist;
	bool __primes_generated__ = 0;
	 
	void genprimes(int n) {
	  __primes_generated__ = 1;
	  sieve(n + 1);
	  for (ll i = 2; i <= n; i++) if (prime[i]) primelist.push_back(i);
	}
	 
	vector<ll> factors(ll n) {
	  if (!__primes_generated__) {
		cerr << "Call genprimes you dope" << endl;
		exit(1);
	  }
	  vector<ll> facs;
	 
	  for (ll i = 0; primelist[i] * primelist[i] <= n && i < primelist.size(); i++) {
		if (n % primelist[i] == 0) {
		  while (n % primelist[i] == 0) {
			n /= primelist[i];
			facs.push_back(primelist[i]);
		  }
		}
	  }
	  if (n > 1) {
		facs.push_back(n);
	  }
	  sort(facs.begin(), facs.end());
	  return facs;
	}
	
	vector<ll> getdivs(ll n) {
    vector<ll> divs;
    for (ll i = 1; i * i <= n; i++) {
      if (n % i == 0) {
        divs.push_back(i);
        divs.push_back(n / i);
      }
    }

    getunique(divs);
    return divs;
  }
}
using namespace number_theory;
namespace modop {
    template<typename T>
	void add(T &a, ll b) {
        a += b;
        if (a >= mod) a -= mod;
    }
    template<typename T>
    void sub(T &a, ll b) {
        a -= b;
        if (a < 0) a += mod;
    }
	ll mpow(ll base, ll exp) {
	  ll res = 1;
	  while (exp) {
		if (exp % 2 == 1){
			res = (res * base) % mod;
		}
		exp >>= 1;
		base = (base * base) % mod;
	  }
	  return res;
	}
	ll minv(ll base) {
	  return mpow(base, mod - 2);
	}
    inline ll mul(ll x) {
        return x;
    }
    template<typename... Args>
    inline ll mul(ll x, Args... rest) {
        return x * mul(rest...) % mod;
    }
	
	const ll FACTORIAL_SIZE = 3.01e6;
	ll fact[FACTORIAL_SIZE], ifact[FACTORIAL_SIZE];
	bool __factorials_generated__ = 0;
	void gen_factorial(ll n) {
		__factorials_generated__ = 1;
		fact[0] = fact[1] = ifact[0] = ifact[1] = 1;
		
		for (ll i = 2; i <= n; i++) {
			fact[i] = (i * fact[i - 1]) % mod;
		}
		ifact[n] = minv(fact[n]);
		for (ll i = n - 1; i >= 2; i--) {
			ifact[i] = ((i + 1) * ifact[i + 1]) % mod;
		}
	}
	ll nck(ll n, ll k) {
		if (!__factorials_generated__) {
			cerr << "Call gen_factorial you dope" << endl;
			exit(1);
		}
		if (k < 0 || n < k) return 0;
		ll den = (ifact[k] * ifact[n - k]) % mod;
		return (den * fact[n]) % mod;
	}
}
using namespace modop;

/* uses modified segtree and min_t */
/* adapt later for generic rmq */
template <typename num_t> 
struct segtree {
  int n, depth;
  vector<num_t> tree, lazy;

  void init(int s, vl& arr) {
    n = s;
    tree = vector<num_t>(4 * s, 0);
    lazy = vector<num_t>(4 * s, 0);
    init(0, 0, n - 1, arr);
  }

  num_t init(int i, int l, int r, vl& arr) {
    if (l == r) return tree[i] = num_t(arr[l], l);

    int mid = (l + r) / 2;
    num_t a = init(2 * i + 1, l, mid, arr),
          b = init(2 * i + 2, mid + 1, r, arr);
    return tree[i] = a.op(b);
  }

  void update(int l, int r, num_t v) {
    update(0, 0, n - 1, l, r, v);
  }

  num_t update(int i, int tl, int tr, int ql, int qr, num_t v) {
    if (tl > tr || tr < ql || qr < tl) return tree[i];
    if (tl == tr) return tree[i] = v;

    int mid = (tl + tr) / 2;
    num_t a = update(2 * i + 1, tl, mid, ql, qr, v),
          b = update(2 * i + 2, mid + 1, tr, ql, qr, v);
        //   pr(i, tl, tr, a.val, a.ind, b.val, b.ind, a.op(b).val, a.op(b).ind);
    return tree[i] = a.op(b);
  }

  num_t query(int l, int r) {
    return query(0, 0, n-1, l, r);
  }

  num_t query(int i, int tl, int tr, int ql, int qr) {    
    if (ql <= tl && tr <= qr) return tree[i];
    if (tl > tr || tr < ql || qr < tl) return num_t::null_v;

    int mid = (tl + tr) / 2;
    num_t a = query(2 * i + 1, tl, mid, ql, qr),
          b = query(2 * i + 2, mid + 1, tr, ql, qr);
    return a.op(b);
  }
};

struct min_t {
  long long val;
  int ind;
  static const long long null_v = 1e9;

  min_t(): val(0) {}
  min_t(long long v): val(v) {}
  min_t(long long v, int i): val(v), ind(i) {};

  min_t op(min_t& other) {
    if (other.val == val) 
      return (ind > other.ind) ? other : *this;
    return (val > other.val) ? other : *this;
  }
  
  min_t lazy_op(min_t v, int size) {
    return min_t(val + v.val, ind);
  }
};

/* uses modified segtree and min_t */
/* adapt later for generic rmq */
struct segt {
  int n, depth;
  vector<vector<pl>> tree;

  void init(int s) {
    n = s;
    tree = vector<vector<pl>>(4 * s);
  }

  void add(vector<pl> &v, pl p) {
    // pr(v, p);
    if (!v.size() || v.back().f > p.f) v.push_back(p);
  }

  void update(int l, int r, pl v) {
    update(0, 0, n - 1, l, r, v);
  }

  void update(int i, int tl, int tr, int ql, int qr, pl v) {
    if (tl > tr || tr < ql || qr < tl) return;
    add(tree[i], v);
    if (tl == tr) return;

    int mid = (tl + tr) / 2;
    update(2 * i + 1, tl, mid, ql, qr, v),
    update(2 * i + 2, mid + 1, tr, ql, qr, v);
  }

  pl get(vector<pl> &v, ll p) {
    // pr(v, p);
    ll l = 0, r = v.size();
    while (l < r) {
        ll m = (l + r) / 2;
        if (v[m].s <= p) l = m + 1;
        else r = m;
    }
    if (l == 0) return {1 << 30, 1};
    return v[l - 1];
  }

  pl query(int l, int r, ll p) {
    return query(0, 0, n-1, l, r, p);
  }

  pl query(int i, int tl, int tr, int ql, int qr, ll p) {
    if (ql <= tl && tr <= qr) {
        // pr(i, tl, tr, tree[i], p);
        return get(tree[i], p);
    }
    if (tl > tr || tr < ql || qr < tl) return {1 << 30, -1};

    int mid = (tl + tr) / 2;
    pl a = query(2 * i + 1, tl, mid, ql, qr, p),
       b = query(2 * i + 2, mid + 1, tr, ql, qr, p);
    return min(a, b);
  }
};



ll n, m, q, k, l, r, x, y, z;
vl a, b, c;
string s, t;

namespace sslow {
    pair<ll, vl> best;
    void rec(vl v, vl vis, vl ops) {
        ll c = 0;
        for (ll i = 0; i < n; i++) {
            c += !vis[i];
            if (!vis[i] && v[i] >= 0) {
                vl rv = vis;
                for (ll j = i - v[i]; j <= i + v[i]; j++) {
                    if (0 <= j && j < n) {
                        rv[j] = 1;
                    }
                }
                vl ro = ops;
                ro.push_back(i);
                rec(v, rv, ro);
            }
        }

        if (c == 0) {
            if (ll(ops.size()) < best.f || best.f == -1) {
                best = {ops.size(), ops};
            }
        }
    }

    pair<ll, vl> solve(vl a) {
        best = {-1, {}};
        rec(a, vl(n, 0), {});
        return best;
    }
}


namespace smart {
    pair<ll, vl> solve(vl a) {
        vl dp(n, 1e9);
        vl par(n, -1);
        vl b(n, 1e9);
        segtree<min_t> st;
        st.init(n, b);
        segt sg;
        sg.init(n);
        for (ll i = 0; i < n; i++) {
            if (i - a[i] <= 0) {
                dp[i] = 1;
            } else {
                pl p = {1 << 30, -1};
                if (i - 1 >= 0) {
                    auto r = st.query(max(ll(0), i - a[i] - 1), i - 1);
                    pl q = {r.val, r.ind};
                    // pr(i, q);
                    p = min(p, q);
                }
                if (i - a[i] - 1 >= 0 && a[i] > 0) {
                    // pr(i, a[i] + i - 1);
                    pl q = sg.query(i, min(n - 1, a[i] + i - 1), i - a[i] - 1);
                    // pr(i, q);
                    p = min(p, q);
                }
                // for (ll j = 0; j < i; j++) {
                //     if (i <= j + a[j] && j + a[j] <= a[i] + i - 1 && j <= i - a[i] - 1) {
                //         p = min(p, {dp[j], j});
                //     }
                // }
                dp[i] = min(dp[i], p.f + 1);
                par[i] = p.s;
            }
            if (i + a[i] <= n - 1 && dp[i] < 1e8) {
                // pr(i, i + a[i], dp[i]);
                ll t = st.query(i + a[i], i + a[i]).val;
                if (dp[i] < t) {
                    st.update(i + a[i], i + a[i], {dp[i], i});
                }
                sg.update(i + a[i], i + a[i], {dp[i], i});
            }
        }
        // pr(dp, par);
        pl ans = {1 << 30, -1};
        for (ll i = 0; i < n; i++) {
            if (i + a[i] >= n - 1) ans = min(ans, {dp[i], i});
        }
        if (ans.f > 1e8) {
            return {-1, {}};
        } else {
            vl ops;
            ll t = ans.s;
            while (t != -1) {
                ops.push_back(t);
                t = par[t];
            }
            sort(all(ops), [&](ll i, ll j) {
                return a[i] < a[j];
            });
            return {ans.f, ops};
        }
    }
}

namespace opt {
    void precomp() {
        
    }
    void stress() {
        for (ll it = 0; it < 1e12; it++) {
            n = 1 + rng() % 10;
            vl a(n);
            for (ll &x: a) x = ll(rng() % (n + 1)) - 1;

            auto ans = smart::solve(a), jur = sslow::solve(a);
            if (ans.f != jur.f) {
                pr(n, a, ans, jur);
                assert(ans.f == jur.f);
            }

            if (it % 1000 == 0) pr(it);
        }
    }
}
using namespace opt;



const bool run = local_ ? 0 : 1;
const bool TC = 1;
void solve(int tc = 0) {
    cin >> n;
    vl a(n);
    for (ll &x: a) cin >> x, --x;
    
    pair<ll, vl> ans = smart::solve(a);
    if (ans.f == -1) cout << -1 << '\n';
    else {
        cout << ans.f << '\n';
        for (ll x: ans.s) cout << x + 1 << " ";
        cout << '\n';
    }

    if (local_) {
        pair<ll, vl> ans = sslow::solve(a);
        pr(ans);
    }
}

int main() {
    #ifdef galen_colin_local
        auto begin = std::chrono::high_resolution_clock::now();
    #endif
    
    send help

    #ifndef galen_colin_local
        // usaco("cbs");
    #endif
    
    // usaco("cowland");
    
    // freopen("tc.txt", "r", stdin);
    // freopen("tc.txt", "w", stdout);
    // freopen("tc2.cpp", "w", stdout);
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    cout << setprecision(15) << fixed;
    cerr << setprecision(4) << fixed;

    

    precomp();

    if (!run) {
        stress();
        return 0;
    }

    int tc = 1;
    // if (local_)
    // if (run)
    if (TC) cin >> tc;
    for (int t = 0; t < tc; t++) {
        pr(t); prs(string(50, '-'));
        solve(t);
        prs(string(50, '-') + "\n");
    }
    
    #ifdef galen_colin_local
        auto end = std::chrono::high_resolution_clock::now();
        cerr << setprecision(4) << fixed;
        cerr << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
    #endif
}