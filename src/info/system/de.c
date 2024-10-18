#include <stdlib.h>

const char *de(void) {
	if (!getenv("XDG_CURRENT_DESKTOP"))
    return "Unknown DE";

  return getenv("XDG_CURRENT_DESKTOP");
}
