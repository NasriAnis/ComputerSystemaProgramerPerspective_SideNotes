As its name says this instruction loads the address (not the content) of a register to generate pointers for latter memory use.

In addition, it can be used to compactly describe common arithmetic operations. For example, if register `%rdx` contains value x, then the instruction `leaq 7(%rdx,%rdx,4)`, `%rax` will set register `%rax` to `5x + 7`. Compilers often find clever uses of `leaq` that have nothing to do with effective address computations. The destination operand must be a register.

![](../../../Attachements/Pasted%20image%2020260716195111.png)
