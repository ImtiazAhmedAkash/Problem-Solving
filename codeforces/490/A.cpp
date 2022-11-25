/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Team Olympiad

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

/*
 * Store the indexes of the input value in their corresponding vectors.
 * For example, store 1's index in v1, 2's in v2, 3's in v3.
 * The minimum of the three vectors will be teams that can be formed.
 * 
 * Print the number of teams.
 * Iterate a loop from 0 to team - 1, 
 * and print the values of the same index of all three vectors.
 */

void solve()
{
    int n;
    cin >> n;
    
    vector<int> v1, v2, v3;
    int val;
    
    for (int i = 1; i <= n; i++)
    {
        cin >> val;
        if (val == 1)
            v1.push_back(i);
        else if (val == 2)
            v2.push_back(i);
        else
            v3.push_back(i);
    }

    int team = min(v1.size(), min(v2.size(), v3.size()));
    cout << team << nl;

    for (int i = 0; i < team; i++)
    {
        cout << v1[i] << " " << v2[i] << " " << v3[i] << nl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}