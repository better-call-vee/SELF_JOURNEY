// a code:
#include <iostream>
using namespace std;

double func(double x) {
    // A unimodal function for demonstration
    return -1 * (x - 2) * (x - 2) + 4;
}

void ternary_search(double l, double r) {
    double eps = 1e-9; // Set the error limit here
    while(r - l > eps) {
        double m1 = l + (r - l) / 3;
        double m2 = r - (r - l) / 3;
        double f1 = func(m1), f2 = func(m2);
        if(f1 < f2) // For minimum, for maximum use '>'
            r = m2;
        else
            l = m1;
    }
    cout << "Minimum value is at x = " << (l + r) / 2
         << " with value = " << func((l + r) / 2) << endl;
}

int main() {
    double left = 0, right = 100; // Assuming our function has a minimum between 0 and 100
    ternary_search(left, right);
    return 0;
}

/*
Interval: [l---------------------------------------------r]
Divide into thirds: [l------m1][m1------m2][m2------r]

Ternary search is an optimization technique that's used to find the minimum or
maximum of a unimodal function. A unimodal function in a given interval is one
that either consistently increases and then decreases or decreases and then
increases; it has a single peak or trough (maximum or minimum), respectively.

Here's a step-by-step intuitive explanation of how ternary search works,
especially focusing on finding the minimum point of a unimodal function that
decreases and then increases:

Step 1: Choose Initial Points
The search starts by identifying two points, m1 and m2, within the interval [l,
r]. These points divide the interval into three equal parts. If we imagine this
interval as a straight line, m1 is one-third of the way in from the left, and m2
is one-third of the way in from the right.

Step 2: Evaluate the Function
Next, the function values at m1 and m2 are calculated. These values are like
signposts telling us which direction the minimum lies in. Because the function
is unimodal, we know the minimum can't be on both sides of a signpost.

Step 3: Discard the Non-Minimum Third
Based on the values at m1 and m2, we can discard one-third of the interval:

If f(m1) is less than f(m2), then we know the minimum can't be in the part of
the interval from m2 to r. Why? Because the function value at m2 is higher, and
since the function decreases and then increases, the minimum must be to the left
of m2.

If f(m1) is greater than f(m2), then we know the minimum can't be in the part of
the interval from l to m1. The function value at m1 is higher, so the minimum
must be somewhere between m1 and r.

Step 4: Repeat the Process
The search then repeats this process on the remaining two-thirds of the
interval, re-dividing it and discarding one-third at a time. With each
repetition, the interval narrows down, zeroing in on the minimum point.

Step 5: Convergence to the Minimum
This process continues until the interval is reduced to a very small size,
determined by eps (epsilon), which is the acceptable error margin. The value of
eps reflects how precisely you want to find the minimum. A smaller eps means a
more accurate result but requires more iterations of the search.

Visualization
Imagine you're looking for the lowest point in a smooth, rounded valley. You
start by looking at two points somewhat apart from each other. If the left point
is lower, you know the valley's lowest point isn't to the right of the right
point. If the right point is lower, you know it isn't to the left of the left
point. You then forget about the third of the valley where the lowest point
can't be and repeat the process on the remaining part, each time narrowing your
search.

Example
For the function f(x) = -(x - 2)^2 + 4, which is a parabola opening downwards
with a maximum at x = 2, the ternary search algorithm would look for the maximum
by comparing function values at m1 and m2 and discarding the appropriate
interval part where the maximum can't be.

To summarize, ternary search narrows down the search interval by using the
unimodal property of the function to discard the part of the interval where the
extreme value (minimum or maximum) can't possibly exist, thus converging on the
solution iteratively.


A unimodal function is one that has a single 'mode' or peak (maximum) or trough
(minimum) within a given interval.
*/
