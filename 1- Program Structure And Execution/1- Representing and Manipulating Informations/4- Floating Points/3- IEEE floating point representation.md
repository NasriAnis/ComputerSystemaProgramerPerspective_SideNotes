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

---

The bit representation is divided into three fields:
- The single sign bit s directly encodes the sign s.
- The k-bit exponent field $\exp = e_{k-1} \cdots e_1 e_0$ encodes the exponent E.
- The n-bit fraction field $\text{frac} = f_{n-1} \cdots f_1 f_0$ encodes the `significand` M, but the value encoded also depends on whether or not the exponent field equals 0.

![](../../../Attachements/Pasted%20image%2020260707100305.png)

In C single precision is a `float` and the double precision is a `double`.

---

The value encoded by a given bit representation can be divided into three different cases (the latter having two variants), depending on the value of exp.

![](../../../Attachements/Pasted%20image%2020260708061325.png)
#### Case 1: Normalized values

|Field|**Stored bits**|**Interpreted as**|
|---|---|---|
|Exponent|`e` — neither all 0s nor all 1s|`E = e − Bias`, where `Bias = 2^(k−1) − 1` (127 single / 1023 double). Gives `E` from −126 to +127 (single) or −1022 to +1023 (double)|
|Fraction|`f` — 23 or 52 raw bits|`M = 1.f` (the stored bits placed after an _implied_ leading 1 that is **not stored**)|

**Use case:** the "normal" everyday range of representable numbers, maximizing precision by not wasting a bit storing that leading 1.

#### Case 2: Denormalized values

|Field|**Stored bits**|**Interpreted as**|
|---|---|---|
|Exponent|`e = 00000000` (all zeros)|`E = 1 − Bias` (a fixed value — same as the smallest normalized exponent)|
|Fraction|`f` — raw bits|`M = 0.f` (leading bit is explicitly 0, **no** implied 1)|

**Use case:** represents values between the smallest normalized number and zero, filling the gap smoothly instead of jumping straight to zero — this is called "gradual underflow." The special case `f = 000...0` (all fraction bits zero too) gives exactly **0**, and since sign is separate, this format naturally produces both +0 and −0 (which compare equal, but are bit-distinguishable).

#### Case 3: Special values

|Field|**Stored bits**|**Interpreted as**|
|---|---|---|
|Exponent|`e = 11111111` (all ones)|—|
|Fraction|`f = 000...0` (all zeros)|**Infinity** (±∞, sign from `s`)|
|Fraction|`f ≠ 0` (anything nonzero)|**NaN** ("not a number")|

**Use cases:**

- **Infinity:** results of overflow (e.g. multiplying two very large numbers) or division by zero.
- **NaN:** results with no valid real or infinite value (e.g. `0/0`, `∞ − ∞`, `√(−1)`); also sometimes used as a sentinel for uninitialized data.

---

### Examples

We can see the fields where every case can be represented:
![](../../../Attachements/Pasted%20image%2020260708061835.png)

![](../../../Attachements/Pasted%20image%2020260708062906.png)

---

Some valuable examples:
![](../../../Attachements/Pasted%20image%2020260709092527.png)

---

Converting from integer into floating point form:

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


For example, we saw in Figure 2.15 that 12,345 has binary representation [11000000111001]. We create a normal-ized representation of this by shifting 13 positions to the right of a binary point, giving 12,345 = 1.10000001110012 × 2^13. To encode this in IEEE single-precision format, we construct the fraction field by dropping the leading 1 and adding 10 zeros to the end, giving binary representation [10000001110010000000000]. To construct the exponent field, we add bias 127 to 13, giving 140, which has binary representation [10001100]. We combine this with a sign bit of 0 to get the floating-point representation in binary of [01000110010000001110010000000000].

 we observe the following correlation in the bitlevel representations of the integer value 12345 (0x3039) and the single-precision floating-point value 12345.0 (0x4640E400):
![](../../../Attachements/Pasted%20image%2020260709094019.png)

