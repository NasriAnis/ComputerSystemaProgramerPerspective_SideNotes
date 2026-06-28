Looking at this code :
```c
int tadd_ok(int x, int y) {
	int sum = x+y;
	return (sum-x == y) && (sum-y == x);
}
```

we tend to agree that this is correct but in reality when adding two number than subtracting the sum with one of them we always get the second no matter what.

lets take :
- `x = 5` (Binary: `0101`)
- `y = 4` (Binary: `0100`)

Mathematically, $5 + 4 = 9$. But $9$ cannot fit in a 4-bit signed integer.

we first compute sum = x + y:
```
   0101  (x = 5)
+  0100  (y = 4)
  ------
   1001  (sum = -7 in Two's Complement)
```

then evaluate sum - x == y :
```
   1001  (sum = -7)
+  1011  (-x  = -5)
  ------
  10100 => truncation => 100 = y
```

which leave us exactly with y.

Modern CPUs use **Two's Complement** representation for signed integers. In Two's Complement, signed integer arithmetic is mathematically equivalent to modular arithmetic (specifically modulo $2^w$, where $w$ is the bit width, like 32).

Because it is modular arithmetic, addition forms an algebraic group. This means that properties like associativity and invertibility **always hold true**, even if the number overflows and wraps around.

Machine addition modulo $2^w$ (where $w$ is the bit width) form an **Abelian group**.

---

Correct `tadd_ok` function can be found in this file [tadd_ok](../../../C/tadd_ok.c), if we wanted to make a `tsub_ok` some people would do it like this :
```c
int tsub_ok(int x, int y) {
	return tadd_ok(x, -y);
}
```

but this wouldn't work for `y = Tmin`
```
TMin = -2,147,483,648
-TMin = +2,147,483,648  →  doesn't fit in int32  →  wraps back to TMin
```

So `tsub_ok(x, TMin)` ends up calling `tadd_ok(x, TMin)` — checking `x + TMin` instead of `x - TMin`. These are completely different operations.