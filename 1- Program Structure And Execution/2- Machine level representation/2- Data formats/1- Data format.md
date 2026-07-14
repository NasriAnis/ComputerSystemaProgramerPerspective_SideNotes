Quantities and their representation in x86_64:
![](../../../Attachements/Pasted%20image%2020260714171912.png)

 The assembly code uses the suffix ‘l’ to denote a 4-byte integer as well as an 8-byte double-precision floating-point number. This causes no ambigu- ity, since floating-point code involves an entirely different set of instructions and registers.

---

- Word: 16 bits
- Double Word: 32 bits
- quad words: 64 bits

Note: 1 byte is 8 bits

---

Microprocessors in the x86 family historically implemented all floating-point operations with a special 80-bit (10- byte) floating-point format. This format can be specified in C programs using the declaration long double. We recommend against using this format, however.

