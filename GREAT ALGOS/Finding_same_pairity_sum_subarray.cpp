#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool find_subarray(const vector<int> &glasses) {
    int n = glasses.size();
    unordered_map<ll, int> diff_index;
    diff_index[0] = 0;
    ll odd_sum = 0, even_sum = 0;
    for(int i = 0; i < n; ++i) {
        if(i % 2 == 0)
            even_sum += glasses[i];
        else
            odd_sum += glasses[i];
        ll diff = even_sum - odd_sum;
        if(diff_index.find(diff) != diff_index.end()) return true;
        diff_index[diff] = i + 1;
    }
    return false;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> glasses(n);
        for(int i = 0; i < n; i++) cin >> glasses[i];
        cout << (find_subarray(glasses) ? "YES" : "NO") << "\n";
    }
    return 0;
}

// this program finds the same pairity sum subarrays which will
// have equivalent cumulative oddsum and evensum.
/*
The core idea is based on a property of cumulative sums. If at two different
points in an array the cumulative sums have the same difference, then the sum of
elements between these two points must be balanced for the even and odd
positions.

Why Does This Work?
Cumulative Sums:

even_sum is the sum of elements at even indices (considering 0 as even).
odd_sum is the sum of elements at odd indices.
Difference Concept:

The difference diff = even_sum - odd_sum at any point in the array gives us the
net difference between the total juice in even-indexed and odd-indexed glasses
up to that point. Finding Equal Sums:

If at two different indices, say i and j (i < j), this difference diff is the
same, it implies something special: The elements added to even_sum and odd_sum
from index i+1 to j have balanced each other out. This means the sum of elements
at even indices from i+1 to j is equal to the sum of elements at odd indices in
the same range.
*/