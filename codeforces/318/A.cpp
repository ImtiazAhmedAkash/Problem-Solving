/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Even Odds

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
 * In the rearrangement, all the odd numbers from 1 to n will be placed first,
 * and then all the even numbers from 1 to n will be placed.
 * So, for n values, there will be n / 2 odd numbers if n is even.
 * If n is odd, then there will be (n / 2) + 1 odd numbers.
 * Both cases can be handled using (n + 1) / 2.
 *
 * k is the position whose value needs to be found.
 *
 * If k is less than (n + 1) / 2, we will get an odd number in k-th position.
 * The general formula for k-th odd number is 2 * k - 1.
 *
 * Else we will get an even number in (k - total number of odd numbers)-th position.
 * The general formula for k-th even number is 2 * k.
 */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n, k;
    cin >> n >> k;

    ll ans;

    if ((n + 1) / 2 >= k)
        ans = 2 * k - 1;
    else {
        k -= (n + 1) / 2;
        ans = 2 * k;
    }

    cout << ans << '\n';

    return 0;
}