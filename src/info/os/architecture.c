#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARCHLEN 100
const char *architecture(void) 
{
	char *r;

	fgets((r = malloc(ARCHLEN)), ARCHLEN, popen("uname -m", "r"));
	*(r+strcspn(r, "\n")) = 0;
	
	return r;
}
