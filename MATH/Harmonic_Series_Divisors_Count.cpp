/*
☞ Better.Call.Vee ☜
created: 16th October, 2023 18:20:44 GMT+6
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b, c;
    cin >> a >> b >> c;

    vector<int> div_cnt(1e6 + 1); //the constraint is 100. counts in nlogn
    for(int i = 1; i <= 1e6; i++)
        for(int j = i; j <= 1e6; j += i) div_cnt[j]++; 

    ll sum = 0;
    for(int i = 1; i <= a; i++)
        for(int j = 1; j <= b; j++)
            for(int k = 1; k <= c; k++) sum += div_cnt[i * j * k];

    cout << sum;

    return 0;
}