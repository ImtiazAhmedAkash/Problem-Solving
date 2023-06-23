/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Same Parity Summands

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF (1 << 30)
#define mod 998244353
#define N 300005
#define deb(x) cerr << #x << " = " << x << nl

/*
 * If n is odd or n is less than 2 * k, 
 * take 1 (k - 1) times in a container and the last element will be n - (k - 1).
 * 
 * If n is even and n >= 2 * k, 
 * take 2 (k - 1) times in a container and the last element will be n - 2 * (k - 1).
 * 
 * Then check if all the elements in the container is greater than 0 and have the same parity.
 * If there is any element that is 0 or less than 0 or have a different parity, print "NO".
 * 
 * Otherwise, print "YES" and then print all the elements of the container.
 */

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> ans;

    if ((n & 1) || (n < 2 * k)) {
        for (int i = 1; i < k; i++) ans.push_back(1);
        ans.push_back(n - (k - 1));
    } 
    else {
        for (int i = 1; i < k; i++) ans.push_back(2);
        ans.push_back(n - 2 * (k - 1));
    }

    int parity = ans.front() & 1;
    for (auto i : ans) {
        if (i <= 0 || (i & 1) != parity) {
            cout << "NO" << nl;
            return;
        }
    }

    cout << "YES" << nl;
    for (auto i : ans) cout << i << " ";
    cout << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}