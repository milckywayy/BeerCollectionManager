#include "utils.h"


int get_str_len(char *str) {
	int len;

	while(*(str++) != '\0') {
		len++;
	}

	return len;
}

