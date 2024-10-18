#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define RESLEN 10

extern const char *distribution(void);
#define equal(s, s1) (strcspn(s, s1) == 0)
const char *packages(void) 
{
	const char *distro;
	char			 *r;

	distro = distribution();

	if (equal(distro, "Manjaro") || equal(distro, "Arch") || equal(distro, "Artix")) {
		fgets((r = malloc(RESLEN)), RESLEN, popen("pacman -Q | wc -l", "r"));
		*(r+strcspn(r, "\n")) = 0;
		return r;
	}

	return "Not supported distribution";
}
