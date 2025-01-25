/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Game With Triangles

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
    int n, m;
    cin >> n >> m;
    vector<ll> A(n);
    for (auto &x : A) cin >> x;
    vector<ll> B(m);
    for (auto &x : B) cin >> x;
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    multiset<ll, greater<>> msA;
    int l = 0, r = n - 1;
    while (l < r) {
        msA.insert(A[r] - A[l]);
        l++, r--;
    }
    
    multiset<ll, greater<>> msB;
    l = 0, r = m - 1;
    while (l < r) {
        msB.insert(B[r] - B[l]);
        l++, r--;
    }
    
    vector<ll> ans;
    multiset<ll> usedA, usedB;
    ll cur = 0;
    while (n && m && n + m >= 3) {
        ll mx = 0;
        if (m && n >= 2 && !msA.empty()) {
            mx = max(mx, *msA.begin());
        }
        if (n && m >= 2 && !msB.empty()) {
            mx = max(mx, *msB.begin());
        }
        
        cur += mx;
        ans.push_back(cur);
        
        if (!msA.empty() && *msA.begin() == mx) {
            usedA.insert(*msA.begin());
            msA.erase(msA.begin());
            n -= 2;
            m--;
        } 
        else {
            usedB.insert(*msB.begin());
            msB.erase(msB.begin());
            m -= 2;
            n--;
        }
        
        if (n == 0 && m && !usedA.empty()) {
            ll change = *usedA.begin();
            usedA.erase(usedA.begin());
            msA.insert(change);
            cur -= change;
            n += 2;
            m++;
            
            cur += *msB.begin();
            usedB.insert(*msB.begin());
            msB.erase(msB.begin());
            m -= 2;
            n--;
        }
        else if (m == 0 && n && !usedB.empty()) {
            ll change = *usedB.begin();
            usedB.erase(usedB.begin());
            msB.insert(change);
            cur -= change;
            m += 2;
            n++;
            
            cur += *msA.begin();
            usedA.insert(*msA.begin());
            msA.erase(msA.begin());
            n -= 2;
            m--;
        }
    }
    
    cout << ans.size() << nl;
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << nl;
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