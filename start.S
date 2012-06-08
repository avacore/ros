/******** Entry ********/
.global entry

ivt:
	b entry
	nop
	nop
	nop
	nop
	nop
	nop
	nop

entry:
	/* Set up */
	mov sp, #0x100000 /* Give C some stack space (at 1 MB) */

	/* Call kmain */
	b kmain
