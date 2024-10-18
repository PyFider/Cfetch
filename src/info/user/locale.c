#include <langinfo.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

const char *locale(void) {return setlocale(LC_ALL,"");}
