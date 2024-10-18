#include <sys/utsname.h>
#include <string.h>
#include <assert.h>
#include <malloc.h>

#define KERNELLEN 1024

const char *kernel(void) {
	struct utsname info;
	char *r;

	assert(uname(&info) == 0);
	
	r = malloc(KERNELLEN);
	strcat(r, info.sysname);
	strcat(r, "\t");
	strcat(r, info.release);

	return r;
} 
