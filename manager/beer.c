#include <stdlib.h>
#include "beer.h"
#include "utils.h"


beer_t *init_beer(char *name, double price, double alcohol_perc, double volume) {
	int i;
	beer_t *beer = malloc(sizeof(beer_t));
	
	/*
	for (i = 0; i < get_str_len(name); i++) {
		beer->name[i] = name[i];
	}
	beer->name[i + 1] = '\0';
	*/

	beer->price = price;
	beer->alcohol_perc = alcohol_perc;
	beer->volume = volume;

	return beer;
}


void free_beer(beer_t *beer) {
	free(beer);
}

