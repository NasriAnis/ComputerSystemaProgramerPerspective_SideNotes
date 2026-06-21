In C no standard specify negative numbers data encoding so they are always Twos complement encoded in every machine.

Generally most numbers are signed by default unless specified as unsigned using the `u` or `U` : `12345U` or `0x123u`

C allows conversion between types (type casting) explicitly or implicitly and these conversions follow the `T2U` and `U2T` functions we saw earlier. Similarly `printf` print numeric value depending on the directive given to it `%d`, `%u`, `%x` etc more on that in [here](2.1-%20Asides.md).

---

When doing operations such as (`<`, `>`)on signed and unsigned values C implicitly casts the signed argument to unsigned and performs the operation.
