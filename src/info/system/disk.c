#include <sys/types.h>
#include <sys/statvfs.h>
#include <malloc.h>
#include <stdio.h>
#include <assert.h>

#define RLEN 100

#define to_GiB(a) ((a)/(1024*1024*1024))
const char *disk(void)
{
	struct statvfs stat;
	char					*r;
	float					 total, used;

	assert(statvfs("/", &stat) == 0);

	total = to_GiB((float)stat.f_blocks * stat.f_frsize);
  used  = to_GiB((float)(stat.f_blocks - stat.f_bfree) * stat.f_frsize);

	r = malloc(RLEN);
	sprintf(r, "%.3f GiB / %.3f GiB (%.0f%%)", used, total, 100*used/total);

	return r;
}
