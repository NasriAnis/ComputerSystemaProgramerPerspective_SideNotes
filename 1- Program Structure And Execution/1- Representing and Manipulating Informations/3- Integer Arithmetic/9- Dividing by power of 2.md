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

