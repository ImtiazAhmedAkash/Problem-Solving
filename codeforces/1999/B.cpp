/*  In the Name of ALLAH, the most gracious, the most merciful  */

// B - Card Game

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
    vector<pair<int, int>> A(2), B(2);
    cin >> A[0].first >> A[1].first >> B[0].first >> B[1].first;
    A[0].second = 1;
    A[1].second = 2;
    B[0].second = 1;
    B[1].second = 2;

    sort(A.begin(), A.end());
    int ans = 0;
    do {
        sort(B.begin(), B.end());
        do {
            int win = 0, lose = 0;
            for (int i = 0; i < 2; i++) {
                if (A[i].first > B[i].first)
                    win++;
                else if (A[i].first < B[i].first)
                    lose++;
            }
            if (win > lose) {
                ans++;
            }
        } while (next_permutation(B.begin(), B.end()));
    } while (next_permutation(A.begin(), A.end()));

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