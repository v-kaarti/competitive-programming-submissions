#include <bits/stdc++.h>
using namespace std;

constexpr auto sum_f = [](int x, int y) { return x + y; };
constexpr auto min_f = [](int x, int y) { return min(x, y); };
constexpr auto max_f = [](int x, int y) { return max(x, y); };
constexpr auto gcd_f = [](int x, int y) { return gcd(x, y); };

template <auto f>
inline constexpr bool idempotent = false;

template <>
inline constexpr bool idempotent<min_f> = true;

template <>
inline constexpr bool idempotent<max_f> = true;

template <>
inline constexpr bool idempotent<gcd_f> = true;

template <auto f>
struct SparseTable {
    int N;
    int K;
    vector<vector<int>> st{};
    vector<int> lg{0};

    SparseTable() = delete;

    SparseTable(const vector<int>& array) { build(array); }

    void build(const vector<int>& array) {
        N = (int) array.size();
        K = N ? (32 - __builtin_clz(N)) - 1 : 0;
        st.assign(K + 1, vector<int>(N));
        lg.assign(N + 1, 0);

        if (N == 0) return;

        copy(array.begin(), array.end(), st[0].begin());

        for (int i = 2; i <= N; ++i) lg[i] = lg[i / 2] + 1;

        for (int i = 1; i <= K; ++i) {
            for (int j = 0; j + (1 << i) <= N; ++j) {
                st[i][j] = f(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
            }
        }
    }

    int query(int L, int R) const {
        bool first = true;
        int res = 0;

        for (int i = K; i >= 0; --i) {
            if ((1 << i) <= R - L + 1) {
                if (first) {
                    res = st[i][L];
                    first = false;
                } else res = f(res, st[i][L]);
                L += 1 << i;
            }
        }

        return res;
    }

    int query_fast(int L, int R) const requires(idempotent<f>) {
        int i = lg[R - L + 1];
        return f(st[i][L], st[i][R - (1 << i) + 1]);
    }
};

using SumSparseTable = SparseTable<sum_f>;
using MinSparseTable = SparseTable<min_f>;
using MaxSparseTable = SparseTable<max_f>;
using GcdSparseTable = SparseTable<gcd_f>;