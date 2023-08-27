#include "utils.h"


int get_str_len(char *str) {
	int len = 0;

	while (*(str++) != '\0') {
		len++;
	}

	return len;
}


int str_equals(char *a, char *b) {
	while (*a != '\0' && *b != '\0') {
		if (*a != *b) {
			return 1;
		}
		
		a++;
		b++;
	}

	if (*a != *b) {
		return 1;
	}

	return 0;
}

