The C programming language allows casting between different numeric data types, but this just change the interpretations of the bits it doesn't change the bit patterns themselves. This can lead to Error.

example :
```c
short int v = -12345;
unsigned short uv = (unsigned short) v;
printf("v = %d, uv = %u\n", v, uv);

// result : v = -12345, uv = 53191
```

```c
unsigned u = 4294967295u; /* UMax */
int tu = (int) u; 
printf("u = %u, tu = %d\n", u, tu);

// result : u = 4294967295, tu = -1
```

In a more mathematical way, using the functions `U2B` and `T2B` that map integer representation to binary vectors we can define `T2U` (two's complement to unsigned) as `T2Uw(x)=B2Uw( T2Bw( x ) )`.

Similarly  the function `U2Tw` , defined as `U2Tw(x)= B2Tw( U2Bw(x) )`.

Any hex or binary value has different unsigned and twos representation, we also remark that these two representation when summed together gives the $2^w$ (the range).

---

**Function expression for `T2U`**, For x such that  TMinw ≤ x ≤ TMaxw :
![](../../../Attachements/Pasted%20image%2020260619201634.png)

if we compute the diff between B2U w (x) − B2T w (x), the weighted sums for bits from 0 to w − 2 will cancel each other, leaving a value B2U w(x) − B2T w (x) = xw−1 (2w−1 − −2w−1 ) = xw−12 w . This gives a relationship B2U w (x) = B2T w (x) + xw−12w . We therefore have :

`B2U w (T2B w (x)) = T2U w (x) = x + xw−12 w` where bit xw−1 determines whether or not x is negative, giving the two cases above.

example : `T2U 16(−12,345) = −12,345 + 216 = 53,191`, `T2U w (−1) = −1 + 2w = UMaxw`.

We also note that when doing `T2U` if a value is positive then it doesn't change during the traduction but when its negative this later increase significantly by $2^w$. (as these figures show).

![](../../../Attachements/Pasted%20image%2020260619205410.png)

---

**Function representation of `U2T`:**
![](../../../Attachements/Pasted%20image%2020260621100806.png)

![](../../../Attachements/Pasted%20image%2020260621100838.png)

---

**Summary**:
The conversion between U to T and vise versa :
- 0 <= x <= `TMaxw` : both `T2U(x) = x` and `U2T(x) = x` (number in this range has similar representations)
- For value outside the range above it s either add $2^w$ `T2U` or subtract `U2T`

Note :
The closest number to zero in `T` is the largest number in `U` :  $T2U w(−1) = −1 + 2w = UMaxw$ 

The most negative number maps to an unsigned number just outside the range of positive two’s-complement numbers :  $T2U w (TMinw ) = −2w−1 + 2w = 2w−1 = TMax w + 1$
