#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <climits>
#include <cmath>
#include <complex>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>
using namespace std;

using ll = long long;
using db = long double;  // or double, if TL is tight
using str = string;      // yay python!

// pairs
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using pd = pair<db, db>;
#define mp make_pair
#define f first
#define s second

#define tcT template <class T
#define tcTU tcT, class U
// ^ lol this makes everything look weird but I'll try it
tcT > using V = vector<T>;
tcT, size_t SZ > using AR = array<T, SZ>;
using vi = V<int>;
using vb = V<bool>;
using vl = V<ll>;
using vd = V<db>;
using vs = V<str>;
using vpi = V<pi>;
using vpl = V<pl>;
using vpd = V<pd>;

// vectors
#define sz(x) int(size(x))
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define sor(x) sort(all(x))
#define rsz resize
#define ins insert
#define pb push_back
#define eb emplace_back
#define ft front()
#define bk back()

#define lb lower_bound
#define ub upper_bound
tcT > int lwb(const V<T> &a, const T &b) { return int(lb(all(a), b) - bg(a)); }
tcT > int upb(const V<T> &a, const T &b) { return int(ub(all(a), b) - bg(a)); }

// loops
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define F0R(i, a) FOR(i, 0, a)
#define ROF(i, a, b) for (int i = (b) - 1; i >= (a); --i)
#define R0F(i, a) ROF(i, 0, a)
#define rep(a) F0R(_, a)
#define each(a, x) for (auto &a : x)

const int MOD = 998244353;  // 1e9+7;
const int MX = (int)2e5 + 5;
const ll BIG = 1e18;  // not too close to LLONG_MAX
const db PI = acos((db)-1);
const int dx[4]{1, 0, -1, 0}, dy[4]{0, 1, 0, -1};  // for every grid problem!!
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
template <class T> using pqg = priority_queue<T, vector<T>, greater<T>>;

// bitwise ops
// also see https://gcc.gnu.org/onlinedocs/gcc/Other-Builtins.html
constexpr int pct(int x) { return __builtin_popcount(x); }  // # of bits set
constexpr int bits(int x) {  // assert(x >= 0); // make C++11 compatible until
	                         // USACO updates ...
	return x == 0 ? 0 : 31 - __builtin_clz(x);
}  // floor(log2(x))
constexpr int p2(int x) { return 1 << x; }
constexpr int msk2(int x) { return p2(x) - 1; }

ll cdiv(ll a, ll b) {
	return a / b + ((a ^ b) > 0 && a % b);
}  // divide a by b rounded up
ll fdiv(ll a, ll b) {
	return a / b - ((a ^ b) < 0 && a % b);
}  // divide a by b rounded down

tcT > bool ckmin(T &a, const T &b) {
	return b < a ? a = b, 1 : 0;
}  // set a = min(a,b)
tcT > bool ckmax(T &a, const T &b) {
	return a < b ? a = b, 1 : 0;
}  // set a = max(a,b)

tcTU > T fstTrue(T lo, T hi, U f) {
	++hi;
	assert(lo <= hi);  // assuming f is increasing
	while (lo < hi) {  // find first index such that f is true
		T mid = lo + (hi - lo) / 2;
		f(mid) ? hi = mid : lo = mid + 1;
	}
	return lo;
}
tcTU > T lstTrue(T lo, T hi, U f) {
	--lo;
	assert(lo <= hi);  // assuming f is decreasing
	while (lo < hi) {  // find first index such that f is true
		T mid = lo + (hi - lo + 1) / 2;
		f(mid) ? lo = mid : hi = mid - 1;
	}
	return lo;
}
tcT > void remDup(vector<T> &v) {  // sort and remove duplicates
	sort(all(v));
	v.erase(unique(all(v)), end(v));
}
tcTU > void safeErase(T &t, const U &u) {
	auto it = t.find(u);
	assert(it != end(t));
	t.erase(it);
}

