#include <stdlib.h>
#include <stdio.h>
#include "beer.h"
#include "utils.h"


beer_t *init_beer(char *name, double price, double alcohol_perc, double volume_ml) {
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


void free_beer(beer_t *beer) {
	free(beer->name);
	free(beer);
}

