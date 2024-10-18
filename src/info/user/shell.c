#include <stdlib.h>
#include <string.h>
#include <malloc.h>

#define RESLEN 100

const char *shell(void)
{
  char *r;

	r = malloc(RESLEN);
	r = getenv("SHELL");
	r += 5; /* SKIPPING /bin/ */
	*(r+strcspn(r, "\n")) = '\0';

  return r;
}