inline namespace IO {
#define SFINAE(x, ...)                                                         \
	template <class, class = void> struct x : std::false_type {};              \
	template <class T> struct x<T, std::void_t<__VA_ARGS__>> : std::true_type {}

SFINAE(DefaultI, decltype(std::cin >> std::declval<T &>()));
SFINAE(DefaultO, decltype(std::cout << std::declval<T &>()));
SFINAE(IsTuple, typename std::tuple_size<T>::type);
SFINAE(Iterable, decltype(std::begin(std::declval<T>())));

template <auto &is> struct Reader {
	template <class T> void Impl(T &t) {
		if constexpr (DefaultI<T>::value) is >> t;
		else if constexpr (Iterable<T>::value) {
			for (auto &x : t) Impl(x);
		} else if constexpr (IsTuple<T>::value) {
			std::apply([this](auto &...args) { (Impl(args), ...); }, t);
		} else static_assert(IsTuple<T>::value, "No matching type for read");
	}
	template <class... Ts> void read(Ts &...ts) { ((Impl(ts)), ...); }
};

template <class... Ts> void re(Ts &...ts) { Reader<cin>{}.read(ts...); }
#define def(t, args...)                                                        \
	t args;                                                                    \
	re(args);

template <auto &os, bool debug, bool print_nd> struct Writer {
	string comma() const { return debug ? "," : ""; }
	template <class T> constexpr char Space(const T &) const {
		return print_nd && (Iterable<T>::value or IsTuple<T>::value) ? '\n'
		                                                             : ' ';
	}
	template <class T> void Impl(T const &t) const {
		if constexpr (DefaultO<T>::value) os << t;
		else if constexpr (Iterable<T>::value) {
			if (debug) os << '{';
			int i = 0;
			for (auto &&x : t)
				((i++) ? (os << comma() << Space(x), Impl(x)) : Impl(x));
			if (debug) os << '}';
		} else if constexpr (IsTuple<T>::value) {
			if (debug) os << '(';
			std::apply(
			    [this](auto const &...args) {
				    int i = 0;
				    (((i++) ? (os << comma() << " ", Impl(args)) : Impl(args)),
				     ...);
			    },
			    t);
			if (debug) os << ')';
		} else static_assert(IsTuple<T>::value, "No matching type for print");
	}
	template <class T> void ImplWrapper(T const &t) const {
		if (debug) os << "\033[0;31m";
		Impl(t);
		if (debug) os << "\033[0m";
	}
	template <class... Ts> void print(Ts const &...ts) const {
		((Impl(ts)), ...);
	}
	template <class F, class... Ts>
	void print_with_sep(const std::string &sep, F const &f,
	                    Ts const &...ts) const {
		ImplWrapper(f), ((os << sep, ImplWrapper(ts)), ...), os << '\n';
	}
	void print_with_sep(const std::string &) const { os << '\n'; }
};

template <class... Ts> void pr(Ts const &...ts) {
	Writer<cout, false, true>{}.print(ts...);
}
template <class... Ts> void ps(Ts const &...ts) {
	Writer<cout, false, true>{}.print_with_sep(" ", ts...);
}
}  // namespace IO

inline namespace Debug {
template <typename... Args> void err(Args... args) {
	Writer<cerr, true, false>{}.print_with_sep(" | ", args...);
}
template <typename... Args> void errn(Args... args) {
	Writer<cerr, true, true>{}.print_with_sep(" | ", args...);
}

void err_prefix(str func, int line, string args) {
	cerr << "\033[0;31m\u001b[1mDEBUG\033[0m"
	     << " | "
	     << "\u001b[34m" << func << "\033[0m"
	     << ":"
	     << "\u001b[34m" << line << "\033[0m"
	     << " - "
	     << "[" << args << "] = ";
}

#ifdef LOCAL
#define dbg(args...) err_prefix(__FUNCTION__, __LINE__, #args), err(args)
#define dbgn(args...) err_prefix(__FUNCTION__, __LINE__, #args), errn(args)
#else
#define dbg(...)
#define dbgn(args...)
#endif

const auto beg_time = std::chrono::high_resolution_clock::now();
// https://stackoverflow.com/questions/47980498/accurate-c-c-clock-on-a-multi-core-processor-with-auto-overclock?noredirect=1&lq=1
double time_elapsed() {
	return chrono::duration<double>(std::chrono::high_resolution_clock::now() -
	                                beg_time)
	    .count();
}
}  // namespace Debug

inline namespace FileIO {
void setIn(str s) { freopen(s.c_str(), "r", stdin); }
void setOut(str s) { freopen(s.c_str(), "w", stdout); }
void setIO(str s = "") {
	cin.tie(0)->sync_with_stdio(0);  // unsync C / C++ I/O streams
	cout << fixed << setprecision(12);
	// cin.exceptions(cin.failbit);
	// throws exception when do smth illegal
	// ex. try to read letter into int
	if (sz(s)) setIn(s + ".in"), setOut(s + ".out");  // for old USACO
}
}  // namespace FileIO

str rev(str s) {
	reverse(all(s));
	return s;
}

int N, Q;

