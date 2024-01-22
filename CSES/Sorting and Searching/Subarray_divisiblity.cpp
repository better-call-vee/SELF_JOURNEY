/*
☞ Better.Call.Vee ☜
created: 21th November, 2023 21:40:34 GMT+6
https://cses.fi/problemset/task/1662
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> inp(n), mod_cnt(n, 0), pre_sum_mods(n + 1, 0);
    for(int i = 0; i < n; i++) cin >> inp[i];

    mod_cnt[0] = 1;
    // prefix_sum[j] - prefix_sum[i-1] = subarray sum. so, we
    // need the 0 mod count set to 1. 0 % n is 0(an implicit empty subarray)
    for(int i = 1; i <= n; i++) {
        pre_sum_mods[i] = pre_sum_mods[i - 1] + inp[i - 1];
        pre_sum_mods[i] %= n;
        pre_sum_mods[i] = (pre_sum_mods[i] + n) % n; // numbers can be negative
        mod_cnt[pre_sum_mods[i]]++; // counting the mods' frequencies
    }

    ll ans = 0;
    auto combinations = [&](int j) {
        ans += (1ll * mod_cnt[j] * (mod_cnt[j] - 1) / 2);
    };
    // a lambda function to count the combinations

    for(int i = 0; i < n; i++) combinations(i);

    cout << ans;

    return 0;
}

/*
2 5 5
here => prefix sums => 0 2 7 12
next => pre_sum_mods : 0 2 1 0
the 1 mods will make 1 combination. 12 - 0 = 12.

(prefix_sum[r] - prefix_sum[l-1]) % n has to be 0.
So, prefix_sum[r] % n = prefix_sum[l] % n means we got a sub-array.
so, we store the mod counts.
and the (mod_cnt * mod_cnt - 1) / 2 is to calculate the sub-array combinations

*/