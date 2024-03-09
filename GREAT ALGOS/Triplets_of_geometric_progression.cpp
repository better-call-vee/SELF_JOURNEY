#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, r;
    cin >> n >> r;
    vector<int> a(n);
    map<ll, int> l, rt;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        rt[a[i]]++;
    }
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        int mid = a[i];
        rt[a[i]]--;
        if(a[i] % r != 0) {
            l[mid]++;
            continue;
        }
        ll left = mid / r, right = 1LL * r * mid;
        ans += (1LL * l[left] * rt[right]);
        l[mid]++;
    }
    cout << ans;
    return 0;
}

/*
We have to count the r based geometric progression for i < j < k;
https://www.hackerrank.com/challenges/count-triplets-1/problem

here, we fix the middle element. and at first we take count of all elements as
the right element. then we go on and count all the occurances while including
left and right counts.
*/