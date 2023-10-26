#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    cin >> n;

    long long ans = sqrtl(n);
    while (ans * ans <= n)
        ans++;
    while (ans * ans > n)
        ans--;

    // it precisely calculates the square root while making
    // the complexity O(1);

    cout << ans;
}