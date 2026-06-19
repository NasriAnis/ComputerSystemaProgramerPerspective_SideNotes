We can make several operations on integers as this table shows :
![Pasted image 20260618082727](../../Attachements/Pasted%20image%2020260618082727.png)
# Integral Data type

The numbers of byte allocated for different compile size (32 or 64 bits) varies this allows different ranges.

The long data type is always machine independent.

we can see the ranges there :
![Pasted image 20260618083139](../../Attachements/Pasted%20image%2020260618083139.png)
![Pasted image 20260618083148](../../Attachements/Pasted%20image%2020260618083148.png)

The C standards also define minimum ranges of value that each data type must be able to represent:
![Pasted image 20260618083336](../../Attachements/Pasted%20image%2020260618083336.png)
# Unsigned encoding

From a bit vector we can make the operation `B2U` (binary to unsigned) using this formula : 
![Pasted image 20260618083557](../../Attachements/Pasted%20image%2020260618083557.png)

for a vector : `x = [xw−1, xw−2, . . . , x0 ]:` (with `w` the position of the bit)

example: 
```
B2U 4 ([0001]) = 0 . 2^3 + 0 . 2^2 + 0 . 2^1 + 1 . 2^0 = 1
```

We can represent this calculation this way : (depending on the place of the digit and if his value is 1 we add the number he encodes).
![Pasted image 20260618084409](../../Attachements/Pasted%20image%2020260618084409.png)

We can calculate also `UMax` of any bit vector represented using w bits :
![Pasted image 20260618084133](../../Attachements/Pasted%20image%2020260618084133.png)

that is equal to 2^w -1.
# Two's Complement encoding

From a bit vector we can also Two's complement encode it, using the `B2T` function :
![Pasted image 20260618084641](../../Attachements/Pasted%20image%2020260618084641.png)

Here the most significant bit `X w-1` is called the sign bit and its weight is of the part we added at the left.

and here is the figure it represent :
![Pasted image 20260618084856](../../Attachements/Pasted%20image%2020260618084856.png)

example:
```
B2T 4([1011]) = −1 . 23 + 0 . 22 + 1 . 21 + 1 . 20 =  −5
```

`TMin` is given by the value of `-2^(w-1)` the most significant bit set to 1 and all other bits to zero: 1000...

in the other hand `Tmax` :
![Pasted image 20260618085211](../../Attachements/Pasted%20image%2020260618085211.png)

that is : `2^(w-1) -1`

### Note
As we saw the signed part range is `+1` time bigger than the unsigned part from that we have the equation :  `|TMin| = |TMax| + 1` (this is due to the sign bit being used in the `TMin` and always set to zero in `Tmax`) and also ` UMax = 2TMax + 1`

![Pasted image 20260618090055](../../Attachements/Pasted%20image%2020260618090055.png)

There's libraries that define and make data types the same across devices possible like the `limits.h` (defines constants `INT_MAX`, `INT_MIN`, and `UINT_MAX` describing the ranges of signed and unsigned integers. For a two’s-complement machine in which data type int has w bits, these constants correspond to the values of `TMaxw` , `TMin` w , and `UMaxw`), `stdint.h` etc more on that in [here](2.1-%20Asides.md).

Example of two's complement representation :
![Pasted image 20260618091551](../../Attachements/Pasted%20image%2020260618091551.png)

# Conversions between Singed and Unsigned

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
![](../../Attachements/Pasted%20image%2020260619201634.png)

if we compute the diff between B2U w (x) − B2T w (x), the weighted sums for bits from 0 to w − 2 will cancel each other, leaving a value B2U w(x) − B2T w (x) = xw−1 (2w−1 − −2w−1 ) = xw−12 w . This gives a relationship B2U w (x) = B2T w (x) + xw−12w . We therefore have :

`B2U w (T2B w (x)) = T2U w (x) = x + xw−12 w` where bit xw−1 determines whether or not x is negative, giving the two cases above.

example : `T2U 16(−12,345) = −12,345 + 216 = 53,191`, `T2U w (−1) = −1 + 2w = UMaxw`.

We also note that when doing `T2U` if a value is positive then it doesn't change during the traduction but when its negative this later increase significantly by $2^w$. (as these figures show).

![](../../Attachements/Pasted%20image%2020260619205410.png)

---

