#ifndef UTILS_H_
#define UTILS_H_

#include "beer.h"


int get_str_len(const char *);
int str_equals(const char *, const char *);
int cmp_str(const char *a, const char *b);

void swap_int(int *a, int *b);
void swap_beer(beer_t **a, beer_t **b);


#endif
