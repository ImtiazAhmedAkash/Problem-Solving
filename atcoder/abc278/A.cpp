/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Shift

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cout << #x << " = " << x << nl

/*
 * Take the inputs in a queue. 
 * Pop the front element and push 0 for k times.
 * Print the queue elements.
 */

void solve()
{
    queue<int> q;

    int n, k, val;
    cin >> n >> k;

    while (n--)
    {
        cin >> val;
        q.push(val);
    }

    while (k--)
    {
        q.pop();
        q.push(0);
    }

    while (not q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}