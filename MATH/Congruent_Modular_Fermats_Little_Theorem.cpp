#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void print(int p) {
    int a = 15;
    for(int i = 1; i < p; i++) cout << a * i % p << " ";
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    print(11);
    return 0;
}

/*
use any number except the 'p' here as a, and the output will be shown all the
number from 1 to p - 1 distinctively. BUT p HAS TO BE A PRIME NUMBER.
a * i % p
   a * 1, a * 2, a * 3, a * 4, .... , a * (p - 1) = [1, p - 1] (% p)
=> a * 1 * a * 2 * a * 3 * a * 4 .... a * (p - 1) = (p - 1)! (% p)
=> a^(p - 1) * (p - 1)! = (p - 1)! (% p)
-------------------------
=> a^(p - 1) ≡ 1 (% p)  |
-------------------------
so, a to the power (p - 1) will always be 1 under mod with a prime number.
given that 'a' IS NOT A MULTIPLE of 'p'.


Now,
a^0  a^1  a^2  a^3 ... a^(p - 1) a^p  (% p)
1     a   ---  --- ...     1      a   (% p) [a^(p - 1) gotten from line 22]
see, here we get a cycle of a p - 1 sized. (p must be prime)
------------------------------------
so, a^(n) % p = a^(n % (p - 1)) % p | as there is a cycle of p - 1 sized.
------------------------------------
*/ 
// https://cses.fi/problemset/task/1712/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll power(ll n, ll pw, ll mod) {
    pw %= mod;
    ll ans = 1;
    while(pw) {
        if(pw & 1) ans = ans * n % mod;
        n = n * n % mod;
        pw >>= 1;
    }
    return ans;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--) {
        int a, b, c;
        cin >> a >> b >> c;
        int mod = 1e9 + 7;
        ll pw = power(b, c, mod - 1), final = power(a, pw, mod);
        cout << final << "\n";
    }
    return 0;
}

/*
Here, in this problem, it wanted a^(b ^ c);
and, the mod value is a prime number.
Thus, we can apply The Fermat's little theorem.
see 55th line, we are calling power function with (mod - 1).
*/