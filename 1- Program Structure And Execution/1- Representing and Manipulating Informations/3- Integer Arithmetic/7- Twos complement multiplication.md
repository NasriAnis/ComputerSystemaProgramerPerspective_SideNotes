For $TMinw ≤ x, y ≤ TMaxw$ :
![](../../../Attachements/Pasted%20image%2020260629075019.png)

**Note** the bit level representation of two complement of unsigned multiplication is exactly the same at the w bit the full untruncated representation can differ.
![](../../../Attachements/Pasted%20image%2020260629075428.png)

Code:
```c
/* Determine whether arguments can be multiplied without overflow */
int tmult_ok(int x, int y) {
int p = x*y;
/* Either x is zero, or dividing p by x gives y */
return !x || p/x == y;
}
```

```c
/* Determine whether the arguments can be multiplied without overflow */
int tmult_ok(int x, int y) {
/* Compute product without overflow */
int64_t pll = (int64_t) x*y;
/* See if casting to int preserves value */
return pll == (int) pll;
}
```