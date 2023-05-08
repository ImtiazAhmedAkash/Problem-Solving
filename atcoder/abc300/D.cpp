/*  In the Name of ALLAH, the most gracious, the most merciful  */

// AABCC

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF (1 << 30)
#define mod 998244353
#define N 300005
#define deb(x) cerr << #x << " = " << x << nl

/*
 * An important observation: 
 * Suppose, a = 2, b = 3. Now, if a^2 * b * c^2 = 10^12, then c = 288675.
 * So, First of all, use a sieve to find out all the prime number upto 3x10^5.
 * 
 * Then, Starting 'a' = 2, fixed a bigger prime 'b' and find out how many 'c' satisfies the condition.
 * To do this, for every 'a' and 'b', calculate 'c'. c = sqrt(N / (a * a * b));
 * 
 * Here, the loop of i is for 'a'
 * the while loop is for 'b'.
 * The count of 'c' can be calculated using upper_bound as the vector is sorted.
 * 
 * Take the sum of count as long as (a^2 * b * c^2) is satisfied.
 * The total sum is the answer.
 */

vector<ll> v;
int arr[N];

void sieve() {
    for (int i = 2; i < N; i++) {
        if (arr[i] == 0) {
            v.push_back(i);
            for (int j = 2 * i; j < N; j += i) arr[j] = 1;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin >> n;
    sieve();

    ll ans = 0;

    for (int i = 0; v[i] * v[i] * v[i + 1] * v[i + 2] * v[i + 2] <= n; i++) {
        ll val = v[i] * v[i];
        int j = i + 1;

        while (1) {
            ll x = sqrt(n / val / v[j]);

            if (x <= v[j]) break;

            ll k = upper_bound(v.begin(), v.end(), x) - v.begin();
            ans += (k - j - 1);
            j++;
        }
    }

    cout << ans << nl;

    return 0;
}