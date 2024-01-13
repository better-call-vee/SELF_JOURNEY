// https://codeforces.com/contest/1558/problem/A
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--) {
        int a, b;
        cin >> a >> b;
        if(a < b) swap(a, b);
        if(a - b & 1) {
            cout << 2 * b + 2 << "\n";
            for(int i = (a - b) / 2; i <= (a + b) - (a - b) / 2; i++)
                cout << i << " ";
        } else {
            cout << b + 1 << "\n";
            for(int i = (a - b) / 2; i <= (a + b) - (a - b) / 2; i += 2)
                cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}

/*
13th line, 17th line:
when a - b is even, the answer is b + 1,
see, the minimum break is (a - b) / 2, and the maximum break possible is
(a + b) - minimum break;
how?
suppose, A = 10, B = 4, the minimum break will be 3.
A B A B A B A B A B A B A B => 0 break combination(sample)
A B A A A A A B A B A A A B => minimum break possible for the above case.
      -   -           -
A B A B A B A B A B A B A B => 0 break combination(sample)
B A B A B A B A A A A A A A => maximum break possible for the above case.
- - - - - - - -   -   -   -

if we subtract the maximum and the minimum possible breaks, we will get
2b. For even difference between a and b, for every two breaks, one's score
is increased.
Let consider the case above, Alice has 10 score, Borys got 4, now we want to
increase borys score, if we increase by 1, it will becomes odd difference. so,
we need to decrease Alice's score as well and it will become 9.
this way, every two times, the breaks work. and thus b + 1 is the answer
for even number of difference.
+1 because of the inclusive behaviour.
Same goes for the odd difference.
Unlike the even difference case, where every additional game beyond the tied
score can be paired up (one for each player), an odd difference means there's
one game that is unpaired. This unpaired game introduces more flexibility in the
number of breaks.
Each of Borys's wins can still be a break, but now, there are additional
scenarios where Alice's wins can also be breaks. This is because the unpaired
game allows for a break scenario that doesn't need to be offset by an additional
game won by Borys.
*/