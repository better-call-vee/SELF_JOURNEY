#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2383
bool isProductOfCoPrimes(ll n) {
    for(ll i = 2; i * i <= n; i++)
        if(n % i == 0)
            if((n / i) % i == 0) return false;

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) {
        ll G, L;
        cin >> G >> L;

        if(L % G != 0) {
            cout << "-1\n";
            continue;
        }

        ll Q = L / G;
        if(isProductOfCoPrimes(Q))
            cout << G << " " << L << "\n";
        else
            cout << "-1\n";
    }

    return 0;
}

/*
Given two numbers, a and b, with:
1. GCD(a, b) = G
2. LCM(a, b) = L

We can express both a and b as:
a = G * x
b = G * y

Where:
x and y are integers which represent the non-common
parts of a and b after factoring out G.

From the relationship between GCD and LCM:
a * b = GCD(a, b) * LCM(a, b)
=> G * x * G * y = G * L
=> x * y = L / G

Observations:
1. For a and b to have G as their GCD and L as their LCM,
the factors x and y must be co-prime. If x and y were not
co-prime and shared a common factor f (where f>1), then:
    a would be divisible by f×G
    b would also be divisible by f×G
This would mean there exists a number larger than G that divides
both a and b, contradicting the assertion that G is the greatest
common divisor.

2. If L is not divisible by G, then no such pair (a, b) exists.
3. If L / G is not a product of co-prime factors, then also no
such pair exists.

the answer:
If a=G and b=L, then:
    Their GCD is G (because G is the only factor of a, and G divides L).
    Their LCM is L (because L is a multiple of both a and b).
*/