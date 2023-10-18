/*
☞ Better.Call.Vee ☜
created: 16th October, 2023 21:13:43 GMT+6
https://basecamp.eolymp.com/en/problems/911
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b, c;
    cin >> a >> b >> c;

    int discriminant = b * b - 4 * a * c;

    if(discriminant > 0) {
        int root1 = (-b - sqrt(discriminant)) / (2 * a),
            root2 = (-b + sqrt(discriminant)) / (2 * a);
        if(root1 > root2) swap(root1, root2);
        cout << "Two roots: " << root1 << " " << root2 << endl;
    } else if(discriminant == 0) {
        int root = -b / (2 * a);
        cout << "One root: " << root << endl;
    } else
        cout << "No roots" << endl;

    return 0;
}