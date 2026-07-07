positional notation as we have seen in [2- Fractional Binary Numbers](2-%20Fractional%20Binary%20Numbers.md) is not efficient since we loose some precision when representing very large numbers. Instead we will represent numbers in the form : $x*2^y$.

---

The IEEE floating point represent a number in the form : $V = (−1)^s × M × 2^E$. Where:
- The sign s determines whether the number is negative (s = 1) or positive (s = 0), where the interpretation of the sign bit for numeric value 0 is handled as a special case (there's a +0 and a −0 bit pattern, but both mean "zero").

 - The `significand` M is a fractional binary number that ranges either between 1 and $2 − \epsilon$ or between 0 and $1 − \epsilon$.
	 - For **normalized** numbers, M ranges between 1 and 2−ε (i.e., $1≤M<2$). It's written as `1.xxxxx` in binary — the leading 1 is implied/not stored, saving a bit.
	- For **denormalized** numbers (used for representing very small numbers near zero, including exact 0), M ranges between 0 and 1−ε (i.e., $0≤M<1$), written as `0.xxxxx`.

- The exponent E weights the value by a (possibly negative) power of 2.
	- Can be positive (large numbers) or negative (small numbers, like the 2⁻²⁴).
	- Stored as a biased unsigned value in practice, but conceptually it's just an integer exponent.


For more details of where all of this mean and from where they come from :

1. Step 1: Determine the sign `s`
	Just look at whether the number is negative or positive:
	- Positive or zero → s=0
	- Negative → s=1
	
	Then work with the **absolute value** for the rest of the steps.

2. Step 2: Convert the number to binary (integer + fraction parts)
	Take the number, say **13.25**.
	
	Convert integer part to binary: 13=1101
	Convert fractional part to binary: 0.25=0.01
	
	So: 13.25=1101.01

3. Step 3: Normalize — shift the binary point until there's exactly one `1` before it
	
	1101.01=1.10101×2^3
	
	(You moved the point 3 places to the left, so you multiply by 232^3 23 to compensate.)
	
	This immediately gives you:  
	
	M=1.10101=1.65625    and    E=3

**Why this always works:** any nonzero binary number has some leading 1 somewhere. You just slide the point right after that leading 1, and count how many places you moved it — that count (with sign) is E.

---

The bit representation is divided into three fields:
- The single sign bit s directly encodes the sign s.
- The k-bit exponent field $\exp = e_{k-1} \cdots e_1 e_0$ encodes the exponent E.
- The n-bit fraction field $\text{frac} = f_{n-1} \cdots f_1 f_0$ encodes the `significand` M, but the value encoded also depends on whether or not the exponent field equals 0.

![](../../../Attachements/Pasted%20image%2020260707100305.png)

In C single precision is a `float` and the double precision is a `double`.

---

The value encoded by a given bit representation can be divided into three different cases (the latter having two variants), depending on the value of exp.

### Case1: Normalized values

