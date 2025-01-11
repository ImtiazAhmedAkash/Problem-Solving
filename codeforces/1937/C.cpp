/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Bitwise Operation Wizard

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 2e5 + 5;

char ask(int a, int b, int c, int d) {
    cout << "? " << a << " " << b << " " << c << " " << d << endl;
    char ch;
    cin >> ch;
    return ch;
}

void print(int a, int b) {
    cout << "! " << a << " " << b << endl;
}

void solve() {
    int n;
    cin >> n;
    
    int ans1 = 0;
    for (int i = 1; i < n; i++) {
        char ch = ask(ans1, ans1, i, i);
        if (ch == '<') {
            ans1 = i;
        }
    }
    
    vector<int> A;
    int mx = 0;
    for (int i = 0; i < n; i++) {
        char ch = ask(mx, ans1, i, ans1);
        if (ch == '=') {
            A.push_back(i);
        } else if (ch == '<') {
            A.clear();
            A.push_back(i);
            mx = i;
        }
    }
    
    int ans2 = A.front();
    for (int i = 1; i < A.size(); i++) {
        char ch = ask(ans2, ans2, A[i], A[i]);
        if (ch == '>') {
            ans2 = A[i];
        }
    }
    
    print(ans1, ans2);
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