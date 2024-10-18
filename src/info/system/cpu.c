#include <stdio.h>
#include <malloc.h>
#include <string.h>

#define RLEN 1024

const char *cpu(void)
{
	FILE *f;
	char *r;

	f = fopen("/proc/cpuinfo", "r");
	r = malloc(RLEN);
	for (;fgets(r, RLEN, f);)
		if (strstr(r, "model name"))
			break;
	
	fclose(f);

	r += strcspn(r, ":")+2;
	*(r+strcspn(r, "\n")) = 0;
	return r;
}
