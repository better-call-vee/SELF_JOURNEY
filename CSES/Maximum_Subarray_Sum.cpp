/*
  +----------+
  | Better.  |
  | Call.Vee |
  +----+-----+
       |
       V
created: 28th September, 2023 14:54:21 GMT+6
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<ll> inp(n);
    for(int i = 0; i < n; i++) cin >> inp[i];

    ll maxSum = -1e18, maxSubarrSum = -1e18;
    for(int i = 0; i < n; i++) {
        maxSubarrSum = max(inp[i], inp[i] + maxSubarrSum);
        maxSum = max(maxSubarrSum, maxSum);
    }

    cout << maxSum;

    return 0;
}