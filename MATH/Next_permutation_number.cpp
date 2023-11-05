#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string nextPermutation(string s) {
    int n = s.size();
    int i, j;
    
    // Find the first decreasing digit from right
    for (i = n - 2; i >= 0; i--) {
        if (s[i] < s[i + 1]) break;
    }
    
    // If no such digit is found, then it's the highest permutation
    if (i == -1) return "BIGGEST";
    
    // Find a number just larger than s[i] from the right of s[i]
    for (j = n - 1; j > i; j--) {
        if (s[j] > s[i]) break;
    }
    
    // Swap s[i] and s[j]
    swap(s[i], s[j]);
    
    // Reverse the digits after i
    reverse(s.begin() + i + 1, s.end());

    return s;
}

int main() {
    int P;
    cin >> P;
    for (int p = 0; p < P; p++) {
        int dsNum;
        string s;
        cin >> dsNum >> s;
        cout << dsNum << " " << nextPermutation(s) << endl;
    }
    return 0;
}

//https://acm.hdu.edu.cn/showproblem.php?pid=3283