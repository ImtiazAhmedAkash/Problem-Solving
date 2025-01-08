/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Sum Graph

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 2e5 + 5;

void ask1(int x) {
    cout << "+ " << x << endl;
    cin >> x;
}

int ask2(int x, int y) {
    cout << "? " << x + 1 << " " << y + 1 << endl;
    cin >> x;
    return x;
}

void print(vector<int>& A, vector<int>& B) {
    cout << "! ";
    for (auto &x : A) {
        cout << x << " ";
    }
    for (auto &x : B) {
        cout << x << " ";
    }
    cout << endl;
}

void solve() {
    int n;
    cin >> n;
    
    ask1(n + 1);
    ask1(n + 2);
    
    vector<int> A(n);
    A.front() = 1;
    int sum = n + 1;
    for (int i = 1; i < n; i++) {
        A[i] = sum - A[i - 1];
        sum = (sum == n + 1 ? n + 2 : n + 1);
    }
    
    int dist = 0;
    int indx = 0;
    for (int i = 1; i < n; i++) {
        int cur = ask2(0, i);
        if (dist < cur) {
            dist = cur;
            indx = i;
        }
    }
    
    vector<int> ans1(n), ans2(n);
    ans1[indx] = A.front();
    ans2[indx] = A.back();
    for (int i = 0; i < n; i++) {
        if (i == indx) continue;
        int cur = ask2(indx, i);
        ans1[i] = A[cur];
        ans2[i] = A[n - 1 - cur];
    }
    
    print(ans1, ans2);
    
    int x;
    cin >> x;
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