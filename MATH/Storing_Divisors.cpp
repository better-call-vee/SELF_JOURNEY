#include <iostream>
#include <vector>
using namespace std;

const int N = 100;  
vector<int> divisors[N];

void storeDivisors() {
    for(int i = 1; i < N; i++) {
        for(int j = i; j < N; j += i) {
            divisors[j].push_back(i);
        }
    }
}

int main() {
    // Storing the divisors
    storeDivisors();

    // Printing the divisors for each number up to N
    for (int i = 1; i < N; ++i) {
        cout << "Divisors of " << i << ": ";
        for (int d : divisors[i]) {
            cout << d << " ";
        }
        cout << endl;
    }

    return 0;
}
