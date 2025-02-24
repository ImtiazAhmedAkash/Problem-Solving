/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// A - Scrambled Scrabble

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "Dbug.h"
#else
#define dbg(...)
#endif

using ll = long long;
constexpr char nl = '\n';

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 2e5 + 5;

void solve() {
    string s;
    cin >> s;
    vector<int> cnt(128, 0);
    for (auto &c : s) {
        cnt[c]++;
    }
    
    string vowel = "AEIOU";
    string consonant = "BCDFGHJKLMNPQRSTVWXZ"; // 'Y' Not included
    
    vector<char> tmp;
    vector<int> cur_cnt(128, 0);
    int NG = 0;
    
    auto find_consonant = [&]() -> bool {
        if (NG) {
            NG--;
            tmp.push_back('N');
            tmp.push_back('G');
            cur_cnt['N']--;
            cur_cnt['G']--;
            return true;
        }
        
        for (auto &c : consonant) {
            if (cur_cnt[c]) {
                cur_cnt[c]--;
                tmp.push_back(c);
                return true;
            }
        }
        
        if (cur_cnt['Y']) {
            cur_cnt['Y']--;
            tmp.push_back('Y');
            return true;
        }
        
        return false;
    };
    
    auto find_vowel = [&]() -> bool {
        for (auto &c : vowel) {
            if (cur_cnt[c]) {
                cur_cnt[c]--;
                tmp.push_back(c);
                return true;
            }
        }
        
        if (cur_cnt['Y']) {
            cur_cnt['Y']--;
            tmp.push_back('Y');
            return true;
        }
        
        return false;
    };
    
    int ans = 0;
    int t = min(cnt['N'], cnt['G']);
    for (int i = 0; i <= t; i++) {
        cur_cnt = cnt;
        NG = i;
        int cur_len = 0;
        tmp.clear();
        while (find_consonant() && find_vowel() && find_consonant()) {
            cur_len += tmp.size();
            tmp.clear();
        }
        ans = max(ans, cur_len);
    }
    
    cout << ans << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T = 1;
    for (int t = 1; t <= T; t++) {
        solve();
    }
    
    return 0;
}