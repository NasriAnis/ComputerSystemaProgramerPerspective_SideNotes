Compilation steps:
1.  the C preprocessor expands the source code to include any files specified with #include commands and to expand any macros, specified with #define declarations.
2.  the compiler generates assembly-code versions of the source files
3. the assembler converts the assembly code into binary object-code files
4. the linker merges these two object-code files along with code implementing library functions (e.g., printf) and generates the final executable code file

Object code is one form of machine code—it contains binary representations of all of the instructions, but the addresses of global values are not yet filled in.