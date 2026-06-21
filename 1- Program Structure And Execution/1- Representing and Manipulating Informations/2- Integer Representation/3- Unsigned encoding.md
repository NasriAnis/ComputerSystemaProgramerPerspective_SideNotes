From a bit vector we can make the operation `B2U` (binary to unsigned) using this formula : 
![Pasted image 20260618083557](../../../Attachements/Pasted%20image%2020260618083557.png)

for a vector : `x = [xw−1, xw−2, . . . , x0 ]:` (with `w` the position of the bit)

example: 
```
B2U 4 ([0001]) = 0 . 2^3 + 0 . 2^2 + 0 . 2^1 + 1 . 2^0 = 1
```

We can represent this calculation this way : (depending on the place of the digit and if his value is 1 we add the number he encodes).
![Pasted image 20260618084409](../../../Attachements/Pasted%20image%2020260618084409.png)

We can calculate also `UMax` of any bit vector represented using w bits :
![Pasted image 20260618084133|293](../../../Attachements/Pasted%20image%2020260618084133.png)

that is equal to 2^w -1.