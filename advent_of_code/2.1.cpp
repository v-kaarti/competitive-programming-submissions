#include <bits/stdc++.h>
#define int long long
using namespace std;



signed main() {
    string report;
    int temp, ans = 0;
    while (getline(cin, report)) {
        vector<int> nums;
        stringstream ss(report);
            while (ss >> temp) nums.push_back(temp);
            if (nums.size() == 1) {
                ans++;
                continue;
            }
    }
}