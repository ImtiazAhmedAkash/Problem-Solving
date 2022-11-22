/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Sereja and Dima

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

/*
 * Insert all the input elements in a deque.
 * Take the greater element between d.front() and d.back() in a variable.
 * Pop the greater element from the deque.
 * As sereja starts the game, if i is even, add the val to sereja.
 * Else add the val to dima.
 * Repeat this n times.
 * In the end, print the sum of their card values.
 */

void solve()
{
    int n;
    cin >> n;

    deque<int> d;
    int val, sereja = 0, dima = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        d.push_back(val);
    }

    for (int i = 0; i < n; i++)
    {
        if (d.front() > d.back())
        {
            val = d.front();
            d.pop_front();
        }
        else
        {
            val = d.back();
            d.pop_back();
        }

        (i & 1) ? dima += val : sereja += val;
    }

    cout << sereja << " " << dima << nl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}