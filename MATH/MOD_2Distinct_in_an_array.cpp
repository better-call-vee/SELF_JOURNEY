// we will be given an array(all distinct elements), we have to find the k by
// which if we mod all the elements of the array, there will remain only 2
// distinct values
// the main insight of this problem is: if we double up the k starting from 1,
// we will get the divergence at a point , where there will be two distinct mod
// values.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--) {
        ll n, k = 1 * 2;
        cin >> n;
        vector<ll> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        while(1) {
            set<ll> mods;
            for(int i = 0; i < n; i++) mods.insert(a[i] % k);
            if(mods.size() == 2) {
                cout << k << "\n";
                break;
            }
            k *= 2;
        }
    }
    return 0;
}
/*
Let's consider a simple array:
[8,16,24,32].

Start with
k=1: Every number modulo 1 is 0. All remainders are the same (uniform).

Double k to 2: Every number in the array is even, so every number modulo 2 is 0. Still
uniform.

Double k to 4: 
8mod4=0
16mod4=0
24mod4=0
32mod4=0
All remainders are 0. Still uniform.

Double k to 8:
8mod8=0
16mod8=0
24mod8=0
32mod8=0
Still uniform.

Double k to 16: Now, we see a change.
8mod16=8
16mod16=0
24mod16=8
32mod16=0
We have two distinct remainders: 0 and 8. We found our answer efficiently.*/