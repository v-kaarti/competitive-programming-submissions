#include <bits/stdc++.h>
using namespace std;

struct DSU {
    int N;
    int components;
    vector<int> parent;
    vector<int> sz;
    DSU() = delete;
    DSU(int n) { init(n); }
    void init(int n) {
        N = n;
        components = n;
        parent.resize(N);
        sz.assign(N, 1);
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int v) {
        if (v == parent[v]) return v;
        return parent[v] = find(parent[v]);
    }
    bool same(int a, int b) {
        return find(a) == find(b);
    }
    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false;
        if (sz[a] < sz[b]) swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
        --components;
        return true;
    }
    int size(int v) {
        return sz[find(v)];
    }
    int count() const {
        return components;
    }
};