#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>

const char *distribution()
{
  FILE *file = fopen("/etc/os-release", "r");
	char *distro = malloc(256);

	assert(file);
  
	fgets(distro, 256, file);
  distro += strlen("NAME:\"");
  distro[strcspn(distro, "\"")] = 0; /* DELETE NOT NEED SYMS */		
		
	fclose(file);
	return distro;
}