template <int SIGMA> struct PalTree {
	struct Node {
		AR<int, SIGMA> to;
		int link;
		int len;
		pi pos;
		int humor;
		int diff;
		int slink;
		vi children;
		vi pref_at_node;
		vi right_ocs;
		Node(int link, int len, int l, int r, int humor, int diff, int slink)
		    : link(link), len(len), pos({l, r}), humor(humor), diff(diff),
		      slink(slink) {
			fill(all(to), -1);
		}
	};
	V<Node> nodes;
	PalTree(str S) {
		nodes.pb(Node(-1, -1, 0, -1, 0, -1, -1));
		nodes.pb(Node(0, 0, 0, 0, 0, -1, -1));
		int p = 0;
		vi path;
		F0R(i, sz(S)) {
			// dbg("AT", i);
			path.pb(p);
			char c = S.at(i);
			int x = c - 'a';
			while (p) {
				int j = i - 1 - nodes.at(p).len;
				// [i - nodes.at(p).len, i)
				bool ok = j >= 0 && S.at(j) == S.at(i);
				if (ok) break;
				p = nodes.at(p).link;
			}
			if (nodes.at(p).to.at(x) != -1) {
				p = nodes.at(p).to.at(x);
				continue;
			}
			int to = sz(nodes);
			nodes.at(p).to.at(x) = to;
			int l = i - 1 - nodes.at(p).len, r = i + 1;
			int link = 1;
			int humor = nodes.at(p).humor;
			if (p > 0) {
				while (true) {
					p = nodes.at(p).link;
					int j = i - 1 - nodes.at(p).len;
					assert(j >= 0);
					if (S.at(j) == S.at(i)) break;
				}
				link = nodes.at(p).to.at(x);
			}
			nodes.at(link).children.pb(to);
			int len = r - l;
			int diff = len - nodes.at(link).len;
			int slink =
			    diff == nodes.at(link).diff ? nodes.at(link).slink : link;
			nodes.pb(Node(link, len, l, r, max(humor, nodes.at(link).len), diff,
			              slink));
			p = to;
		}
		path.pb(p);
		path.erase(begin(path));
		F0R(i, sz(S)) nodes.at(path.at(i)).pref_at_node.pb(i);
		F0R(i, sz(S)) process_right_ocs(i, path.at(i));
	}

	void process_right_ocs(int r, int node) {
		while (true) {
			assert(node > 1);
			// dbg("HELLO", r, node, nodes.at(node).len);
			nodes.at(node).right_ocs.pb(r);
			while (true) {
				int diff = nodes.at(node).diff;
				int slink = nodes.at(node).slink;
				if (slink <= 1) return;
				assert((nodes.at(node).len - nodes.at(slink).len) % diff == 0);
				bool should_break =
				    nodes.at(slink).len * 3 < nodes.at(slink).len + diff;
				node = slink;
				if (should_break) break;
			}
		}
	}

	vpi stk;
	V<vpi> queries_with_r;
	vi ret;

	void dfs(int paltree_node) {
		stk.pb({nodes.at(paltree_node).len, paltree_node});
		for (int r : nodes.at(paltree_node).pref_at_node) {
			for (auto [len, i] : queries_with_r.at(r)) {
				int pos = lwb(stk, mp(len + 1, 0));
				ret.at(i) = stk.at(pos - 1).s;
			}
		}
		for (int c : nodes.at(paltree_node).children) dfs(c);
		stk.pop_back();
	}
	vi paltree_nodes(const vpi &queries) {
		// dbg("BEFORE PALTREE NODES");
		// dbg(queries);
		queries_with_r = V<vpi>(N);
		F0R(i, sz(queries)) {
			auto [l, r] = queries.at(i);
			if (l <= r) queries_with_r.at(r).pb({r - l + 1, i});
		}
		ret = vi(sz(queries), -1);
		dfs(1);
		F0R(i, sz(queries)) {
			auto [l, r] = queries.at(i);
			if (l <= r) assert(ret.at(i) >= 0);
		}
		// dbg("AFTER PALTREE NODES");
		// each(t, ret) assert(t >= 0);
		return ret;
	}
};

V<vpi> range_upds;

