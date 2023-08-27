#ifndef COLLECTION_STATS_H_
#define COLLECTION_STATS_H_

#include <stdlib.h>
#include "collection.h"
#include "beer.h"


char *get_most_common_beer(collection_t *coll) {
	int i, beer_index, count;

	if (coll == NULL) {
		return NULL; // Collection doesn't exist
	}

	if (coll->n < 1) {
		return NULL; // Collection is empty
	}

	beer_index = 0;
	count = coll->amount[beer_index];
	for (i = 1; i < coll->n; i++) {
		if (coll->amount[i] > count) {
			beer_index = i;
			count = coll->amount[i];
		}
	}

	return coll->beers[beer_index]->name;
}

char *get_strongest_beer(collection_t *coll) {
	int i, beer_index, alcohol_perc;

	if (coll == NULL) {
		return NULL; // Collection doesn't exist
	}

	if (coll->n < 1) {
		return NULL; // Collection is empty
	}

	beer_index = 0;
	alcohol_perc = coll->beers[beer_index]->alcohol_perc;
	for (i = 1; i < coll->n; i++) {
		if (coll->beers[i]->alcohol_perc > alcohol_perc) {
			beer_index = i;
			alcohol_perc = coll->beers[i]->alcohol_perc;
		}
	}

	return coll->beers[beer_index]->name;
}

char *get_most_expensive_beer(collection_t *coll) {
	int i, beer_index, price;

	if (coll == NULL) {
		return NULL; // Collection doesn't exist
	}

	if (coll->n < 1) {
		return NULL; // Collection is empty
	}

	beer_index = 0;
	price = coll->beers[beer_index]->price;
	for (i = 1; i < coll->n; i++) {
		if (coll->beers[i]->price > price) {
			beer_index = i;
			price = coll->beers[i]->price;
		}
	}

	return coll->beers[beer_index]->name;
}

char *get_cheapest_beer(collection_t *coll) {
	int i, beer_index, price;

	if (coll == NULL) {
		return NULL; // Collection doesn't exist
	}

	if (coll->n < 1) {
		return NULL; // Collection is empty
	}

	beer_index = 0;
	price = coll->beers[beer_index]->price;
	for (i = 1; i < coll->n; i++) {
		if (coll->beers[i]->price < price) {
			beer_index = i;
			price = coll->beers[i]->price;
		}
	}

	return coll->beers[beer_index]->name;
}

int get_all_beer_count(collection_t *coll) {
	int i;
	int count = 0;

	for (i = 0; i < coll->n; i++) {
		count += coll->amount[i];
	}

	return count;
}

int get_all_beer_volume_ml(collection_t *coll) {
	int i;
	int volume_ml = 0;

	for (i = 0; i < coll->n; i++) {
		volume_ml += coll->beers[i]->volume_ml;
	}

	return volume_ml;
}

double get_all_beer_price(collection_t *coll) {
	int i;
	double price = 0; 

	for (i = 0; i < coll->n; i++) {
		price += coll->beers[i]->price;
	}

	return price;
}

double get_all_beer_alcohol_ml(collection_t *coll) {
	int i;
	double alcohol_ml = 0.0;

	for (i = 0; i < coll->n; i++) {
		alcohol_ml += coll->beers[i]->volume_ml * (coll->beers[i]->alcohol_perc / 100);
	}

	return alcohol_ml;
}


#endif
