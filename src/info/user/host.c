#include <sys/utsname.h>
#include <assert.h>

const char *hostname(void) 
{
	struct utsname info;
	assert(uname(&info) == 0);

	return info.nodename;
}