template <int SIGMA>
void parallel_dfs(PalTree<SIGMA> &p, PalTree<SIGMA> &rp, int al, int ar) {
	// p.nodes.at(al).right_ocs
	// rp.nodes.at(ar).right_ocs

	// dbg("parallel dfs", al, ar, p.nodes.at(al).to);
	{
		int len = p.nodes.at(al).len;

		vi left_ocs;
		for (int x : rp.nodes.at(ar).right_ocs) left_ocs.pb(N - 1 - x);
		reverse(all(left_ocs));
		assert(is_sorted(all(left_ocs)));

		// dbg(len, al, ar, left_ocs, p.nodes.at(al).right_ocs);

		int l_idx = -1;

		for (int r : p.nodes.at(al).right_ocs) {
			bool moved = 0;
			while (l_idx + 1 < sz(left_ocs) &&
			       left_ocs.at(l_idx + 1) + len <= r)
				++l_idx, moved = true;
			if (moved && left_ocs.at(l_idx) + 2 * len <= r) {
				int l = left_ocs.at(l_idx);
				// dbg("ADD RANGE UPD", l, r, len);
				range_upds.at(r).pb({l, len});
			}
		}
	}

	F0R(i, SIGMA) if (p.nodes.at(al).to.at(i) != -1) {
		int bl = p.nodes.at(al).to.at(i);
		int br = rp.nodes.at(ar).to.at(i);
		assert(br != -1);
		parallel_dfs(p, rp, bl, br);
	}
}

/**
 * Source: http://codeforces.com/blog/entry/12143
 * Time: O(N)
 * Description: length of largest palindrome centered at each character of
 * string and between every consecutive pair Verification:
 * http://www.spoj.com/problems/MSUBSTR/
 */

vi manacher(str _S) {
	str S = "@";
	each(c, _S) S += c, S += "#";
	S.bk = '&';
	vi ans(sz(S) - 1);
	int lo = 0, hi = 0;
	FOR(i, 1, sz(S) - 1) {
		if (i != 1) ans[i] = min(hi - i, ans[hi - i + lo]);
		while (S[i - ans[i] - 1] == S[i + ans[i] + 1]) ++ans[i];
		if (i + ans[i] > hi) lo = i - ans[i], hi = i + ans[i];
	}
	ans.erase(begin(ans));
	F0R(i, sz(ans)) if (i % 2 == ans[i] % 2)++ ans[i];
	return ans;
}
/// Usage: ps(manacher("abacaba"))


#include <algorithm>
#include <cassert>
#include <functional>
#include <vector>


#ifdef _MSC_VER
#include <intrin.h>
#endif

#if __cplusplus >= 202002L
#include <bit>
#endif

namespace atcoder {

namespace internal {

#if __cplusplus >= 202002L

using std::bit_ceil;

#else

unsigned int bit_ceil(unsigned int n) {
    unsigned int x = 1;
    while (x < (unsigned int)(n)) x *= 2;
    return x;
}

#endif

int countr_zero(unsigned int n) {
#ifdef _MSC_VER
    unsigned long index;
    _BitScanForward(&index, n);
    return index;
#else
    return __builtin_ctz(n);
#endif
}

constexpr int countr_zero_constexpr(unsigned int n) {
    int x = 0;
    while (!(n & (1 << x))) x++;
    return x;
}

}  // namespace internal

}  // namespace atcoder


namespace atcoder {

#if __cplusplus >= 201703L

template <class S, auto op, auto e> struct segtree {
    static_assert(std::is_convertible_v<decltype(op), std::function<S(S, S)>>,
                  "op must work as S(S, S)");
    static_assert(std::is_convertible_v<decltype(e), std::function<S()>>,
                  "e must work as S()");

#else

template <class S, S (*op)(S, S), S (*e)()> struct segtree {

#endif

  public:
    segtree() : segtree(0) {}
    explicit segtree(int n) : segtree(std::vector<S>(n, e())) {}
    explicit segtree(const std::vector<S>& v) : _n(int(v.size())) {
        size = (int)internal::bit_ceil((unsigned int)(_n));
        log = internal::countr_zero((unsigned int)size);
        d = std::vector<S>(2 * size, e());
        for (int i = 0; i < _n; i++) d[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--) {
            update(i);
        }
    }

    void set(int p, S x) {
        assert(0 <= p && p < _n);
        p += size;
        d[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    S get(int p) const {
        assert(0 <= p && p < _n);
        return d[p + size];
    }

    S prod(int l, int r) const {
        assert(0 <= l && l <= r && r <= _n);
        S sml = e(), smr = e();
        l += size;
        r += size;

        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }
        return op(sml, smr);
    }

    S all_prod() const { return d[1]; }

    template <bool (*f)(S)> int max_right(int l) const {
        return max_right(l, [](S x) { return f(x); });
    }
    template <class F> int max_right(int l, F f) const {
        assert(0 <= l && l <= _n);
        assert(f(e()));
        if (l == _n) return _n;
        l += size;
        S sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!f(op(sm, d[l]))) {
                while (l < size) {
                    l = (2 * l);
                    if (f(op(sm, d[l]))) {
                        sm = op(sm, d[l]);
                        l++;
                    }
                }
                return l - size;
            }
            sm = op(sm, d[l]);
            l++;
        } while ((l & -l) != l);
        return _n;
    }

    template <bool (*f)(S)> int min_left(int r) const {
        return min_left(r, [](S x) { return f(x); });
    }
    template <class F> int min_left(int r, F f) const {
        assert(0 <= r && r <= _n);
        assert(f(e()));
        if (r == 0) return 0;
        r += size;
        S sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!f(op(d[r], sm))) {
                while (r < size) {
                    r = (2 * r + 1);
                    if (f(op(d[r], sm))) {
                        sm = op(d[r], sm);
                        r--;
                    }
                }
                return r + 1 - size;
            }
            sm = op(d[r], sm);
        } while ((r & -r) != r);
        return 0;
    }

  private:
    int _n, size, log;
    std::vector<S> d;

    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
};

}  // namespace atcoder

