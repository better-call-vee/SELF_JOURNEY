/*
☞ Better.Call.Vee ☜
created: 13th November, 2023 19:16:15 GMT+6
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
 
    int n, t;
    cin >> n >> t;
 
    vector<int> machines(n);
    for(int i = 0; i < n; i++) cin >> machines[i];
 
    ll left = 0, right = 1e18, ans = 1e18;
    while(left <= right) {
        ll sec = left + (right - left) / 2, sum = 0, i;
 
        for(i = 0; i < n; i++) {
            sum += sec / machines[i];
            if(sum >= t) {
                ans = min(ans, sec);
                break;
            }
        }
 
        if(sum >= t)
            right = sec - 1;
        else
            left = sec + 1;
    }
 
    cout << ans;
 
    return 0;
}