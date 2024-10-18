#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define USERNAMELEN 100

const char *username(void) 
{
	char *r;

	fgets((r = malloc(USERNAMELEN)), USERNAMELEN, popen("whoami", "r"));
	*(r+strcspn(r, "\n")) = 0;

	return r;
}
