#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;
  while (n--) {
    string s;
    cin >> s;
    s.pop_back();
    s.pop_back();
    s.push_back('i');
    cout << s << endl;
  }
}
