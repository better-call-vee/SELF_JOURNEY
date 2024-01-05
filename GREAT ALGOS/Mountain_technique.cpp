// https://codeforces.com/problemset/problem/1832/C

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fast                                                                   \
    ios_base::sync_with_stdio(false);                                          \
    cin.tie(nullptr);                                                          \
    cout.tie(nullptr);

int main() {
    fast;

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        vector<ll> cv(n);

        for(int i = 0; i < n; i++) cin >> cv[i];

        ll contrast = 0;
        for(int i = 0; i < n - 1; i++) contrast += abs(cv[i] - cv[i + 1]);

        if(n == 1 || contrast == 0) {
            cout << 1 << "\n";
            continue;
        }

        ll count = 1;
        int inc = 0;
        for(int i = 1; i < n; i++) {
            if(cv[i] > cv[i - 1] && inc != 1) {
                inc = 1;
                count++;
            } else if(cv[i] < cv[i - 1] && inc != -1) {
                inc = -1;
                count++;
            }
        }

        cout << count << "\n";
    }

    return 0;
}

/*
This technique is particularly useful in scenarios where the array exhibits
fluctuations similar to the ascents and descents of a mountainous terrain. Let's
break down this technique with a clearer explanation:

Understanding the Problem
The problem involves an array of numbers. The "contrast" of an array is defined
as the sum of the absolute differences between each pair of adjacent elements.
For example, for the array [5, 4, 2, 1, 0, 0, 4], the contrast is |5-4| + |4-2|
+ |2-1| + |1-0| + |0-0| + |0-4|, which equals 9.

The objective is to determine the minimum number of elements required to
represent this contrast.

The Mountain Technique
Visualizing Peaks and Valleys: Think of the array as a mountainous landscape.
Each element is a point on this terrain. A rise in value indicates an ascent,
while a drop signifies a descent.

Identifying Changes in Direction: Note when the "slope" of the mountain changes
– from ascending to descending or vice versa. These points are crucial as they
represent a change in the trend of the array.

Calculating Contrast with Fewer Elements:
If the array is continuously ascending or descending, the contrast can be found
simply by subtracting the first element from the last. In this scenario, only
two elements (start and end) are needed. In cases where the array has both
ascents and descents, more elements are required. Each time there's a change in
direction (from ascent to descent or vice versa), it's essential to include the
element at this turning point. This is because these points contribute
significantly to the total contrast.

Example Analysis:
For [5, 4, 2, 1, 0, 0, 4], the contrast is 9. Initially, the array descends till
the 6th element (0). Then, it ascends to 4. We include the element at the
turning point (0) in our calculation. If the array were [1, 2, 3, 4, 5], it's
continuously ascending, so only the first and last elements are needed. The
contrast is 5 - 1 = 4.

Counting the Required Elements: Start with the first
element, then traverse the array. Each time there's a change in direction,
increment your count. This count represents the minimum number of elements
required to represent the original contrast.

Conclusion
The mountain technique is an intuitive method to minimize the number of elements
while preserving the contrast of the array. It's particularly effective in
scenarios where the array exhibits multiple ascents and descents, akin to a
mountain range. By focusing on the turning points where the direction changes,
you effectively capture the essence of the array's contrast with fewer elements.






*/