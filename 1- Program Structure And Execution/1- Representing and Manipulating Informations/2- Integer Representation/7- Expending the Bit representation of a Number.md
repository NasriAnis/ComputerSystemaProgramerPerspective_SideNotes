One common operation is to convert an integer into different word sizes, converting from bigger to smaller word size is not possible. However converting from smaller to bigger is doable.

To convert a unsigned number into a larger data type we can add leading zeros (zero extension).

To convert a two's complement number into a larger data type we have to perform a sign extension, this by adding copies of the most significant bit (sign bit) to the representation : $x = [xw−1, xw−2, . . . , x0 ]$ of width w and $x' = [xw−1, . . . , xw−1, xw−1, xw−2 , . . . , x0]$  of width w' where w'>w.

Example code (run on a big-endian 32 bit machine) :
```c
short sx = -12345; /* -12345 */
unsigned short usx = sx; /* 53191 */
int x = sx; /* -12345 */
unsigned ux = usx; /* 53191 */

printf("sx = %d:\t", sx);
show_bytes((byte_pointer) &sx, sizeof(short));
// sx = -12345: cf c7

printf("usx = %u:\t", usx);
show_bytes((byte_pointer) &usx, sizeof(unsigned short));
// usx = 53191: cf c7

printf("x = %d:\t", x);
show_bytes((byte_pointer) &x, sizeof(int));
// x = -12345: ff ff cf c7

printf("ux = %u:\t", ux);
show_bytes((byte_pointer) &ux, sizeof(unsigned));
// ux = 53191: 00 00 cf c7
```

Example graph of sign extensions:
![](../../../Attachements/Pasted%20image%2020260621120824.png)

---

Looking at this code :
```c
short sx = -12345;
unsigned uy = sx;

printf("uy = %u:\t", uy);
show_bytes((byte_pointer) &uy, sizeof(unsigned));

// uy = 4294954951: ff ff cf c7
```

from there we deduce that the program first changes the size and then the type (C standards).