# Official PSP kernel drivers header files

SCE devkit version 6.60 has a stub library `display_stub.a` available for users.
Along with stubs, this archive also has an object file `userinterrupt.o` which somehow has DWARF debug symbols from which I created the headers.

Obviously, the headers are missing lots of functions/structures declarations.
Gotta add those from uOFW.

## Ghidra database

You can import the DWARF symbols into a Ghidra project with [the types database](SCE_kernel_headers_660.gdt).  
It contains everything as extracted from the object file.
