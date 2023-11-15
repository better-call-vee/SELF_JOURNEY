/*
☞ Better.Call.Vee ☜
created: 15th November, 2023 12:20:08 GMT+6
https://codeforces.com/edu/course/2/lesson/6/5/practice/contest/285084/problem/C
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, k, inp;
vector<int> a, b;

bool sumcnt(int x) {
    int left = 0, right = n - 1;
    ll cnt = 0;
    while(left < n and right >= 0) {
        if(a[left] + b[right] <= x) {
            cnt += right + 1;
            left++;
        } else
            right--;
    }
    return cnt >= k; //there are more than k pairs of less than
    //mid equivalent sum means, it's a chance to be the answer.
    //if it's true, we suppress the range more and try to get a 
    //less mid to lessen the answer.
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> inp;
        a.push_back(inp);
    }
    for(int i = 0; i < n; i++) {
        cin >> inp;
        b.push_back(inp);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int left = 0, right = 2e9, ans;
    while(left <= right) {
        int mid = left + (right - left) / 2;
        if(sumcnt(mid)) {
            ans = mid;
            right = mid - 1;
        } else
            left = mid + 1;
    }

    cout << ans;

    return 0;
}