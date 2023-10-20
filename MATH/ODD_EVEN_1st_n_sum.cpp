/*
☞ Better.Call.Vee ☜
created: 20th October, 2023 19:14:32 GMT+6
https://codeforces.com/contest/486/problem/A
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    ll odd = (n + 1) / 2, even = n / 2;
    
    cout << even * (even + 1) - odd * odd;

    return 0;
}