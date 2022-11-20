/*  In the name of ALLAH, the most gracious, the most merciful  */

// Repetition

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cout << #x << " = " << x << nl

/*
 * If two consecutive elements are the same, increment the count.
 * If they are different, a repitition is finished.
 * Store the longest repitition in 'best' by comparing best and count.
 * Reset the count to 1.
 * Count is started or reset to 1, because 
 * for n repitition, there is n + 1 elements.
 * The value of best at the end of the program is the answer.
 */

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string str;
    cin >> str;

    ll count = 1, best = 0;
    for (ll i = 0; i < (ll)str.size(); i++)
    {
        if (str[i] == str[i + 1])
            count++;
        else
        {
            best = max(count, best);
            count = 1;
        }
    }
    cout << best << nl;

    return 0;
}