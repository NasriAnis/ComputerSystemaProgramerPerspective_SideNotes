This `MOV` instruction class copy data from a source to a destination without any transformation ( The only exception is that when movl has a register as the destination, it will also set the high-order 4 bytes of the register to 0, This exception arises from the convention, adopted in x86-64, that any instruction that generates a 32-bit value for a register also sets the high-order portion of the register to 0):
![](../../../Attachements/Pasted%20image%2020260714180002.png)

x86-64 imposes the restriction that a move instruction cannot have both operands refer to memory locations. Copying a value from one memory location to another requires two instructions—the first to load the source value into a register, and the second to write this register value to the destination.

---

The regular movq instruction can only have immediate source operands that can be represented as 32-bit two’s-complement numbers. This value is then sign extended to produce the 64-bit value for the destination. The movabsq in- struction can have an arbitrary 64-bit immediate value as its source operand and can only have a register as a destination.

---

![](../../../Attachements/Pasted%20image%2020260715080013.png)
![](../../../Attachements/Pasted%20image%2020260715080208.png)

there are other `mov` instructions that perform computation on the operand before saving it for example `movz`  fill out the remaining bytes of the destination with zeros, while those in the `movs` class fill them out by sign extension, replicating copies of the most significant bit of the source operand.

each instruction name has a size designator the first specifying the source size, and the second specifying the destination size. 

Note the absence of an explicit instruction to zero-extend a 4-byte source value to an 8-byte destination in Figure 3.5. Such an instruction would logically be named `movzlq`, but this instruction does not exist. Instead, this type of data movement can be implemented using a `movl` instruction having a register as the destination. This technique takes advantage of the property that an instruction generating a 4-byte value with a register as the destination will fill the upper 4 bytes with zeros.

we also have the `cltq` instruction that always uses register %eax as its source and %rax as the destination for the sign-extended result.