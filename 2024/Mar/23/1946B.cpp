#include <bits/stdc++.h>
using namespace std;
#define int long long
const int P = 1e9 + 7;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int S = 0, sum = 0;
    int cur = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
        cur += a[i];
        cur = max(cur, 0LL);
        S = max(S, cur);
    }
    sum = (sum % P + P) % P;
    S = S % P;
    int t = 1;
    for (int i = 0; i < k; i++) {
        t = t * 2 % P;
    }
    int ans = (sum + S * t - S + P) % P;
    cout << ans << '\n';
}


signed main() {
    //cout << fixed << setprecision(20);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1, G = 1;
    //cin >> G;
    cin >> T;
    while (T--)
        solve();
    return 0;
}