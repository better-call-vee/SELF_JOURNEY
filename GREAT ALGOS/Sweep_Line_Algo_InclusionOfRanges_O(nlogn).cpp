/*
☞ Better.Call.Vee ☜
created: 23th October, 2023 13:28:06 GMT+6
https://codeforces.com/contest/1884/problem/C
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int sweepLine(vector<pair<int, int>> go) {
    vector<pair<int, int>> levels;
    for(auto [l, r] : go) {
        levels.push_back({l, +1});
        levels.push_back({r + 1, -1});
    }
    sort(levels.begin(), levels.end());
    int n = levels.size();

    int sum = 0, ans = 0;
    for(int i = 0, j; i < n; i = j) {
        int elm = levels[i].first;
        for(j = i; j < n && elm == levels[j].first; j++)
            sum += levels[j].second;
        ans = max(ans, sum);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, l, r, n, m;
    cin >> t;

    while(t--) {
        cin >> n >> m;
        vector<pair<int, int>> ex1st, exLast;

        for(int i = 0; i < n; i++) {
            cin >> l >> r;
            if(l > 1) ex1st.push_back({l, r});
            if(r < m) exLast.push_back({l, r});
            /*
            It's not that the other elements can't serve as minimum values; it's
            that if looking for the maximum "cost," we should focus on these two
            edge cases.
            */
        }
        cout << max(sweepLine(ex1st), sweepLine(exLast)) << "\n";
    }
    return 0;
}

/*
I have an array initially filled with zeros and a list of segments defined by
their starting and ending indices l[i] and r[i]. I can choose any subset of
these segments to apply to the array. Applying a segment means increasing every
element in the array within that segment's range by 1. After applying my chosen
segments, I have to calculate the maximum and minimum values in the array. My
goal is to maximize the difference between these two values, known as the
"cost."

The problem is solved using a Sweep Line Algorithm. Imagine a vertical line
sweeping from the leftmost to the rightmost index of the array. As this line
hits the starting or ending point of any segment, it triggers an "event."

    Events Creation: For each segment (l,r), two events are generated:
        Starting Event at l with a value of +1
        Ending Event at r with a value of −1

    Sorting: All these events are sorted based on their index.

    Sweeping: We initialize two variables, sum = 0 and ans = 0. As we sweep:
        sum keeps track of the "height" or "level" of the array at the current
        index.(ensures the inclusion of all elements of a range)
        ans records the maximum height encountered so far.

    Event Processing: For each unique position, accumulate all events happening
     at that index to update sum. Then, update ans if sum is greater.

Sorting allows us to process events in their natural order, from left to right.
The inner loop accumulates all events that happen at the same position.
sum is the running "height" at the current index.
*/

/*
6
1 3
2 2
3 8
2 4
3 5
4 6
6 3
1 1
1 2
1 3
2 2
2 3
3 3
7 6
2 2
1 6
1 2
5 6
1 5
4 4
3 6
6 27
6 26
5 17
2 3
20 21
1 22
12 24
4 1000000000
2 999999999
3 1000000000
123456789 987654321
9274 123456789


Output:
1
3
2
3
4
4
*/