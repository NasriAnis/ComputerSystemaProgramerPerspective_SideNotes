Contrary to extension, truncating cut off bits from a value.This occur for example when casting an `int` (32bit) into a `short` (16bit).

this can alter the value of the data.

---

**Principle of truncation of a unsigned number :**

let x be a bit vector : $[xw−1, xw−2 , . . . , x0]$ and $x`$ the result of truncating x by k bits be : $[xk−1, xk−2 , . . . , x0]$ 

let $x = B2U w (x)$ and $x` = B2U k (x`)$ then $x` = x mod 2^k$.

---

**Principle of truncation of Twos complement number :**

this is a similar property than the one above expect that it then converts the most significant bit into a sign bit.

Then $x` = U2T k (x mod 2^k )$.

---

Summary:

The effect of truncation on unsigned numbers is : $B2U k ([xk−1 , xk−2, . . . , x0 ]) = B2U w ([xw−1, xw−2, . . . , x0 ]) mod 2^k$

and for twos complement : $B2T k ([xk−1, xk−2 , . . . , x0 ]) = U2T k (B2U w ([xw−1, xw−2, . . . , x0 ]) mod 2^k )$

