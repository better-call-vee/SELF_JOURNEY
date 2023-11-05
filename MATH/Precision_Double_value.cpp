if (a == b)
 when a and b are double values.

Even if a and b are equal, they might not be equal in the computer's 
perspective due to precision issues.
Better Approach: 
if (abs(a - b) < 1e-9)
abs returns the absolute value of a number. 
1e-9 is 10^-9, which is a very small number.
So, if the difference between a and b is less than 1e-9, 
then we can consider them as equal.
