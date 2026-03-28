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

int k;

struct query{
    int l,r, id;
    bool operator < (query b){
        if(l/k == b.l/k) return r/k < b.r/k;
        return l/k < b.l/k;
    }
};

void add(int x, int& xor){

}

void del(int x, int& xor){

}

signed main(){
    int n, q;
    cin >> n >> q;
    

    k = sqrt(n);

    int arr[n + 1];
    for(int i = 1; i <= n; i++)
        cin >> arr[i];

    vector<query> queries;
    vector<int> res(q);

    for(int i = 0;i < q;i++){
        int l,r;
        cin >> l >> r;
        queries.push_back({l,r,i});
    }

    sort(queries.begin(),queries.end());

    int l = 1, r = 0, ans = 0, curr = 0;

    for(auto [ql, qr, id] : queries){
        while(l < ql) del(arr[l++], curr); //[l+1,r]
        while(r < qr) add(arr[++r], curr); //[l,r+1]
        while(l > ql)  add(arr[--l]); //[l-1,r]
        while(r > qr)  del(arr[r--]); //[l-1,r]
        res[id] = ans;
    }
}