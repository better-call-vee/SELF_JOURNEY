/*
☞ Better.Call.Vee ☜
created: 15th November, 2023 19:11:51 GMT+6
https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/E
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
double c;

bool calculate(double x) { return x * x + sqrt(x) >= c; }

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> c;
    double left = 1.0, right = 1e5, ans;
    while(right - left >= 1e-6) {
        // there can be answers in between this range so..
        double mid = (right + left) / 2.0;
        if(calculate(mid)) {
            ans = mid;
            right = mid;
        } else
            left = mid;
        // we won't plus or minus mid here because in between 1, there
        // can be so many answers.
    }

    cout << fixed << setprecision(16) << ans;

    return 0;
}