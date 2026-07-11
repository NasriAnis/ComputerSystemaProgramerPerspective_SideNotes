The IEEE standard specifies a simple rule for arithmetic operations on floating point. that is rounding the result of operation on x and y (as real numbers).

Note : x +(f) y = round(x + y)

Arithmetic addition are commutative x +(f) y = y +(f) f, but not associative (3.14+1e10)-1e10=0 the 3.14 value is lost due to rounding but 3.14+(1e10- 1e10) evaluates to 3.14.

As with an abelian group, most values have inverses under floating-point addition, that is, x +f −x = 0. The exceptions are infinities (since +∞ − ∞ = NaN), and NaNs, since NaN +f x = NaN for any x.

On the other hand, floating-point addition satisfies the following monotonicity property: if a ≥ b, then x +f a ≥ x +f b for any values of a, b, and x other than NaN. This property of real (and integer) addition is not obeyed by unsigned or two’s- complement addition (since they wrap around).

![](../../../Attachements/Pasted%20image%2020260711110648.png)
