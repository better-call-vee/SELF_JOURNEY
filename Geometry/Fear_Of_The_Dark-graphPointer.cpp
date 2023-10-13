/*
☞ Better.Call.Vee ☜
created: 10th October, 2023 12:17:55 GMT+6
https://codeforces.com/contest/1886/problem/B
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct point {
    int x = 0, y = 0; // to organize the code
};

double dist(point a, point b) { return hypot(a.x - b.x, a.y - b.y); }
// hypotenuse(অতিভূজ) function. returns rootover(a^2 + b^2)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while(T--) {
        point O, A, B, P;
        cin >> P.x >> P.y >> A.x >> A.y >> B.x >> B.y;

        // strategies:
        double mini_dist =
            min({max(dist(A, O), dist(A, P)), //{} for more than 2 elements.(1)
                 max(dist(B, O), dist(B, P)), //(2)
                 max({dist(A, O), dist(A, B) / 2, dist(B, P)}),   //(3)
                 max({dist(B, O), dist(A, B) / 2, dist(A, P)})   //(4)
                 }); 

        cout << mini_dist << "\n";
    }

    return 0;
}

/*

(1, 2) => when we only use the A/B lantern. For A: We take the max of (A, O) and
(A, P) to light up all the areas from O to P. taking max because we can't change
the power while moving and thus we have to decide at once. A --> O --> P or
O --> A --> P or O --> P --> A.

(3, 4) => crucial strategy. example is the second test case.
for 3 and 4, we will use both lanterns. We will take the max of (A, O),
A and B's half measure and (B, P). It  doesn’t strictly mean Monocarp travels
from O to A, then A to B, and finally B to P. It represents setting the lantern
power such that it is possible to travel along these segments if needed,
lighting up a path from O to P.
It turns out to be the strategy that requires the least power among
the considered ones. I mean, if you take the max of them, it will lighting up
the needed path easily.

*/