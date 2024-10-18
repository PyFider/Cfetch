#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define RLEN 1024
const char *videocard(void) 
{
	FILE	*p;
	char	*r;

	p = popen("lspci | grep -i vga", "r");
	fgets((r = malloc(RLEN)), RLEN, p);
	pclose(p);

	/* REMOVE START */
	r += strcspn(r, ":")+1;
	r += strcspn(r, ":")+2;
	
	/* REMOVE END */
	*(r+strcspn(r, "(")) = '\0';

	return r;
}
