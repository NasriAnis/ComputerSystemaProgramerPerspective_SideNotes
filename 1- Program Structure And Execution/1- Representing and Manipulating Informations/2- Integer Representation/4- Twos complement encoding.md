From a bit vector we can also Two's complement encode it, using the `B2T` function :
![Pasted image 20260618084641](../../../Attachements/Pasted%20image%2020260618084641.png)

Here the most significant bit `X w-1` is called the sign bit and its weight is of the part we added at the left.

and here is the figure it represent :
![Pasted image 20260618084856](../../../Attachements/Pasted%20image%2020260618084856.png)

example:
```
B2T 4([1011]) = −1 . 23 + 0 . 22 + 1 . 21 + 1 . 20 =  −5
```

`TMin` is given by the value of `-2^(w-1)` the most significant bit set to 1 and all other bits to zero: 1000...

in the other hand `Tmax` :
![Pasted image 20260618085211](../../../Attachements/Pasted%20image%2020260618085211.png)

that is : `2^(w-1) -1`

### Note
As we saw the signed part range is `+1` time bigger than the unsigned part from that we have the equation :  `|TMin| = |TMax| + 1` (this is due to the sign bit being used in the `TMin` and always set to zero in `Tmax`) and also ` UMax = 2TMax + 1`

![Pasted image 20260618090055](../../../Attachements/Pasted%20image%2020260618090055.png)

There's libraries that define and make data types the same across devices possible like the `limits.h` (defines constants `INT_MAX`, `INT_MIN`, and `UINT_MAX` describing the ranges of signed and unsigned integers. For a two’s-complement machine in which data type int has w bits, these constants correspond to the values of `TMaxw` , `TMin` w , and `UMaxw`), `stdint.h` etc more on that in [here](2.1-%20Asides.md).

Example of two's complement representation :
![Pasted image 20260618091551](../../../Attachements/Pasted%20image%2020260618091551.png)

