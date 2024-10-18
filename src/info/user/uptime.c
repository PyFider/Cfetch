#include <stdio.h>
#include <malloc.h>

const char *format_time(int);
const char *uptime(void)
{
	double uptime;
	fscanf(popen("cat /proc/uptime", "r"), "%lf", &uptime);
	return format_time((int)uptime);
}

#define RLEN 300
#define syntax(t, s1, s2) ((t > 1) ? s1:s2)
const char* format_time(int sec)
{
    int h, m, s;
    char *r = malloc(RLEN);

    h =  sec / 3600;
    m = (sec % 3600) / 60;
    s =  sec % 60;

    if (h)
			sprintf(r, "%d %s, %d %s", h, syntax(h, "hours", "hour"), m, syntax(m, "mins", "min"));
		else if (m)
			sprintf(r, "%d %s", m, syntax(m, "mins", "min")); 
		else
			sprintf(r, "%d %s", s, syntax(s, "secs", "sec"));
		
		return r;
}
