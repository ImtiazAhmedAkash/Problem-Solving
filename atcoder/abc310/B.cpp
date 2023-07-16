/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Strictly Superior

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF (1 << 30)
#define mod 998244353
#define N 300005
#define deb(x) cerr << #x << " = " << x << nl

void solve() {
    int product, function_limit;
    cin >> product >> function_limit;
    vector<int> price(product);
    vector<vector<int>> function(product);
    
    for (int i = 0; i < product; i++) {
        int f;
        cin >> price[i] >> f;
        while(f--) {
            int x;
            cin >> x;
            function[i].push_back(x);
        }
    }
    
    string ans = "No";
    for (int i = 0; i < product; i++) {
        for (int j = 0; j < product; j++) {
            bool one = false, two = false, three = false;
            if (i == j) continue;
            if (price[i] >= price[j]) one = true;
            if (includes(function[j].begin(), function[j].end(), function[i].begin(), function[i].end())) two = true;
            if (price[i] > price[j] || !(includes(function[i].begin(), function[i].end(), function[j].begin(), function[j].end()))) three = true;
            if (one && two && three) {
                ans = "Yes";
                break;
            }
        }
    }
    cout << ans << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
    
    return 0;
}