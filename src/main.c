#include <stdio.h>

/* OS */
extern const char *kernel(void);
extern const char *distribution(void);
extern const char *architecture(void);

/* USER */
extern const char *username(void);
extern const char *hostname(void);
extern const char *domainname(void);
extern const char *uptime(void);
extern const char *shell(void);
extern const char *term(void);
extern const char *locale(void);
extern const char *ip(void);

/* SYSTEM */
extern const char *de(void);
extern const char *memory(void);
extern const char *disk(void);
extern const char *battery(void);
extern const char *packages(void);
extern const char *cpu(void);
extern const char *videocard(void);
extern const char *display(void);

#define print(name, res)	\
fputs(name, stdout);			\
fputs(res, stdout);				\
putchar('\n');						\

int main(void) {
	/* OS */
	fputs("OS\n", stdout);
	printf("Distribution:\t%s %s\n", distribution(), architecture());
	print("Kernel:\t\t",	kernel());
	/* END OS */

	putchar('\n');

	/* USER */
	fputs("User\n", stdout);
	print("Hostname:\t",	hostname());
	print("User:\t\t",		username());
	print("Domain:\t\t",	domainname());
	print("Uptime:\t\t",	uptime());
	print("Shell:\t\t",		shell());
	print("Terminal:\t",	term());
	print("Locale:\t\t",	locale());
	print("IP:\t\t",			ip());
	/* END USER */

	putchar('\n');

	/* SYSTEM */
	fputs("System\n", stdout);
	print("DE:\t\t",		  de());
	print("Memory:\t\t",  memory());
	print("Disk (/):\t",  disk());
	print("Battery:\t",	  battery());
	print("Packages:\t",  packages());
	print("CPU:\t\t",		  cpu());
	print("CPU1:\t\t",		videocard());
	print("Display:\t",	  display());
	/* END SYSTEM*/
  
	return 0;
}
