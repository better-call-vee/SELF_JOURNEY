#include <bits/stdc++.h>
using namespace std;

const int N = 101;
vector<int> divisors[N];
vector<int> divisors2[N];

void storeDivisors() {
    for(int i = 1; i < N; i++)
        for(int j = i; j < N; j += i) divisors[j].push_back(i);
}

void stDiv() {
    for(int i = 1; i < N; i++) {
        for(int j = 1; j * j <= i; j++) {
            if(i % j == 0) {
                divisors2[i].push_back(j);
                if(j != i / j) divisors2[i].push_back(i / j);
            }
        }
        sort(divisors2[i].begin(), divisors2[i].end());
    }
}

int main() {
    // Storing the divisors
    storeDivisors();

    // Printing the divisors for each number up to N
    for(int i = 1; i < N; ++i) {
        cout << "Divisors of " << i << ": ";
        for(int d : divisors[i]) {
            cout << d << " ";
        }
        cout << "\n";
    }

    stDiv();
    cout << "\n\nUsing Rootover Complexity: \n";
    for(int i = 1; i < N; ++i) {
        cout << "Divisors of " << i << ": ";
        for(int d : divisors2[i]) cout << d << " ";
        cout << "\n";
    }

    return 0;
}
