/*
☞ Better.Call.Vee ☜
created: 14th November, 2023 21:14:21 GMT+6
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    vector<int> inp(n);
    for(int i = 0; i < n; i++) cin >> inp[i];

    ll left = 1, right = 1e18, ans;
    while(left <= right) {
        ll mid = left + (right - left) / 2, subarr_cnt = 1, sum = 0;

        for(int i = 0; i < n; i++)
            if(inp[i] > mid) {
                subarr_cnt = 1e18;
                goto next;
            }

        sum = inp[0];
        for(int i = 1; i < n; i++) {
            if(inp[i] + sum > mid)
                subarr_cnt++, sum = inp[i];
            else
                sum += inp[i];
        }

    next:
        if(subarr_cnt <= k) {
            ans = mid;
            right = mid - 1;
        } else
            left = mid + 1;
    }

    cout << ans;

    return 0;
}