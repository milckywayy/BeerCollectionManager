#include <stdio.h>
#include "utils.h"


int get_str_len(const char *str) {
	int len = 0;

	while (*(str++) != '\0') {
		len++;
	}

	return len;
}

int str_equals(const char *a, const char *b) {
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

int cmp_str(const char *a, const char *b) {
	while (*a == *b && *a != '\0') {
		a++;
		b++;
	}
	
	if (*a == '\0' && *b == '\0') {
        	return 0;
    	}
	else if (*a == '\0') {
        	return -1;
    	}
	else if (*b == '\0') {
        	return 1;
	}

	return *a - *b;
}


void swap_int(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void swap_beer(beer_t **a, beer_t **b) {
	beer_t *tmp = *a;
	*a = *b;
	*b = tmp;
}

