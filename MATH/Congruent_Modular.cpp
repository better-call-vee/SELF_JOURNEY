
If 5^99 is congruent to k (mod 11), what is k?

To solve this, we first find the pattern of 5^n (mod 11) for small n:

5^1 ≡ 5 (mod 11)
5^2 ≡ 3 (mod 11)
5^3 ≡ 4 (mod 11)
5^4 ≡ 9 (mod 11)
5^5 ≡ 1 (mod 11)
5^6 ≡ 5 (mod 11)

Here we see the cycle starts repeating after every 5 terms. Therefore, we can reduce 
the power modulo 5:

99 ≡ 4 (mod 5)

This implies that 5^99 is congruent to 5^4 which is equal to 9 (mod 11). Therefore, k = 9.

≡(congruence sign);


Another One:

What is the value of (-(2^1000)) % 7 ?  
[(minus (2 to the power 1000)) modulo 7]

=>
2^1000 % 7
= (2^999) * 2 % 7
= (2^(3 * 333)) * 2 % 7
= ((2^3)^333) * 2 % 7
= (8^333) * 2 % 7
= (8 % 7)^333 * 2 % 7
= (1^333) * 2 % 7
= 1 * 2 % 7
= 2 % 7
= 2

Now,
-2^1000 % 7
= - (2^1000 % 7) % 7
= -2 % 7
= (-2 + 7) % 7
= 5 % 7
= 5

Also, here is a cycle as well:
2 ^ 1 % 7 = 2
2 ^ 2 % 7 = 4
2 ^ 3 % 7 = 1
2 ^ 4 % 7 = 2 and goes on...
so, 1000 % 3 = 1 => 2 ^ 1 % 7 = 2 => -2 % 7 = 5.
also, last digit:
2 ^ 1 = 2
2 ^ 2 = 4
2 ^ 3 = 8
2 ^ 4 = 6
2 ^ 5 = 2
2 ^ 6 = 4 AND GOES ON...
