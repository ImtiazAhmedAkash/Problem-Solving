/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Tenzing and Books

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF (1 << 30)
#define mod 998244353
#define N 300005
#define deb(x) cerr << #x << " = " << x << nl

/*
 * Take the three stack of books as inputs one by one and read the books serially.
 * 
 * Things to keep in mind:
 * For a bitwise OR operation, if a bit becomes 1, it can never be 0.
 * So, if a book has difficulty rating y, and (x | y) != x, Tenzing will never read the book.
 * Because it will change a 0 bit of x to 1.
 * 
 * For every stack, take the inputs in a vector.
 * Then, if for any element the condition is not satisfied, stop reading from that stack and move to the next.
 * Otherwise, update the sum (sum |= y).
 * 
 * Finally, if the sum is equal to x, the answer is "Yes", otherwise, "No".
 */

void solve() {
    int n, x;
    cin >> n >> x;
    int sum = 0;
    string ans = "No";
    for (int i = 0; i < 3; i++) {
        vector<int> a(n);
        for (auto &i : a) cin >> i;

        for (auto i : a) {
            if ((i | x) != x) break;
            sum |= i;
        }
    }
    if (sum == x) ans = "Yes";
    cout << ans << nl;
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