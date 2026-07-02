Integer multiplication can cause a lot of overhead (3 clock cycles for the `i7` `Haswell`), so to speed that up compilers have a way to optimize multiplications by replacing it with constant factors with combinations of shift and addition operations.

---

**First case multiplication by a power of 2**:
When multiplying a integer `x` to a power of `k` ($x*2^k$) the `w+k` bit representation is given by `x<<k`. As an example : $11*4 = 44$ that is in bit level representation $[1011] << 2 = [101100]$ with $4 = 2^2$.

---

**Unsigned multiplication by a power of 2**:
For C variables x and k with unsigned values x and k, such that 0 ≤ k < w, the C expression x << k yields the value: 
![](../../../Attachements/Pasted%20image%2020260702084412.png)

**Two’s-complement multiplication by a power of 2**:
For C variables x and k with two’s-complement value x and unsigned value k, such that 0 ≤ k < w, the C expression x << k yields the value:
![](../../../Attachements/Pasted%20image%2020260702084554.png)

---

Multiplying by the power of 2 can cause overflows shifted the 4-bit pattern [1011] (numeric value 11) left by two positions to get [101100] (numeric value 44). Truncating this to 4 bits gives [1100] (numeric value 12 = 44 mod 16). Other example 3*a as (a<<1) + a.

C compilers try to remove many cases where an integer is being multiplied by a constant with combinations of shifting, adding, and subtracting. For example, sup- pose a program contains the expression x*14. Recognizing that 14 = 23 + 2 2 + 21, the compiler can rewrite the multiplication as (x<<3) + (x<<2) + (x<<1), replac- ing one multiplication with three shifts and two additions. The two computations will yield the same result, regardless of whether x is unsigned or two’s comple- ment, and even if the multiplication would cause an overflow. Even better, the compiler can also use the property 14 = 24 − 21 to rewrite the multiplication as (x<<4) - (x<<1), requiring only two shifts and a subtraction.

---

![](../../../Attachements/Pasted%20image%2020260702090820.png)

Note: $2^x=14$ is impossible so we use the compiler uses this technique.