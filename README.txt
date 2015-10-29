Ex 3
Q1
ljmp    $PROT_MODE_CSEG, $protcseg, this cause the CPU switch to 32 bit mode.
And after the following .code32, the CPU starts executing 32 bit code.

Q2
The last instruction of boot:
((void (*)(void)) (ELFHDR->e_entry))();
7d63:	ff 15 18 00 01 00    	call   *0x10018

The first instruction of kernel:
0x10000c:	movw   $0x1234,0x472

Q3
At address 0x0010000c

Q4
ph = (struct Proghdr *) ((uint8_t *) ELFHDR + ELFHDR->e_phoff);
	eph = ph + ELFHDR->e_phnum;
	for (; ph < eph; ph++)
		// p_pa is the load address of this segment (as well
		// as the physical address)
		readseg(ph->p_pa, ph->p_memsz, ph->p_offset);

This code loads all segments of kernel into memory.

Ex 8
Q1
console.c exports cputchar(ch) function to printf.c to handle lower level displaying stuff.
printf.c use this function to print formatted text.

Q2
This code is used to display a new line and push the text screen up for one line.

Q3
	a) fmt points to the address of "x %d, y %x, z %d\n", ap points to the address of x in stack.
	b) 	vcprintf (fmt=0xf0101cde "x %d, y %x, z %d\n", ap=0xf010ff74 "\001") at kern/printf.c:19
		cons_putc (c=120) at ./inc/x86.h:48
		cons_putc (c=32) at ./inc/x86.h:48
		Hardware watchpoint 4: ap
		Old value = (va_list) 0xf010ff74 "\001"
		New value = (va_list) 0xf010ff78 "\003"
		0xf0101045 in vprintfmt (putch=0xf0100908 <putch>, putdat=0xf010ff3c, fmt=0xf0101cde "x %d, y %x, z %d\n", 
			ap=0xf010ff78 "\003") at lib/printfmt.c:75
		cons_putc (c=49) at ./inc/x86.h:48
		cons_putc (c=44) at ./inc/x86.h:48
		cons_putc (c=32) at ./inc/x86.h:48
		cons_putc (c=121) at ./inc/x86.h:48
		cons_putc (c=32) at ./inc/x86.h:48
		Hardware watchpoint 4: ap
		Old value = (va_list) 0xf010ff78 "\003"
		New value = (va_list) 0xf010ff7c "\004"
		0xf0100d5c in getuint (ap=0xf010ff2c, lflag=-267321480) at lib/printfmt.c:62
		cons_putc (c=51) at ./inc/x86.h:48
		cons_putc (c=44) at ./inc/x86.h:48
		cons_putc (c=32) at ./inc/x86.h:48
		cons_putc (c=122) at ./inc/x86.h:48
		cons_putc (c=32) at ./inc/x86.h:48
		Hardware watchpoint 4: ap
		Old value = (va_list) 0xf010ff7c "\004"
		New value = (va_list) 0xf010ff80 "\334\031\020\360\244\377\020\360\270\377", <incomplete sequence \360>
		0xf0101045 in vprintfmt (putch=0xf0100908 <putch>, putdat=0xf010ff3c, fmt=0xf0101cde "x %d, y %x, z %d\n", 
			ap=0xf010ff80 "\334\031\020\360\244\377\020\360\270\377", <incomplete sequence \360>) at lib/printfmt.c:75
		cons_putc (c=52) at ./inc/x86.h:48
		cons_putc (c=10) at ./inc/x86.h:48

Q4
It prints He110 World.
It's because on the address of i stores 0x72 0x6c 0x64 on the stack, which is equivalent to "rld". And 57616 is e110 in hex mode.
For big endian, i should be 0x726c664. 57616 doesn't need to be changed.

Q5
x=3 y=-267380260
Because the ap moves to the address above 3 and read it out.

Q6
Push an integer after the last argument to indicate the number of arguments.