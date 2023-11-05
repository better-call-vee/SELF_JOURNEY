/*
☞ Better.Call.Vee ☜
created: 31th October, 2023 01:48:51 GMT+6
https://codeforces.com/contest/1891/problem/B
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
        int n, q, query;
        cin >> n >> q;

        vector<vector<int>> bit_n_ids(31);
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            bit_n_ids[__builtin_ctz(a[i])].push_back(i);
        }

        for(int i = 0; i < q; i++) {
            cin >> query;
            for(int j = query; j <= 30; j++) {
                for(auto id : bit_n_ids[j]) {
                    a[id] += (1 << (query - 1));
                    bit_n_ids[query - 1].push_back(id);
                }
                bit_n_ids[j].clear();
            }
        }

        for(int i = 0; i < n; i++) cout << a[i] << " \n"[i == n - 1];
    }

    return 0;
}

/*
line 32: bit_n_ids[query - 1].push_back(id);
It's because when I add the 2^(query - 1) to any element, it will lessen
the zeroes to the right of the least significant bit.
suppose, 2^4:16 = 10000 => after adding 2^3:8, it will become 24 => 11000
see. 
[THIS IS THE MAIN LESSON HERE]
We also clear out the current id vector after using it.


Why everytime j <= 30?
because we need to check every multiple of that 2^query.
suppose, query is 2. every number which will contain zeroes(in binary)
more than or equivalent to 2, will be divisible by query 2(2^2).
*/