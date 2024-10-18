#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define RESLEN 10

const char *battery(void)
{
	char *r;

	r = malloc(RESLEN);
	fgets(r, RESLEN, popen("cat /sys/class/power_supply/BAT*/capacity", "r"));
	*(r+strcspn(r, "\n")) = '%';

	return r;
}
