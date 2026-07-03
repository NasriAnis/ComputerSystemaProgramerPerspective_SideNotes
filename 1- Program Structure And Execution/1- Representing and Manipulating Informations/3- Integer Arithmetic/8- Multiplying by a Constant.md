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

---

**How does the compiler choose between Form A and Form B:**
Assuming that addition and subtraction have the same performance, the rule is to choose form A when n = m, either form when n = m + 1, and form B when n > m + 1.

The justification for this rule is as follows:

Assume first that m > 0. When n = m, form A requires only a single shift, while form B requires two shifts and a subtraction. Example bit representations : 1000, 100 etc

When n = m + 1, both forms require two shifts and either an addition or a subtraction. Example bit representations : 1100, 11000 etc

When n > m + 1, form B requires only two shifts and one subtraction, while form A requires n − m + 1 > 2 shifts and n − m > 1 additions. 

For the case of m = 0, we get one fewer shift for both forms A and B, and so the same rules apply for choosing between the two.

---

Some examples:
#### Example 1:
Let's decode `11001100`:

```
bit:  7 6 5 4 3 2 1 0
      1 1 0 0 1 1 0 0
```

Value = 128 + 64 + 8 + 4 = **204**

**Step 1: Identify each run**

- Run 1: bits 7, 6 → `n = 7, m = 6`
- Run 2: bits 3, 2 → `n = 3, m = 2`

(The zeros at bits 5,4 and bits 1,0 just separate/terminate runs — they don't get their own term.)

**Step 2: Apply Form B to each run separately**

- Run 1: `(x<<8) - (x<<6)`
- Run 2: `(x<<4) - (x<<2)`

**Step 3: Add the runs together**

```
x*204 = (x<<8) - (x<<6) + (x<<4) - (x<<2)
```

**Step 4: Verify**

- `x<<8` = 256x
- `x<<6` = 64x
- `x<<4` = 16x
- `x<<2` = 4x
- `256x - 64x + 16x - 4x = 192x + 12x = 204x` ✓

**Step 5: Cost**

- Shifts: 4
- Add/Subs: 3 (three operations connecting four terms)

#### Example 2:
Let's work through 28 step by step.

**Step 1: Binary representation of 28**

```
bit:  5 4 3 2 1 0
      0 1 1 1 0 0
```

28 = 16 + 8 + 4 = `11100`

**Step 2: Find the run of 1s**

There's one run of consecutive 1-bits at positions 4, 3, 2.

- Top of run → `n = 4`
- Bottom of run → `m = 2`

**Step 3: Apply Form A (naive way — one shift+add per bit)**

```
(x<<4) + (x<<3) + (x<<2)
```

That's **3 shifts and 2 adds** — not optimal.

**Step 4: Apply Form B (the trick)**

Using the identity: a run of ones from `n` down to `m` equals `2^(n+1) - 2^m`, so:

```
(x<<(n+1)) - (x<<m)
= (x<<5) - (x<<2)
```

**Step 5: Verify**

- `x<<5` = `x * 32`
- `x<<2` = `x * 4`
- `32x - 4x = 28x` ✓

**Step 6: Count the cost**

- Shifts: 2 (one for `x<<5`, one for `x<<2`)
- Add/Subs: 1 (just the subtraction)