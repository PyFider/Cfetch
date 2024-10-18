#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define RLEN 512

const char *display(void)
{
	FILE *p;
	char *r;

	p = popen("xrandr", "r");
	r = malloc(RLEN);
	for (;fgets(r, RLEN, p);)
		if (strcspn(r, "*") != strlen(r))
			break;

	r += 3; /* SKIP SPACING */
	*(r+strcspn(r, " ")) = '\0'; /* REMOVING RIGHT INFO */

	return r;
}
