Integer division is even slower and require more CPU cycles (30 or more).

But diving by a power of 2 can be translated to a sequence of shift operations as multiplication but using right shifts rather then left shifts.

There exists two type of right shifts logical and arithmetic that server for unsigned or twos complement numbers respectively.

---

Some notations : 

 For any real number a, define $\lfloor a \rfloor$  to be the unique integer $a'$ such that a' ≤ a < a' + 1. As examples, $\lfloor 3.14 \rfloor$  = 3, $\lfloor -3.14 \rfloor$  = −4, and $\lfloor 3 \rfloor$  = 3

Similarly, define $\lceil a \rceil$ to be the unique integer a' such that a' − 1 < a ≤ a' .
As examples, $\lceil 3.14 \rceil$ = 4,  $\lceil -3.14 \rceil$= −3, and $\lceil 3 \rceil$ = 3. 

 For x ≥ 0 and y > 0, integer division should yield $\lfloor x/y \rfloor$, while for x < 0 and y > 0, it should yield $\lceil x/y \rceil$. That is, it should round down a positive result but round up a negative one.

---

**Unsigned division by power of 2**:
For C variables x and k with unsigned values x and k, such that 0 ≤ k < w, the C
expression x >> k yields the value $\lfloor x/2k \rfloor$.

![](../../../Attachements/Pasted%20image%2020260703164754.png)

---

When performing twos complement shifts we always use arithmetic right shift.

**Twos complement division by power of 2 rounded down**:
Let C variables x and k have two’s-complement value x and unsigned value k, respectively, such that 0 ≤ k < w. The C expression x >> k, when the shift is performed arithmetically, yields the value $\lfloor x/2^k \rfloor$.

![](../../../Attachements/Pasted%20image%2020260704083833.png)

For cases when no rounding is required (k=1) the result will be $x/2^k$, however when rounding is required shifting cause the result to be rounded downward (this still need to be adjusted).

**Two’s-complement division by a power of 2 rounded up**:
We can correct for the improper rounding that occurs when a negative number
is shifted right by “biasing” the value before shifting.

Let C variables x and k have two’s-complement value x and unsigned value k, respectively, such that 0 ≤ k < w. The C expression (x + ==(1 << k) - 1==) >> k, when the shift is performed arithmetically, yields the value $\lceil x/2^k \rceil$.

This figure shows how the shifts are correct now when adding the bias :
![](../../../Attachements/Pasted%20image%2020260704085420.png)

 In the third column, we show the result of adding the bias value to −12,340, with the lower k bits (those that will be shifted off to the right) shown in italics. We can see that the bits to the left of these may or may not be incremented. For the case where no rounding is required (k = 1), adding the bias only affects bits that are shifted off. For the cases where rounding is required, adding the bias causes the upper bits to be incremented, so that the result will be rounded toward zero.

The biasing technique exploits the property that $\lceil x/y \rceil$= $\lfloor (x + y − 1)/y \rfloor$ for integers x and y such that y > 0. As examples: 
-  x = −30 and y = 4, we have x + y − 1 = −27 and $\lceil −30/4\rceil$ = −7 = $\lfloor −27/4\rfloor$ 
-  x = −32 and y = 4, we have x + y − 1 = −29 and $\lceil −32/4\rceil$ = −8 = $\lfloor−29/4\rfloor$

These analyses show that for a two’s-complement machine using arithmetic right shifts, the C expression:
```c
(x<0 ? x+(1<<k)-1 : x) >> k
```

will compute the value $x/2^k$ .