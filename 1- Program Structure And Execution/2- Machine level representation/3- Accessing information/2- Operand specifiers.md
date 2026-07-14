![](../../../Attachements/Pasted%20image%2020260714174048.png)

Every instructions have operands specifying the source values to use perform operation on and the destination to store the results. `x86_64` support different operand forms as seen in the table above.

Sources can be read as constants, or from registers and memory the result this can be stored in registers or memory.

Constants: In ATT-format assembly code, these are written with a ‘$’ followed by an integer Different instructions allow different ranges of immediate values; the assembler will automatically select the most compact way of encoding a value.

registers: the contents of a register, one of the sixteen 8-, 4-, 2-, or 1-byte low-order portions of the registers for operands having 64, 32, 16, or 8 bits, respectively. we use the notation ra to denote an arbitrary register a and indicate its value with the reference R[ra ], viewing the set of registers as an array R indexed by register identifiers.

Memory: which we access some memory location according to a computed address, often called the effective address. Since we view the memory as a large array of bytes, we use the notation Mb[Addr] to denote a reference to the b-byte value stored in memory starting at address Addr.

The most general form is shown at the bottom of the table with syntax Imm(rb ,ri ,s). Such a reference has four components: an immediate offset Imm, a base register rb, an index register ri , and a scale factor s, where s must be 1, 2, 4, or 8. Both the base and index must be 64-bit registers. The effective address is computed as Imm + R[rb ] + R[ri ] . s. This general form is often seen when referencing elements of arrays. 

