This `MOV` instruction class copy data from a source to a destination without any transformation ( The only exception is that when movl has a register as the destination, it will also set the high-order 4 bytes of the register to 0, This exception arises from the convention, adopted in x86-64, that any instruction that generates a 32-bit value for a register also sets the high-order portion of the register to 0):
![](../../../Attachements/Pasted%20image%2020260714180002.png)

x86-64 imposes the restriction that a move instruction cannot have both operands refer to memory locations. Copying a value from one memory location to another requires two instructions—the first to load the source value into a register, and the second to write this register value to the destination.

