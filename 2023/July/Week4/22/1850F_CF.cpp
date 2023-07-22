#include "bits/stdc++.h"
using namespace std;

#define ll long long

#define          all(v)              v.begin(), v.end()
#define         rall(v)              v.rbegin(),v.rend()

#define            pb                push_back
#define          sz(a)               (int)a.size()

void solve() {
    int n; cin >> n;
    vector<ll> cnt(n + 1, 0), mx(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        if (x <= n) ++cnt[x];
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; j += i) mx[j] += cnt[i];
    }
    cout << *max_element(all(mx)) << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}