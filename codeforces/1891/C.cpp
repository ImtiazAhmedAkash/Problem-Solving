/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Smilo and Monsters

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 2e5 + 5;

void solve() {
    int n;
    cin >> n;
    vector<ll> A(n);
    for (auto &x : A) cin >> x;
    sort(A.begin(), A.end());
    
    ll ans = 0, combo = 0;
    int i = 0, j = n - 1;
    while (i <= j) {
        if (i == j) {
            if (combo == 0 && A[j] == 1)
                ans++;
            else {
                ll need = max(0LL, (A[j] - combo) / 2);
                A[j] = (A[j] + combo); 
                combo += need;
                A[j] -= 2 * combo;
                ans += combo + A[j] + 1;
            }
            i++;
        } else if (combo + A[i] < A[j]) {
            combo += A[i++];
        } else if (combo + A[i] >= A[j]) {
            A[i] -= A[j] - combo;
            if (A[i] == 0) i++;
            ans += 1 + A[j--];
            combo = 0;
        }
    }
    cout << ans << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        solve();
    }

    return 0;
}