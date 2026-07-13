`ISA` : instruction set architecture define the instructions and their effects on the state of the processor state
`Virtual addresses` : the memory addresses used by a machine-level program providing a memory model that appears to be a very large byte array.

The machine code for x86-64 differs greatly from the original C code. Parts of the processor state are visible that normally are hidden from the C programmer:
![](../../../Attachements/Pasted%20image%2020260712094611.png)

in addition machine code views memory as a large byte addressable array,  Aggregate data types in C such as arrays and structures are represented in machine code as contiguous collections of bytes. Even for scalar data types, assembly code makes no distinctions between signed or unsigned integers, between different types of pointers, or even between pointers and integers.

The program memory contains the executable machine code for the program, some information required by the operating system, a run-time stack for managing procedure calls and returns, and blocks of memory allocated by the user (e.g., by using the malloc library function). As mentioned earlier, the program memory is addressed using virtual addresses. At any given time, only limited subranges of virtual addresses are considered valid. For example, x86-64 virtual addresses are represented by 64-bit words. In current implementations of these machines, the upper 16 bits must be set to zero, and so an address can potentially specify a byte over a range of 248, or 64 terabytes. More typical programs will only have access to a few megabytes, or perhaps several gigabytes. The operating system manages this virtual address space, translating virtual addresses into the physical addresses of values in the actual processor memory.

