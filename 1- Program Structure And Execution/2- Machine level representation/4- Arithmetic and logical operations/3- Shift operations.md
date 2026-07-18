![](../../../Attachements/Pasted%20image%2020260718083548.png)

Note: n principle, having a 1-byte shift amount would make it possible to encode shift amounts ranging up to 28 − 1 = 255. So a shift instruction operating on data values that are w bits long determines the shift amount from the low-order m bits of register %cl, where 2m = w.  The higher-order bits are ignored. So, for example, when register %cl has hexadecimal value 0xFF, then instruction salb would shift by 7, while salw would shift by 15, sall would shift by 31, and salq would shift by 63.

- **salb** (w=8): m = log₂(8) = 3 bits used → mask = 0x07. `0xFF & 0x07 = 0x07 = 7`
- **salw** (w=16): m = log₂(16) = 4 bits → mask = 0x0F. `0xFF & 0x0F = 0x0F = 15`
- **sall** (w=32): m = log₂(32) = 5 bits → mask = 0x1F. `0xFF & 0x1F = 0x1F = 31`
- **salq** (w=64): m = log₂(64) = 6 bits → mask = 0x3F. `0xFF & 0x3F = 0x3F = 63`

