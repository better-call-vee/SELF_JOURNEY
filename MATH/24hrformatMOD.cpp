/*
☞ Better.Call.Vee ☜
created: 21th October, 2023 18:53:08 GMT+6
https://atcoder.jp/contests/abc325/tasks/abc325_b
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    map<int, int> time_and_emp;
    for(int i = 0; i < n; i++) {
        int emp, time;
        cin >> emp >> time;
        if(time == 0) time = 24;
        time_and_emp[time] += emp;
    }

    ll ans = 0;
    for(int i = 0; i <= 23; i++) {
        ll total = 0;
        for(auto [time, emp] : time_and_emp) {
            int chk = (i + time) % 24;
            if(chk >= 9 and chk < 18) total += emp;
        }
        ans = max(ans, total);
    }
    cout << ans;

    return 0;
}