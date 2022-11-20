/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Playing Cards Validation

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cout << #x << " = " << x << nl

/*
 * Store the string in a vector and use a map to count the words.
 * If a word is present more than once (i.e. nax > 1), return "NO".
 *
 * Take two strings.
 * The first one contains the eligible characters for str.front().
 * The second one contains the eligible character for str.back().
 *
 * Then for each string in the vector, we will search,
 * if str.front() is not found in s1, return "NO".
 * if str.back() is not found in s2, return "NO".
 * These two cases, violates the conditions.
 * 
 * Otherwise, return "YES".
 */

string solve()
{
    int n;
    cin >> n;

    vector<string> v(n);
    map<string, int> m;
    int nax = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        m[v[i]]++;

        if (m[v[i]] > nax)
            nax = m[v[i]];
    }

    if (nax > 1)
        return "No";

    string s1 = "HDCS", s2 = "A23456789TJQK";
    for (int i = 0; i < n; i++)
    {
        if (s1.find(v[i].front()) == string::npos)
            return "No";

        else if (s2.find(v[i].back()) == string::npos)
            return "No";
    }
    return "Yes";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cout << solve() << nl;

    return 0;
}