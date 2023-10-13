/*
☞ Better.Call.Vee ☜
created: 10th October, 2023 23:14:22 GMT+6
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while(T--) {
        string s1;
        ll pos;
        cin >> s1 >> pos;
        pos--;

        int remove_char, substr_pos;

        int n = s1.size();
        for(int i = 0; i < n; i++) {
            int substr_length = n - i;

            if(substr_length > pos) {
                remove_char = i;
                substr_pos = pos;
                break;
            }

            pos -= substr_length;
        }

        string S;
        for(int i = 0; i < n; i++) {
            char chk = s1[i];

            while(remove_char > 0 and !S.empty() and chk < S.back()) {
                S.pop_back();
                remove_char--;
            }

            S += chk;
        }

        cout << S[substr_pos];
    }

    return 0;
}