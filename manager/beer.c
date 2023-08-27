#include <stdlib.h>
#include <stdio.h>
#include "beer.h"
#include "utils.h"


beer_t *init_beer(char *name, double price, double alcohol_perc, int volume_ml) {
	int i = 0;
	int name_len = 0;
	beer_t *beer = malloc(sizeof(beer_t));

	name_len = get_str_len(name);	
	beer->name = malloc(sizeof(char) * (name_len + 1));

	if (beer == NULL || beer->name == NULL) {
		return NULL;
	}

	for (i = 0; i < name_len; i++) {
		beer->name[i] = name[i];
	}
	beer->name[i] = '\0';

	beer->price = price;
	beer->alcohol_perc = alcohol_perc;
	beer->volume_ml = volume_ml;

	return beer;
}

void print_beer(beer_t *beer) {
	printf("%s: price: %f, alc: %f, ml: %d\n", beer->name, beer->price, beer->alcohol_perc, beer->volume_ml);
}

void free_beer(beer_t *beer) {
	free(beer->name);
	free(beer);
}

int cmp_beer_name_asc(const void *a, const void *b) {
    	beer_t *beer_a = *(beer_t **)a;
    	beer_t *beer_b = *(beer_t **)b;

	return cmp_str(beer_a->name, beer_b->name);
}

int cmp_beer_name_desc(const void *a, const void *b) {
    	return -cmp_beer_name_asc(a, b);
}

int cmp_beer_alc_asc(const void *a, const void *b) {
    	beer_t *beer_a = *(beer_t **)a;
    	beer_t *beer_b = *(beer_t **)b;
    	
	if (beer_a->alcohol_perc < beer_b->alcohol_perc) return -1;
    	if (beer_a->alcohol_perc > beer_b->alcohol_perc) return 1;
    	
	return 0;
}

int cmp_beer_alc_desc(const void *a, const void *b) {
    	return -cmp_beer_alc_asc(a, b);
}

int cmp_beer_price_asc(const void *a, const void *b) {
    	beer_t *beer_a = *(beer_t **)a;
    	beer_t *beer_b = *(beer_t **)b;
    	
	if (beer_a->price < beer_b->price) return -1;
    	if (beer_a->price > beer_b->price) return 1;
    	
	return 0;
}

int cmp_beer_price_desc(const void *a, const void *b) {
	return -cmp_beer_price_asc(a, b);
}

int cmp_beer_volume_asc(const void *a, const void *b) {
	beer_t *beer_a = *(beer_t **)a;
    	beer_t *beer_b = *(beer_t **)b;
    	
	return beer_a->volume_ml - beer_b->volume_ml;
}

int cmp_beer_volume_desc(const void *a, const void *b) {
    	return -cmp_beer_volume_asc(a, b);
}

