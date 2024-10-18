#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define RESLEN  250
#define LINELEN 200
#define MILLION 1000000

const char *memory(void)
{
	/* INIT */
	FILE *p;
	char *r, ln[LINELEN];
	double m_used, m_all;
	size_t i;

	/* GET ALL INFO */
	p = popen("vmstat -s", "r");

	/* MEMORY TOTAL */
	fgets(ln, LINELEN, p);
	m_all = atof(ln)/MILLION;

	/* MEMORY USED */
	fgets(ln, LINELEN, p);
	m_used = atof(ln)/MILLION;

	/* GET RESULT */
	r = malloc(RESLEN);
	sprintf(r, "%.3f GiB / %.3f GiB (%.0f%%)", m_used, m_all, 100*m_used/m_all);

	/* END */
	pclose(p);
	return r;
}
