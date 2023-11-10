/*
Ternary search starts by taking an interval [l, r] and dividing it into three
equal parts using two midpoints, m1 and m2. It then compares the function values
at these midpoints. Depending on the comparison, it discards one-third of the
interval where a minimum or maximum cannot possibly be located.


Interval: [l---------------------------------------------r]
Divide into thirds: [l------m1][m1------m2][m2------r]
Comparisons lead to the discarding of one-third of this interval based on 
where the function increases or decreases.
Repeat on the remaining 2/3rds interval.
Intuition Behind the Steps:

    1) Choosing Points: m1 and m2 are chosen so that they divide the interval
    into three equal parts: m1 = l + (r - l) / 3 and m2 = r - (r - l) / 3.
    2) Evaluating Function: Evaluate the function at m1 and m2.
    3) Discarding Intervals:
        For a minimum search in a unimodal function that first decreases, then increases:
            If f(m1) < f(m2), discard from m2 to r, else discard from l to m1.
        For a maximum search in a unimodal function that first increases, then decreases:
            If f(m1) > f(m2), discard from m2 to r, else discard from l to m1.

A unimodal function has only one local maximum or minimum within a specified range.
Suppose -x^2 , here maximum will 0^2. these points are local extremes.
x^2, here minimum will be 0.

*/
//a code:
#include <iostream>
using namespace std;

double func(double x) {
    // A unimodal function for demonstration
    return -1 * (x - 2) * (x - 2) + 4;
}

void ternary_search(double l, double r) {
    double eps = 1e-9; // Set the error limit here
    while (r - l > eps) {
        double m1 = l + (r - l) / 3;
        double m2 = r - (r - l) / 3;
        double f1 = func(m1), f2 = func(m2);
        if (f1 < f2) // For minimum, for maximum use '>'
            r = m2;
        else
            l = m1;
    }
    cout << "Minimum value is at x = " << (l + r) / 2 << " with value = " << func((l + r) / 2) << endl;
}

int main() {
    double left = 0, right = 100; // Assuming our function has a minimum between 0 and 100
    ternary_search(left, right);
    return 0;
}
