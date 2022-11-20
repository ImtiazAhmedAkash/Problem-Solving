/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Misjudge the Time

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cout << #x << " = " << x << nl

/*
 * Here, a = h / 10; b = h % 10; c = m / 10; d = m % 10;
 * Then swap b with c.
 * Now, h1 = a * 10 + b (b = value after swapping)
 * and m1 = c * 10 + d (c = value after swapping)
 * if h1 : m1 represents a valid time in 24-hour clock,
 * print h1 and m1, respectively, otherwise, find the next such time.
 *
 * To find the next confusing time, increment m by 1.
 * If m reaches 60, we will assign m = 0, and increase h by 1.
 * If h reaches 24, we will assign h = 0;
 *
 * Its because when m reaches 60, it restarts from 0.
 * and when h reaches 24 in a 24-hour clock, it restarts from 0.
 */

void solve()
{
    int h, m;
    cin >> h >> m;

    while (1)
    {
        int a = h / 10;
        int b = h % 10;
        int c = m / 10;
        int d = m % 10;

        swap(b, c);

        int h1 = a * 10 + b;
        int m1 = c * 10 + d;

        if (h1 < 24 && m1 < 60)
            break;
        
        m++;
        if (m == 60)
        {
            m = 0;
            h++;
            
            if (h == 24)
                h = 0;
        }
    }

    cout << h << " " << m << nl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}