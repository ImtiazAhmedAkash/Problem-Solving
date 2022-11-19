/*  In the Name of ALLAH, the most gracious, the most merciful  */

// FF

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cout << #x << " = " << x << nl

/*
 * We'll handle the follow and unfollow operation using map.
 * Here, the key of the map will be a pair <follower, idol>,
 * and the value will be bool.
 * If a follows b, then m[{a, b}] will be true.
 * If a unfollows b, then m[{a, b}] will be false.
 *
 * If m[{a, b}] == true and m[{b, a}] == true, both a and b follow each other.
 * In this case, the output will be "YES", otherwise "NO";
 */

void solve()
{
    int n, q;
    cin >> n >> q;

    map<pair<int, int>, bool> m;
    int t, a, b;

    while (q--)
    {
        cin >> t >> a >> b;

        if (t == 1)
            m[{a, b}] = true;
        else if (t == 2)
            m[{a, b}] = false;
        else
        {
            if (m[{a, b}] && m[{b, a}])
                cout << "Yes" << nl;
            else
                cout << "No" << nl;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}