/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Slay the Dragon

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF (1LL << 62)
#define mod 998244353
#define N 300005
#define deb(x) cerr << #x << " = " << x << nl

void solve() {
    int n;
    cin >> n;
    vector<ll> hero(n);
    ll total = 0;
    for (auto &x : hero) {
        cin >> x;
        total += x;
    }
    sort(hero.begin(), hero.end());
    int dragon;
    cin >> dragon;
    while (dragon--) {
        ll dragon_defense, dragon_attack;
        cin >> dragon_defense >> dragon_attack;
        ll ans = INF, tmp = INF;
        auto it = lower_bound(hero.begin(), hero.end(), dragon_defense);
        if (it == hero.end()) it--;
        ll hero_attack = *it;
        ans = max(0LL, dragon_defense - hero_attack);
        ll hero_defense = total - hero_attack;
        ans += max(0LL, dragon_attack - hero_defense);
        if (it != hero.begin()) {
            it--;
            hero_attack = *it;
            tmp = max(0LL, dragon_defense - hero_attack);
            hero_defense = total - hero_attack;
            tmp += max(0LL, dragon_attack - hero_defense);
        }
        cout << min(tmp, ans) << nl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
    
    return 0;
}