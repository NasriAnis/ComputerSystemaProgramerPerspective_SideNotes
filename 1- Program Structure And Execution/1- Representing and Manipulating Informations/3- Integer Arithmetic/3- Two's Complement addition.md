in twos complement addition can yield either a too large (positive) or too small (negative) number o represent in the w bit, we then just truncate the overflow.

Given integer values x and y in the range −2 w−1 ≤ x, y ≤ 2w−1 − 1, their sum is in the range −2w ≤ x + y ≤ 2w − 2, potentially requiring w + 1 bits to represent exactly. 

For integer values x and y in the range −2w−1 ≤ x, y ≤ 2 w−1 − 1:
![](../../../Attachements/Pasted%20image%2020260624122211.png)

---

When x+y yield a number bigger than `Tmax` we say a positive overflow occurs and when its smaller than `Tmin` we say that a negative overflow occurred. In this case, the effect of truncation is to add 2w to the sum.

![](../../../Attachements/Pasted%20image%2020260624123008.png)

---

Since two’s-complement addition has the exact same bit-level representation as unsigned addition, we can characterize the operation +t as one of converting its arguments to unsigned, performing unsigned addition, and then converting back to two’s complement:
![](../../../Attachements/Pasted%20image%2020260626061302.png)

---

To better understand this let define :
- z = x + y
- z' = z mod 2^w
- z'' = U2T z'

From there we get 4 cases :

1. $−2^w ≤ z < −2^(w−1)$ : From there we have $z'=z+2^w$ => $0<= z' < -2^(w-1) + 2^w = 2^(w-1)$. And from that and the U2T equation we fall into the range `< TMax` so $z'' = z'$.
	This is case of negative overflow adding two numbers and obtaining a no-negative  (that’s the only way we can have z < −2w−1) result $z'' = x + y + 2^w$ 

2. $−2w−1 ≤ z < 0$ : We will have $z' = z + 2w$ giving $−2w−1 + 2w = 2w−1 ≤ z' < 2 w$, Since z' is in this range then $z'' = z' − 2w$ therefore  $z'' = z' − 2w = z + 2w − 2w = z$. That is, our two’s- complement sum `z''` equals the integer sum x + y.

3. $0 ≤ z < 2w−1$ : Then we will have $z' = z$, giving $0 ≤ z' < 2 w−1$ , and hence $z'' = z' = z$. Again, the two’s-complement sum `z''` equals the integer sum x + y.

4. $2w−1 ≤ z < 2w$ . We will again have $z' = z$, giving $2w−1 ≤ z' < 2w$ . But in this range (u > TMax) we have $z'' = z' − 2w$ , giving $z'' = x + y − 2w$ . This is the case of positive overflow. We have added two positive numbers x and y (that’s the only way we can have z ≥ 2 w−1 ) and obtained a negative result $z'' = x + y − 2w$.

examples :
![](../../../Attachements/Pasted%20image%2020260626064946.png)

--- 
 
 Detecting overflows : For x and y in the range TMinw ≤ x, y ≤ TMaxw , let s = . x +t w y. Then the compu- tation of s has had positive overflow if and only if x > 0 and y > 0 but s ≤ 0. The computation has had negative overflow if and only if x < 0 and y < 0 but s ≥ 0.

---

![](../../../Attachements/Pasted%20image%2020260626065603.png)

Note : its -2, -4, -6, -8 not 22, 24, 26, 28.