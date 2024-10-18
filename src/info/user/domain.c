#include <sys/utsname.h>
#include <assert.h>

const char *domainname(void) 
{
	struct utsname info;
	assert(uname(&info) == 0);

	return info.__domainname;
}
