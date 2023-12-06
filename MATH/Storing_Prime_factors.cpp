// C++ program to print all prime factors
#include <bits/stdc++.h>
using namespace std;

// A function to print all prime
// factors of a given number n
int n;
vector<int> prm_facts;
void primeFactors(int n) {
    // Print the number of 2s that divide n
    while(n % 2 == 0) {
        cout << 2 << " ";
        n = n / 2;
    }

    // n must be odd at this point. So we can skip
    // one element (Note i = i +2)
    for(int i = 3; i <= sqrt(n); i = i + 2) {
        // While i divides n, print i and divide n
        while(n % i == 0) {
            prm_facts[i] = 1;
            n = n / i;
        }
    }

    // This condition is to handle the case when n
    // is a prime number greater than 2
    if(n > 2) prm_facts[n] = 1;
}

/* Driver code */
int main() {
    cin >> n;
    prm_facts.resize(n);
    primeFactors(n);

    for(int i = 2; i * i <= n; i++) {
        if(prm_facts[i]) cout << i << " ";
    }
    return 0;
}
