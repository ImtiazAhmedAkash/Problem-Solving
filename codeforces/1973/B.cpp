/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Cat, Fox and the Lonely Array

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
    vector<int> A(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    
    vector pref(n + 1, vector<int>(20));
    for (int i = 1; i <= n; i++) {
        for (int bit = 0; bit < 20; bit++) {
            if (A[i] & (1 << bit)) {
                pref[i][bit] = 1;
            }
            pref[i][bit] += pref[i - 1][bit];
        }
    }
    
    auto check = [&](int mid) -> bool {
        int rangeOr = 0;
        for (int bit = 0; bit < 20; bit++) {
            if (pref[mid][bit]) {
                rangeOr |= (1 << bit);
            }
        }
        
        for (int i = mid + 1; i <= n; i++) {
            int curOr = 0;
            for (int bit = 0; bit < 20; bit++) {
                if (pref[i][bit] - pref[i - mid][bit]) {
                    curOr |= (1 << bit);
                }
            }
            if (curOr != rangeOr) return false;
        }
        
        return true;
    };
    
    int L = 1, R = n;
    while (L < R) {
        int M = L + (R - L) / 2;
        if (check(M)) {
            R = M;
        } else {
            L = M + 1;
        }
    }
    
    cout << L << nl;
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