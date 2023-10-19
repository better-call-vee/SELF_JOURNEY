/*
☞ Better.Call.Vee ☜
created: 19th October, 2023 21:04:02 GMT+6
https://codeforces.com/contest/1624/problem/B
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) {
        int a, b, c;
        cin >> a >> b >> c;

        if((2 * b - a > 0 && (2 * b - a) % c == 0) or
           (2 * b - c > 0 && (2 * b - c) % a == 0) or ((a + c) % (2 * b) == 0))
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}

/*
(a + c) % (2 * b) checks if is (a + c) multiple of 2 × b and

the rest checks if it's possible to transform the sequence into an arithmetic
progression by multiplying a or c to make b the midpoint.

to be an arithmetic progression, it has to be b - a = c - b;
=> 2b = a + c;
thus, we check if 2b - a or, 2b - c is a multiple of c or, a.
and > 0 is because we need positive integers to check.
*/