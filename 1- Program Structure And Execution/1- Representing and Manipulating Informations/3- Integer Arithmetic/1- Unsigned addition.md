If we have two integers as follow : $0 <= x, y < 2^w$, the sum of x and y we get something in the range of $0<= x+y <= UMaxw + UMaxw$ that is $0<= x+y <= (2^w - 1) + (2^w - 1)$ that is $0<= x+y <= 2^(w+1) − 2$ .

![](../../../Attachements/Pasted%20image%2020260623154626.png)

So representing this sum could require w+1 bits. So we just truncate to be w bits and read the result as unsigned.

![](../../../Attachements/Pasted%20image%2020260623154813.png)

This can be characterized by : $Sum . mod(2^w)$ 

example: x = 9 (1001) and y = 12 (1100), the sum is 21 (10101) --->Truncation---> (0101) which is 5. Also we could have done 21.mod(16) = 5.

these additions has the sign :
![](../../../Attachements/Pasted%20image%2020260623154425.png)

---

**Detecting overflows :**
When an overflow like this occurs in a C program it is not signaled as an error but there s ways to know that.

For x and y in the range 0 ≤ x, y ≤ UMaxw , let s = . x +u w y. Then the computation of s overflowed if and only if s < x (or equivalently, s < y).

code example :
```c
int uadd_ok(unsigned x, unsigned y) {
    unsigned result = x + y;
    return result >= x; // Returns 1 if safe, 0 if it overflowed
}
```
