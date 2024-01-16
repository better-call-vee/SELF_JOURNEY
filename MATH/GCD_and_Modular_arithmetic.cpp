#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> divs, a(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 1; i * i <= n; i++)
            if(n % i == 0) {
                divs.push_back(i);
                if((n / i) != i) divs.push_back(n / i);
            }
        int d = divs.size(), k, pnts = 0, gcd1 = 0, gcd2 = 0;
        for(int i = 0; i < d; i++) {
            k = n / divs[i], gcd2 = 0;
            for(int st = 0; st < k; st++) {
                gcd1 = 0;
                for(int j = st; j < n; j += k)
                    gcd1 = gcd(gcd1, abs(a[st] - a[j]));
                gcd2 = gcd(gcd2, gcd1);
            }
            if(gcd2 != 1) pnts++;
        }
        cout << pnts << "\n";
    }
    return 0;
}

/*
https://codeforces.com/contest/1920/problem/C

We will be given an array. We have to make partitions of the array it's size's
divisors' times. Suppose, n = 6, it will divided 4 times (1, 2, 3, 6). Then we
need to decide an integer m >= 2, if it can mod down all the elements and make
the divided subarrays identical or not.

suppose, a[1] , a[2], a[3]...a[k + 1]...a[2k+1]...a[3k+1]...and so on...
the condition is it has to be a[1] % m = a[k+1] % m = a[2k+1] % m ....
we can say from this :
(a[1] - a[k+1]) % m = 0 % m;
=> (a[1] - a[k+1]) % m = 0;
=> that means if m and it's factors can divide fully the difference of the
current element and current element + kth element, then it satisfies our
condition.
Now, for every element and it + kth element we will get a m. Now if the gcd
of those m(s) is not 1, we can determine, we will get an m which actually
accomplishes our goal.
now, the edge case is when all the m(s)' gcd is 0, that means all the
elements are the same.
*/
