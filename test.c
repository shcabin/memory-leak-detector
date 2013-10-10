#include <stdio.h>
#include <malloc.h>
#include <string.h>

#include "leak_detector.h"

void main()
{
	void *ptr;
	ptr=malloc(256);
	ptr=malloc(128);
	strdup("0123456789abcdef");
	calloc(1,32);

	free(ptr);
	report_mem_leak();
}

/*output maybe like this
user@linux-z1mu:~/gcc/leak> cat leak_info.txt 
Memory Leak Summary
-----------------------------------
leak total:304,max used size:432,once max:256

address : 0x 804c008    size    : 256 bytes
    00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00    ................
    00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00    ................
    00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00    ................
    00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00    ................
line:9 file    : test.c
-----------------------------------
address : 0x 804c3c8    size    : 16 bytes
    30 31 32 33 34 35 36 37 38 39 61 62 63 64 65 66    0123456789abcdef
line:11 file    : test.c
-----------------------------------
address : 0x 804c4f8    size    : 32 bytes
    00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00    ................
    00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00    ................
line:12 file    : test.c
--------------------------------

*/


