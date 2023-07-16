/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Mismatched Parentheses

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF (1 << 30)
#define mod 998244353
#define N 300005
#define deb(x) cerr << #x << " = " << x << nl

void solve() {
    int n;
    string s;
    cin >> n >> s;
    s += '0';
    string ans = "";
    stack<char> st;
    for (int i = 0; i <= n; i++) {
        if (i == n) {
            if (!st.empty()) {
                string tmp = "";
                while(!st.empty()) {
                    tmp += st.top();
                    st.pop();
                }
                for (int i = tmp.size() - 1; i >= 0; i--) {
                    ans += tmp[i];
                }
            }
        }
        else if (!st.empty() && s[i] == ')') {
            while(st.top() != '(') st.pop();
            st.pop();
        }
        else if (!st.empty() || s[i] == '(') {
            st.push(s[i]);
        }
        else if (st.empty() && s[i] != '(') {
            ans += s[i];
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