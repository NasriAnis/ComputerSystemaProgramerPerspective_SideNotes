In addition to the integer registers the CPU maintains a set of single-bit condition code registers, that can be tested to perform conditional branches:
![](../../../Attachements/Pasted%20image%2020260721100447.png)


All instructions alter these flags apart the `leaq`. For logical operations such as `xor` the carry and overflow flags are set to zero. 

For the shift operations, the carry flag is set to the last bit shifted out, while the overflow flag is set to zero

 the `inc` and `dec` instructions set the overflow and zero flags, but they leave the carry flag unchanged.

---

There exist also other instruction in addition to the ones in figure 3.10 that sets condition codes whiteout altering any other register
![](../../../Attachements/Pasted%20image%2020260721104226.png)

