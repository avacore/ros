/******** Entry ********/
.globl entry
entry:
	/* Set up */
	mov sp, #0x100000 /* Give C some stack space (at 1 MB) */

	/* Call kmain */
	b kmain
