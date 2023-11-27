/*
☞ Better.Call.Vee ☜
created: 24th November, 2023 10:45:30 GMT+6
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//https://cses.fi/problemset/task/1073/
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, cube;
    cin >> n;

    vector<int> towers;
    for(int i = 0; i < n; i++) {
        cin >> cube;
        auto check = upper_bound(towers.begin(), towers.end(), cube);

        if(check == towers.end())
            towers.push_back(cube);
        else
            *check = cube;
    }
    cout << towers.size();

    return 0;
}