using namespace atcoder;
int op(int a, int b) { return max(a, b); }
int e() { return 0; }

vi ans;

int main() {
	// read read read
	setIO();
	re(N, Q);
	ans = vi(Q);

	def(str, S);
	// str S(N, 'n');
	vi center_lens = manacher(S);

	vpi center_pals;
	F0R(i, sz(center_lens)) {
		int l = i / 2, r = (i + 1) / 2;
		++l, --r;
		l -= (center_lens.at(i) + 1) / 2;
		r += (center_lens.at(i) + 1) / 2;
		if (i % 2 == 0) assert(l <= r);
		assert(l + r == i);
		center_pals.pb({l, r});
	}
	// dbg(center_pals);
	dbg("DONE 1");

	vpi queries, rqueries;
	rep(Q) {
		def(int, L, R);
		// int L = rng() % N + 1, R = rng() % N + 1;
		if (L > R) swap(L, R);
		--L, --R;
		queries.pb({L, R});
		rqueries.pb({N - 1 - R, N - 1 - L});
	}
	dbg("DONE 2");

	PalTree<26> p(S), rp(rev(S));
	dbg("DONE INIT PALTREE");

	{  // case 1
		// dbg("DONE INIT PALTREE");

		segtree<int, op, e> seg(0);
		{
			vi nodes_cen = p.paltree_nodes(center_pals);
			vi to_maxq;
			for (int x : nodes_cen) {
				to_maxq.pb(x == -1 ? 0 : p.nodes.at(x).humor);
			}
			seg = segtree<int, op, e>(to_maxq);
		}

		vi nodes_r = p.paltree_nodes(queries);
		vi nodes_l = rp.paltree_nodes(rqueries);

		// TODO: case 1
		F0R(i, Q) {
			int c1 = p.nodes.at(nodes_r.at(i)).humor;
			int c2 = rp.nodes.at(nodes_l.at(i)).humor;
			ckmax(ans.at(i), c1);
			ckmax(ans.at(i), c2);

			int cen_l =
			    2 * queries.at(i).f + rp.nodes.at(nodes_l.at(i)).len - 1;
			int cen_r =
			    2 * queries.at(i).s - (p.nodes.at(nodes_r.at(i)).len - 1);
			assert(cen_l <= cen_r);
			if (cen_l < cen_r) ckmax(ans.at(i), seg.prod(cen_l + 1, cen_r));
			// cen_l + 1 ... cen_r
		}
	}
	dbg("DONE PART 2");
	{  // case 2
		range_upds.rsz(N);
		parallel_dfs(p, rp, 0, 0);
		parallel_dfs(p, rp, 1, 1);
		V<vi> queries_with_r(N);
		F0R(i, Q) queries_with_r.at(queries.at(i).s).pb(i);

		vi fenw(N);
		F0R(r, N) {
			for (auto [l, v] : range_upds.at(r)) {
				for (++l; l; l -= l & -l) ckmax(fenw.at(l - 1), v);
			}
			for (int q : queries_with_r.at(r)) {  // everything >= l + 1
				int l = queries.at(q).f;
				for (++l; l <= N; l += l & -l) ckmax(ans.at(q), fenw.at(l - 1));
			}
		}
	}
	dbg("DONE PART 3");

	// TODO: case 2

	each(t, ans) ps(t);
	dbg(time_elapsed());

	// you should actually read the stuff at the bottom
}

/* stuff you should look for
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */