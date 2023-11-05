#include <iostream>
using namespace std;

long long computeXOR(long long n) {
    switch(n % 4) {
    case 0:
        return n;
    case 1:
        return 1;
    case 2:
        return n + 1;
    case 3:
        return 0;
    }
    return 0;
}

int main() {
    long long a, b;
    cin >> a >> b;

    long long result = computeXOR(b) ^ computeXOR(a - 1);
    cout << result;
    return 0;
}


/*
If we XOR the result of all numbers from 1 to b with the result of all 
numbers from 1 to a−1, we effectively "cancel out" the numbers from 1 to a−1, 
leaving only the XOR of numbers from aa to bb.

To illustrate with a simple example:

Suppose a=3 and b=5. We want the XOR of 3, 4, and 5.
Using our method:

    XOR of numbers from 1 to 2 = 3
    XOR of numbers from 1 to 5 = 1

Now, 1 ⊕ 3 = 2, which is the XOR of numbers 3, 4, and 5.
*/