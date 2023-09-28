/*
  +----------+
  | Better.  |
  | Call.Vee |
  +----+-----+
       |
       V
created: 28th September, 2023 14:54:21 GMT+6
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<ll> inp(n);
    for(int i = 0; i < n; i++) cin >> inp[i];
    //we have to find the maximum sum among the subarrays

    ll maxSum = -1e18, maxSubarrSum = -1e18;
    for(int i = 0; i < n; i++) {
        maxSubarrSum = max(inp[i], inp[i] + maxSubarrSum); //simulate to understand.
        maxSum = max(maxSubarrSum, maxSum);
    }

    cout << maxSum;

    return 0;
}

/*
10
24 7 -27 17 -67 65 -23 58 85 -39
output => 185
 
i	inp[i]	maxSubarrSum	maxSum	Explanation
0	  24	    24	          24	Start with 24
1	  7         31	          31	Extend with 7
2	 -27	     4	          31	Add -27
3	  17	    21	          31	Extend with 17
4	 -67	   -46	          31	Add -67
5	  65	    65	          65	Start new subarray with 65
6	 -23	    42	          65	Add -23
7	  58	   100	         100	Extend with 58
8	  85	   185	         185	Extend with 85
9	 -39	   146	         185	Add -39

So, the maximum subarray sum is 185, which is the sum of the subarray 65, -23, 58, 85.

The algorithm efficiently computes the maximum subarray sum in O(n) time complexity.
It's a dynamic programming approach where the solution to the current problem depends
on the previous state (maxSubarrSum).
The algorithm is elegant and powerful, working even if all numbers are negative.

The essence of the Kadane's algorithm is to loop through the array and at each position, 
decide whether to extend the current subarray or start a new one from the current position.
Two main variables are maintained:

    maxSubarrSum: This holds the maximum subarray sum ending at the current position.
    maxSum: This keeps track of the global maximum subarray sum encountered so far.

For each element inp[i], we have two choices:

    We include inp[i] in the current subarray, i.e., extend the current subarray.
    This will give us inp[i] + maxSubarrSum.
    We start a new subarray from inp[i], making inp[i] the only element in this new subarray.

Among these two choices, we pick the one that gives the maximum value and set it to maxSubarrSum.

Then, we update maxSum to be the maximum of maxSum and maxSubarrSum.
*/