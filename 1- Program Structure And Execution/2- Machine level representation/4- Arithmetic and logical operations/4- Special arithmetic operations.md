When multiplying two 64 bits value it yields a 128 bits one (16 bytes numbers), intel refers to those as `oct word`

![](../../../Attachements/Pasted%20image%2020260719220428.png)

these are one operand instruction that yield a 128 bits result. (i is twos complement)

for example this C code:
```
#include <inttypes.h>
typedef unsigned __int128 uint128_t;
	void store_uprod(uint128_t *dest, uint64_t x, uint64_t y) {
	*dest = x * (uint128_t) y;
}
```

that generates this instructions:
```
void store_uprod(uint128_t *dest, uint64_t x, uint64_t y)
dest in %rdi, x in %rsi, y in %rdx
store_uprod:
	 movq %rsi, %rax    Copy x to multiplicand
	 mulq %rdx          Multiply by y
	 movq %rax, (%rdi)  Store lower 8 bytes at dest
	 movq %rdx, 8(%rdi) Store upper 8 bytes at dest+8
	 ret
```

observe that storing the result involve two `movq` instructions, one for the low-order 8 bytes (line 4), and one for the high-order 8 bytes (line 5). Since the code is generated for a little-endian machine, the high-order bytes are stored at higher addresses, as indicated by the address specification 8(%rdi).

The signed division instruction idivl takes as its dividend the 128-bit quantity in registers %rdx (high-order 64 bits) and %rax (low-order 64 bits). The divisor is given as the instruction operand. The instruction stores the quotient in register %rax and the remainder in register %rdx.

Same for divide it exist only single operand divide instructions:

**`divl`** — 32-bit division

- Divides a 64-bit dividend (in `edx:eax`, with `edx` as the high 32 bits and `eax` as the low 32 bits) by a 32-bit divisor.
- Result: quotient in `eax`, remainder in `edx`.
- Example: `divl %ebx` computes `edx:eax / ebx`.

**`divq`** — 64-bit division

- Divides a 128-bit dividend (in `rdx:rax`, with `rdx` as the high 64 bits and `rax` as the low 64 bits) by a 64-bit divisor.
- Result: quotient in `rax`, remainder in `rdx`.
- Example: `divq %rbx` computes `rdx:rax / rbx`.