/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Minimum Difficulty

#include <bits/stdc++.h>
using namespace std;

#define deb(x) cout << #x << " = " << x << '\n'

/*
 * An important observation is, the array is increasing, i.e. a[i] < a[i + 1] for all i, from 1 to n.
 * First of all, find out the difficulty of the track without removing any hold. 
 * Then, find out the minimum difficulty if one hold is removed from the track.
 * The answer will be the maximum of these two.
 */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int maxi = 0, mini = INT_MAX;

    for (int i = 1; i < n; i++) maxi = max(maxi, a[i] - a[i - 1]);

    for (int i = 2; i < n; i++) mini = min(mini, a[i] - a[i - 2]);

    cout << max(maxi, mini) << '\n';

    return 0;
}