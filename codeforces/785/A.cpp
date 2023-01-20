/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Anton and Polyhedrons

#include <bits/stdc++.h>
using namespace std;

/*
 * Create a map and set the polyhedron names as key and triangular faces as values.
 * Then, take a string n-times, and sum up the values for respective keys.
 * Total value of sum is the answer.
 */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    map<string, int> m;

    m["Cube"] = 6;
    m["Dodecahedron"] = 12;
    m["Icosahedron"] = 20;
    m["Octahedron"] = 8;
    m["Tetrahedron"] = 4;

    int n;
    cin >> n;
    int sum = 0;
    while (n--) {
        string str;
        cin >> str;
        sum += m[str];
    }
    cout << sum << '\n';

    return 0;
}