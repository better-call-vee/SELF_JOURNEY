#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
#define endl '\n'
#define fastIO                                                                 \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

using namespace std;

// ofstream cout ("speeding.out");
// ifstream cin ("speeding.in");
// https://atcoder.jp/contests/abc125/tasks/abc125_c?lang=en

int main() {
    fastIO;

    int n;

    cin >> n;

    int pre[n + 2], suf[n + 2], ar[n + 1];

    pre[0] = suf[0] = 0;
    pre[n + 1] = suf[n + 1] = 0;

    for(int i = 1; i <= n; i++) cin >> ar[i];

    for(int i = 1; i <= n; i++) pre[i] = __gcd(pre[i - 1], ar[i]);
    for(int i = n; i >= 1; i--) suf[i] = __gcd(suf[i + 1], ar[i]);

    int mx = 0;

    for(int i = 1; i <= n; i++) mx = max(__gcd(pre[i - 1], suf[i + 1]), mx);

    cout << mx << endl;

    return 0;
}

/*
The pre[] array is filled by calculating the GCD of the current element and the
GCD until the previous element (from left to right). Similarly, the suf[] array
is filled from right to left.

Finding the Maximum GCD: The main logic iterates
through each element and computes the GCD of the prefix GCD (excluding the
current element) and the suffix GCD (also excluding the current element). This
effectively simulates removing each element once and finding the GCD of the
remaining elements. The maximum GCD found in this way is stored in mx.
*/